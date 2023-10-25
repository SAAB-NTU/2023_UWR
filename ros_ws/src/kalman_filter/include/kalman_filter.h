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
        Eigen::VectorXf prediction(const Eigen::VectorXf& u, const float& dt);
        Eigen::VectorXf update(const Eigen::VectorXf& z);
        Eigen::VectorXf residual(const Eigen::VectorXf& z);
        Eigen::MatrixXf Q,R;
    protected:
        Eigen::MatrixXf F,P,H;
        Eigen::VectorXf x,B;
       
};



#endif
