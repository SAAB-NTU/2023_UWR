#!/usr/bin/python3

import rospy
from sensor_msgs.msg import CompressedImage
from geometry_msgs.msg import Pose
import math
from cv_bridge import CvBridge
import cv2
from sklearn.cluster import DBSCAN
import numpy as np

def dbscan_callback(scan):

    bridge = CvBridge()

    img = bridge.compressed_imgmsg_to_cv2(scan, desired_encoding='passthrough')

    img=cv2.cvtColor(img,cv2.COLOR_BGR2GRAY)

    _,th=cv2.threshold(img,0,255,cv2.THRESH_BINARY)

    coordinates = np.transpose(np.nonzero((th)))

 
    # Perform K-means clustering on the pixel positions

    #num_clusters = 5 # Number of cluster

    '''
    kmeans = KMeans(n_clusters=num_clusters, random_state=0)

    kmeans.fit(coordinates)

    # Get the cluster labels assigned to each pixel position

    labels = kmeans.labels_

    '''

    # Perform DBSCAN clustering on the pixel positions

    eps = 5  # Maximum distance between two points to be considered neighbors
    min_samples = 20  # Minimum number of points required to form a dense region

 

    dbscan = DBSCAN(eps=eps, min_samples=min_samples)

 

    dbscan.fit(coordinates)

    # Get the cluster labels assigned to each pixel position
    labels = dbscan.labels_

    # Assign different colors to each cluster
    num_clusters = len(np.unique(labels))  
    # Create a blank colored image
    colored_image = np.zeros_like(img, dtype=np.uint8)
    colored_image=cv2.cvtColor(colored_image,cv2.COLOR_GRAY2BGR)
    # Assign different colors to each cluster
    vars=[]
    centres=[]
    for label in range(num_clusters):

        cluster_pixels = coordinates[labels == label]

        if(len(cluster_pixels)>1):

 

            #print(len(cluster_pixels))

 

            process=np.asarray(cluster_pixels)

 

            vars.append(np.var(process))

 

            centres.append((np.array(np.mean(process[:,1]),np.uint),np.array(np.mean(process[:,0]),np.uint)))

 

            color = np.array(np.random.randint(0, 256, size=3).tolist())  # Generate a random color for each cluster

 

            for pixel in cluster_pixels:

 

                colored_image[pixel[0]][pixel[1]] = color

 

 

    #cv2.circle(colored_image,(int(centres[vars.index(min(vars))][0]),int(centres[vars.index(min(vars))][1])), int(min(vars))//10,(255,255,255), -1)

 

    #plt.figure(figsize=(15,15))

 

    #plt.imshow(colored_image)

 

    dbscan_2=cv2.cvtColor(colored_image,cv2.COLOR_BGR2GRAY)

 

    cv2.imwrite("/home/saab/Desktop/img_pose.png",dbscan_2)

 

    robot_pose=Pose()

 

    robot_pose.position.x=centres[vars.index(min(vars))][0]

    robot_pose.position.y=centres[vars.index(min(vars))][1]

 

    robot_pose.position.z=0

    robot_pose.orientation.x=0

    robot_pose.orientation.y=0

    robot_pose.orientation.z=0

    robot_pose.orientation.w=1

 

    pub.publish(robot_pose)

 

if __name__ == '__main__':

    rospy.init_node('dbscan_ptn_node')

    pub = rospy.Publisher('/dbscan_ptn_tf', Pose, queue_size=10)

    rospy.Subscriber('/marus_boat/sonar/compressed', CompressedImage, dbscan_callback)

    rospy.spin()
