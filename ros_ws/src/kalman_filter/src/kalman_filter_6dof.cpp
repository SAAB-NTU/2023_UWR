#include "../include/kalman_filter.h"

KalmanFilter_6dof::KalmanFilter_6dof()
{
    x << 0,0,0,0,0,0; //6x1 state variable
    Eigen::Matrix<double, 6, 6> identityMatrix = Eigen::Matrix<double, 6, 6>::Identity();

    P << 0.001, 0, 0, 0, 0, 0,
         0, 0.001, 0, 0, 0, 0,
         0, 0, 0.001, 0, 0, 0,
         0, 0, 0, 0.001, 0, 0,
         0, 0, 0, 0, 0.001, 0,
         0, 0, 0, 0, 0, 0.001; //6x6 covariancematrix; so no covariance between state variables
    Q << 10, 0, 0, 0, 0, 0,
         0, 10, 0, 0, 0, 0,
         0, 0, 10, 0, 0, 0,
         0, 0, 0, 10, 0, 0,
         0, 0, 0, 0, 10, 0,
         0, 0, 0, 0, 0, 10; //6x6 process noise
    R << 0.01, 0, 0, 0, 0, 0,
         0, 0.01, 0, 0, 0, 0,
         0, 0, 0.01, 0, 0, 0,
         0, 0, 0, 0.01, 0, 0,
         0, 0, 0, 0, 0.01, 0,
         0, 0, 0, 0, 0, 0.01; //6x6 measurement noise
}

Eigen::VectorXf KalmanFilter_6dof::prediction(const Eigen::VectorXf& u,const float& dt)
{
    
    // x_k = F_k * x_k-1 + B_k*u_k
    // F << 1,dt,0,1;
    F << 1, dt, 0, 1, 0, 0,
         0, 1, 0, 0, 0, 0,
         0, 0, 1, dt, 0, 0,
         0, 0, 0, 1, 0, 0,
         0, 0, 0, 0, 1, dt,
         0, 0, 0, 0, 0, 1;
    // B << 0.5*dt*dt,dt;
    B << 0.5 * dt * dt, 0, 0,
          dt, 0, 0,
          0, 0.5 * dt * dt, 0,
          0, dt, 0,
          0, 0, 0.5 * dt * dt,
          0, 0, dt;


    x = F*x + B*u;
    P = F*P*F.transpose() + Q; //Update the covariance matrix P from above (due to the system dynamics)

    return x;
}

Eigen::VectorXf KalmanFilter_6dof::update(const Eigen::VectorXf& z) //z = SONAR output
{
Eigen::MatrixXf identityMatrix = Eigen::MatrixXf::Identity(6, 6);
    Eigen::VectorXf y = z-H*x; //y = residual error
    Eigen::MatrixXf K = P*H.transpose() * (H*P*H.transpose()+R).inverse(); //Kalman weighting matrix

    x = x + K*y;
    //joseph equation for stable computation
    //P = (Eigen::Matrix2f::Identity()-K*H)*P*(Eigen::Matrix2f::Identity()-K*H).transpose() + K*R*K.transpose(); //check again !!
    //P = (identityMatrix-K*H)*P-(identityMatrix-K*H).transpose() + K*R*K.transpose(); //check again !!
    P = (identityMatrix-K*H)*P-(identityMatrix-K*H).transpose() + K*R*K.transpose(); //check again !!
    return x;
}

Eigen::VectorXf KalmanFilter_6dof::residual(const Eigen::VectorXf& z)
{
   return z-H*x; 
}
