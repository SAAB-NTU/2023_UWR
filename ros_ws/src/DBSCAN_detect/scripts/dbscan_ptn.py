#!/usr/bin/python3

import rospy
from sensor_msgs.msg import CompressedImage
from geometry_msgs.msg import PoseWithCovarianceStamped
from nav_msgs.msg import OccupancyGrid
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
    vars1=[]
    vars2=[]
    centres=[]
    for label in range(num_clusters):

        cluster_pixels = coordinates[labels == label]

        if(len(cluster_pixels)>1):


            process=np.asarray(cluster_pixels)

            vars1.append(np.var(process[:,0]))
            vars2.append(np.var(process[:,1]))

            centres.append((np.array(np.mean(process[:,1]),np.uint),np.array(np.mean(process[:,0]),np.uint)))

            color = np.array(np.random.randint(0, 256, size=3).tolist())  # Generate a random color for each cluster

            for pixel in cluster_pixels:

                colored_image[pixel[0]][pixel[1]] = color

 

 

    #cv2.circle(colored_image,(int(centres[vars.index(min(vars))][0]),int(centres[vars.index(min(vars))][1])), int(min(vars))//10,(255,255,255), -1)

    #plt.figure(figsize=(15,15))

    #plt.imshow(colored_image)

    dbscan_2=cv2.cvtColor(colored_image,cv2.COLOR_BGR2GRAY)

    cv2.imwrite("/home/saab/Desktop/img_pose.png",dbscan_2)

    robot_pose=PoseWithCovarianceStamped()

    robot_pose.pose.pose.position.x=centres[vars.index(min(vars1))][0]

    robot_pose.pose.pose.position.y=centres[vars.index(min(vars2))][1]

    

    robot_pose.pose.pose.position.z=0

    robot_pose.pose.pose.orientation.x=0

    robot_pose.pose.pose.orientation.y=0

    robot_pose.pose.pose.orientation.z=0

    robot_pose.pose.pose.orientation.w=1

        # Create a 6x6 covariance matrix with zeros
    covariance_matrix = np.zeros((6, 6))

    # Populate the (0, 0) and (1, 1) elements with x and y covariances
    covariance_matrix[0, 0] = min(vars1)
    covariance_matrix[1, 1] = min(vars2)

    robot_pose.pose.covariance = covariance_matrix.flatten()

    prob_map=th*(100/255)
    pub_map.publish(prob_map.flatten())

    pub_ptn.publish(robot_pose)

 

if __name__ == '__main__':

    rospy.init_node('dbscan_ptn_node')

    pub_ptn = rospy.Publisher('/dbscan_ptn_tf', PoseWithCovarianceStamped, queue_size=1)
    pub_map = rospy.Publisher('/map_fls', OccupancyGrid, queue_size=10)

    rospy.Subscriber('/marus_boat/sonar/compressed', CompressedImage, dbscan_callback)

    rospy.spin()
