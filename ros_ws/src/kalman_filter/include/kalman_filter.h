#ifndef KALMAN_FILTER
#define KALMAN_FILTER

#include <eigen3/Eigen/Dense>
#include <iostream>

class KalmanFilter
{
    public:
        KalmanFilter();
        Eigen::Vector2f prediction(const float& u, const float& dt);
        Eigen::Vector2f update(const Eigen::Vector2f& z);
        Eigen::Vector2f residual(const Eigen::Vector2f& z);
        Eigen::Matrix2f Q,R;
    protected:
        Eigen::Matrix2f F,P,H;
        Eigen::Vector2f x,B;
       
};

class KalmanFilter_6dof
{
    public:
        KalmanFilter_6dof();
        Eigen::Matrix<double,6,1> prediction(const Eigen::Matrix<double,3,1>& u, const float& dt);
        Eigen::Matrix<double,6,1> update(const Eigen::Matrix<double,6,1>& z);
        Eigen::Matrix<double,6,1> residual(const Eigen::Matrix<double,6,1>& z);
        Eigen::Matrix<double, 6, 6>  Q,R;
    protected:
        Eigen::Matrix<double, 6, 6> F,P,H;
        Eigen::Matrix<double, 6, 1> x;
        Eigen::Matrix<double,6,3> B;
       
};



#endif
