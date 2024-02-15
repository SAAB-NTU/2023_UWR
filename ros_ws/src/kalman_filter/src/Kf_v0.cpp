#include "../include/kalman_filter.h"

//First version - 1 DOF only


KalmanFilter::KalmanFilter()
{
    x << 0,0;
    H = Eigen::Matrix2f::Identity();
    P << 0.001,0,0,0.001;
    Q << 10,0,0,10;
    R << 0.01,0,0,0.01;
}

Eigen::Vector2f KalmanFilter::prediction(const float& u,const float& dt)
{
    // x_k = F_k * x_k-1 + B_k*u_k
    F << 1,dt,0,1;
    B << 0.5*dt*dt,dt;
    x = F*x + B*u;
    P = F*P*F.transpose() + Q;
    return x;
}

Eigen::Vector2f KalmanFilter::update(const Eigen::Vector2f& z)
{
    Eigen::Vector2f y = z-H*x;
    Eigen::Matrix2f K = P*H.transpose() * (H*P*H.transpose()+R).inverse();
    x = x + K*y;
    //joseph equation for stable computation
    //P = (Eigen::Matrix2f::Identity()-K*H)*P*(Eigen::Matrix2f::Identity()-K*H).transpose() + K*R*K.transpose(); //check again !!
    P = (Eigen::Matrix2f::Identity()-K*H)*P-(Eigen::Matrix2f::Identity()-K*H).transpose() + K*R*K.transpose(); //check again !!
    return x;
}

Eigen::Vector2f KalmanFilter::residual(const Eigen::Vector2f& z)
{
   return z-H*x; 
}