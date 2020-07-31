
#include <iostream>
//#include <Eigen/Eigen>
#include <eigen3/Eigen/Eigen>
#include <math.h>

Eigen::MatrixXd InertiaMatrix(Eigen::VectorXd q)
{
    
    //Variáveis de Configuração
    double AlphaR = q(0);
    double AlphaL = q(1); 
    double Phi    = q(2);
    double Theta  = q(3);
    double Psi    = q(4);
    double X      = q(5);
    double Y      = q(6);
    double Z      = q(7);
    
    Eigen::MatrixXd M(8,8);

    const double Ixx1 = 0.1489;
    const double Iyy1 = 0.1789;
    const double Izz1 = 0.3011;
    const double Ixz1 = -0.0189;
    const double Ixx2 = 0.0007103;
    const double Iyy2 = 0.00071045;
    const double Izz2 = 0.00021337;
    const double Ixx3 = 0.0007103;
    const double Iyy3 = 0.00071045;
    const double Izz3 = 0.00021337;
    const double ds = 0.02;
    const double B = 0.0524; //rad
    const double g = 9.8;
    const double b = 9.5e-6;
    const double Kt = 1.7e-7;
    const double M1 = 7.0;
    const double M2 = 0.3;
    const double M3 = 0.3;
    const double XB1 = 0.06684;
    const double YB1 = 0;
    const double ZB1 = 0.005392;
    const double pi = 3.14159265358979323846264338327950288419716939937510582097494459230781640628;
    const double XB2 = 0.078;
    const double YB2 = -0.6073;
    const double ZB2 = 0.1235;
    const double XB3 = 0.078;
    const double YB3 = 0.6073;
    const double ZB3 = 0.1235;

    double cosPhi = cos(Phi);
    double sinPhi = sin(Phi);
    double cosTheta = cos(Theta);
    double sinTheta = sin(Theta);
    double cosPsi = cos(Psi);
    double sinPsi = sin(Psi);
    double sinAlphaR = sin(AlphaR);
    double cosAlphaR = cos(AlphaR);
    double sinAlphaL = sin(AlphaL);
    double cosAlphaL = cos(AlphaL);
    double sinB = sin(B);
    double cosB = cos(B);

    M << Izz2 + Iyy2*pow(cosB,2) - Izz2*pow(cosB,2) + M2*pow(ds,2)*pow(cosB,2), 0, -cosB*sinAlphaR*(Iyy2*sinB - Izz2*sinB + M2*pow(ds,2)*sinB + M2*YB2*ds), Izz2*cosPhi + Iyy2*pow(cosB,2)*cosPhi - Izz2*pow(cosB,2)*cosPhi + M2*pow(ds,2)*pow(cosB,2)*cosPhi + Iyy2*cosAlphaR*cosB*sinB*sinPhi - Izz2*cosAlphaR*cosB*sinB*sinPhi + M2*pow(ds,2)*cosAlphaR*cosB*sinB*sinPhi + M2*ZB2*ds*cosAlphaR*cosB*cosPhi + M2*XB2*ds*cosB*cosPhi*sinAlphaR + M2*YB2*ds*cosAlphaR*cosB*sinPhi, Izz2*cosTheta*sinPhi + Iyy2*pow(cosB,2)*cosTheta*sinPhi - Izz2*pow(cosB,2)*cosTheta*sinPhi + Iyy2*cosB*sinAlphaR*sinB*sinTheta - Izz2*cosB*sinAlphaR*sinB*sinTheta + M2*pow(ds,2)*pow(cosB,2)*cosTheta*sinPhi - Iyy2*cosAlphaR*cosB*cosPhi*sinB*cosTheta + Izz2*cosAlphaR*cosB*cosPhi*sinB*cosTheta + M2*pow(ds,2)*cosB*sinAlphaR*sinB*sinTheta + M2*YB2*ds*cosB*sinAlphaR*sinTheta - M2*YB2*ds*cosAlphaR*cosB*cosPhi*cosTheta + M2*ZB2*ds*cosAlphaR*cosB*cosTheta*sinPhi + M2*XB2*ds*cosB*sinAlphaR*cosTheta*sinPhi - M2*pow(ds,2)*cosAlphaR*cosB*cosPhi*sinB*cosTheta, M2*ds*cosAlphaR*cosB*cosPsi*cosTheta - M2*ds*cosB*sinAlphaR*(sinPhi*sinPsi + cosPhi*cosPsi*sinTheta), M2*ds*cosB*sinAlphaR*(cosPsi*sinPhi - cosPhi*sinPsi*sinTheta) + M2*ds*cosAlphaR*cosB*cosTheta*sinPsi, -M2*ds*cosB*(cosAlphaR*sinTheta + cosPhi*sinAlphaR*cosTheta),
            0, Izz3 + Iyy3*pow(cosB,2) - Izz3*pow(cosB,2) + M3*pow(ds,2)*pow(cosB,2), cosB*sinAlphaL*(Iyy3*sinB - Izz3*sinB + M3*pow(ds,2)*sinB - M3*YB3*ds), Izz3*cosPhi + Iyy3*pow(cosB,2)*cosPhi - Izz3*pow(cosB,2)*cosPhi + M3*pow(ds,2)*pow(cosB,2)*cosPhi - Iyy3*cosAlphaL*cosB*sinB*sinPhi + Izz3*cosAlphaL*cosB*sinB*sinPhi - M3*pow(ds,2)*cosAlphaL*cosB*sinB*sinPhi + M3*ZB3*ds*cosAlphaL*cosB*cosPhi + M3*XB3*ds*cosB*cosPhi*sinAlphaL + M3*YB3*ds*cosAlphaL*cosB*sinPhi, Izz3*cosTheta*sinPhi + Iyy3*pow(cosB,2)*cosTheta*sinPhi - Izz3*pow(cosB,2)*cosTheta*sinPhi - Iyy3*cosB*sinAlphaL*sinB*sinTheta + Izz3*cosB*sinAlphaL*sinB*sinTheta + M3*pow(ds,2)*pow(cosB,2)*cosTheta*sinPhi + Iyy3*cosAlphaL*cosB*cosPhi*sinB*cosTheta - Izz3*cosAlphaL*cosB*cosPhi*sinB*cosTheta - M3*pow(ds,2)*cosB*sinAlphaL*sinB*sinTheta + M3*YB3*ds*cosB*sinAlphaL*sinTheta - M3*YB3*ds*cosAlphaL*cosB*cosPhi*cosTheta + M3*ZB3*ds*cosAlphaL*cosB*cosTheta*sinPhi + M3*XB3*ds*cosB*sinAlphaL*cosTheta*sinPhi + M3*pow(ds,2)*cosAlphaL*cosB*cosPhi*sinB*cosTheta, M3*ds*cosAlphaL*cosB*cosPsi*cosTheta - M3*ds*cosB*sinAlphaL*(sinPhi*sinPsi + cosPhi*cosPsi*sinTheta), M3*ds*cosB*sinAlphaL*(cosPsi*sinPhi - cosPhi*sinPsi*sinTheta) + M3*ds*cosAlphaL*cosB*cosTheta*sinPsi, -M3*ds*cosB*(cosAlphaL*sinTheta + cosPhi*sinAlphaL*cosTheta),
         -cosB*sinAlphaR*(Iyy2*sinB - Izz2*sinB + M2*pow(ds,2)*sinB + M2*YB2*ds), cosB*sinAlphaL*(Iyy3*sinB - Izz3*sinB + M3*pow(ds,2)*sinB - M3*YB3*ds), Ixx1 + Iyy2 + Iyy3 + M1*pow(YB1,2) + M2*pow(YB2,2) + M3*pow(YB3,2) + M1*pow(ZB1,2) + M2*pow(ZB2,2) + M3*pow(ZB3,2) + M2*pow(ds,2) + M3*pow(ds,2) + Ixx3*pow(cosAlphaL,2) + Ixx2*pow(cosAlphaR,2) - Iyy3*pow(cosAlphaL,2) - Iyy2*pow(cosAlphaR,2) - Iyy2*pow(cosB,2) - Iyy3*pow(cosB,2) + Izz2*pow(cosB,2) + Izz3*pow(cosB,2) - M2*pow(ds,2)*pow(cosB,2) - M3*pow(ds,2)*pow(cosB,2) + Iyy3*pow(cosAlphaL,2)*pow(cosB,2) + Iyy2*pow(cosAlphaR,2)*pow(cosB,2) - Izz3*pow(cosAlphaL,2)*pow(cosB,2) - Izz2*pow(cosAlphaR,2)*pow(cosB,2) + 2*M2*YB2*ds*sinB - 2*M3*YB3*ds*sinB + M3*pow(ds,2)*pow(cosAlphaL,2)*pow(cosB,2) + M2*pow(ds,2)*pow(cosAlphaR,2)*pow(cosB,2) + 2*M3*ZB3*ds*cosAlphaL*cosB + 2*M2*ZB2*ds*cosAlphaR*cosB, M1*XB1*ZB1*sinPhi - M1*XB1*YB1*cosPhi - M2*XB2*YB2*cosPhi - M3*XB3*YB3*cosPhi - Ixz1*sinPhi + M2*XB2*ZB2*sinPhi + M3*XB3*ZB3*sinPhi + Ixx3*cosAlphaL*sinAlphaL*sinPhi + Ixx2*cosAlphaR*sinAlphaR*sinPhi - Iyy3*cosAlphaL*sinAlphaL*sinPhi - Iyy2*cosAlphaR*sinAlphaR*sinPhi + Iyy3*cosB*cosPhi*sinAlphaL*sinB - Iyy2*cosB*cosPhi*sinAlphaR*sinB - Izz3*cosB*cosPhi*sinAlphaL*sinB + Izz2*cosB*cosPhi*sinAlphaR*sinB + Iyy3*cosAlphaL*pow(cosB,2)*sinAlphaL*sinPhi + Iyy2*cosAlphaR*pow(cosB,2)*sinAlphaR*sinPhi - Izz3*cosAlphaL*pow(cosB,2)*sinAlphaL*sinPhi - Izz2*cosAlphaR*pow(cosB,2)*sinAlphaR*sinPhi - M2*XB2*ds*cosPhi*sinB + M3*XB3*ds*cosPhi*sinB + M3*pow(ds,2)*cosB*cosPhi*sinAlphaL*sinB - M2*pow(ds,2)*cosB*cosPhi*sinAlphaR*sinB + M3*XB3*ds*cosAlphaL*cosB*sinPhi + M2*XB2*ds*cosAlphaR*cosB*sinPhi - M3*YB3*ds*cosB*cosPhi*sinAlphaL - M2*YB2*ds*cosB*cosPhi*sinAlphaR + M3*ZB3*ds*cosB*sinAlphaL*sinPhi + M2*ZB2*ds*cosB*sinAlphaR*sinPhi + M3*pow(ds,2)*cosAlphaL*pow(cosB,2)*sinAlphaL*sinPhi + M2*pow(ds,2)*cosAlphaR*pow(cosB,2)*sinAlphaR*sinPhi, Ixz1*cosPhi*cosTheta - Iyy2*sinTheta - Iyy3*sinTheta - Ixx1*sinTheta - M1*pow(YB1,2)*sinTheta - M2*pow(YB2,2)*sinTheta - M3*pow(YB3,2)*sinTheta - M1*pow(ZB1,2)*sinTheta - M2*pow(ZB2,2)*sinTheta - M3*pow(ZB3,2)*sinTheta - M2*pow(ds,2)*sinTheta - M3*pow(ds,2)*sinTheta - Ixx3*pow(cosAlphaL,2)*sinTheta - Ixx2*pow(cosAlphaR,2)*sinTheta + Iyy3*pow(cosAlphaL,2)*sinTheta + Iyy2*pow(cosAlphaR,2)*sinTheta + Iyy2*pow(cosB,2)*sinTheta + Iyy3*pow(cosB,2)*sinTheta - Izz2*pow(cosB,2)*sinTheta - Izz3*pow(cosB,2)*sinTheta + M2*pow(ds,2)*pow(cosB,2)*sinTheta + M3*pow(ds,2)*pow(cosB,2)*sinTheta - Iyy3*pow(cosAlphaL,2)*pow(cosB,2)*sinTheta - Iyy2*pow(cosAlphaR,2)*pow(cosB,2)*sinTheta + Izz3*pow(cosAlphaL,2)*pow(cosB,2)*sinTheta + Izz2*pow(cosAlphaR,2)*pow(cosB,2)*sinTheta - M3*pow(ds,2)*pow(cosAlphaL,2)*pow(cosB,2)*sinTheta - M2*pow(ds,2)*pow(cosAlphaR,2)*pow(cosB,2)*sinTheta - Ixx3*cosAlphaL*cosPhi*sinAlphaL*cosTheta - Ixx2*cosAlphaR*cosPhi*sinAlphaR*cosTheta + Iyy3*cosAlphaL*cosPhi*sinAlphaL*cosTheta + Iyy2*cosAlphaR*cosPhi*sinAlphaR*cosTheta - M1*XB1*ZB1*cosPhi*cosTheta - M2*XB2*ZB2*cosPhi*cosTheta - M3*XB3*ZB3*cosPhi*cosTheta - M1*XB1*YB1*cosTheta*sinPhi - M2*XB2*YB2*cosTheta*sinPhi - M3*XB3*YB3*cosTheta*sinPhi - 2*M2*YB2*ds*sinB*sinTheta + 2*M3*YB3*ds*sinB*sinTheta + Iyy3*cosB*sinAlphaL*sinB*cosTheta*sinPhi - Iyy2*cosB*sinAlphaR*sinB*cosTheta*sinPhi - Izz3*cosB*sinAlphaL*sinB*cosTheta*sinPhi + Izz2*cosB*sinAlphaR*sinB*cosTheta*sinPhi - Iyy3*cosAlphaL*pow(cosB,2)*cosPhi*sinAlphaL*cosTheta - Iyy2*cosAlphaR*pow(cosB,2)*cosPhi*sinAlphaR*cosTheta + Izz3*cosAlphaL*pow(cosB,2)*cosPhi*sinAlphaL*cosTheta + Izz2*cosAlphaR*pow(cosB,2)*cosPhi*sinAlphaR*cosTheta - 2*M3*ZB3*ds*cosAlphaL*cosB*sinTheta - 2*M2*ZB2*ds*cosAlphaR*cosB*sinTheta - M2*XB2*ds*sinB*cosTheta*sinPhi + M3*XB3*ds*sinB*cosTheta*sinPhi - M3*XB3*ds*cosAlphaL*cosB*cosPhi*cosTheta - M2*XB2*ds*cosAlphaR*cosB*cosPhi*cosTheta - M3*ZB3*ds*cosB*cosPhi*sinAlphaL*cosTheta - M2*ZB2*ds*cosB*cosPhi*sinAlphaR*cosTheta - M3*pow(ds,2)*cosAlphaL*pow(cosB,2)*cosPhi*sinAlphaL*cosTheta - M2*pow(ds,2)*cosAlphaR*pow(cosB,2)*cosPhi*sinAlphaR*cosTheta - M3*YB3*ds*cosB*sinAlphaL*cosTheta*sinPhi - M2*YB2*ds*cosB*sinAlphaR*cosTheta*sinPhi + M3*pow(ds,2)*cosB*sinAlphaL*sinB*cosTheta*sinPhi - M2*pow(ds,2)*cosB*sinAlphaR*sinB*cosTheta*sinPhi, M1*(YB1*(sinPhi*sinPsi + cosPhi*cosPsi*sinTheta) + ZB1*(cosPhi*sinPsi - cosPsi*sinPhi*sinTheta)) + M3*(YB3*(sinPhi*sinPsi + cosPhi*cosPsi*sinTheta) - ds*(sinB*(sinPhi*sinPsi + cosPhi*cosPsi*sinTheta) - cosAlphaL*cosB*(cosPhi*sinPsi - cosPsi*sinPhi*sinTheta)) + ZB3*(cosPhi*sinPsi - cosPsi*sinPhi*sinTheta)) + M2*(ds*(sinB*(sinPhi*sinPsi + cosPhi*cosPsi*sinTheta) + cosAlphaR*cosB*(cosPhi*sinPsi - cosPsi*sinPhi*sinTheta)) + YB2*(sinPhi*sinPsi + cosPhi*cosPsi*sinTheta) + ZB2*(cosPhi*sinPsi - cosPsi*sinPhi*sinTheta)), - M1*(YB1*(cosPsi*sinPhi - cosPhi*sinPsi*sinTheta) + ZB1*(cosPhi*cosPsi + sinPhi*sinPsi*sinTheta)) - M3*(YB3*(cosPsi*sinPhi - cosPhi*sinPsi*sinTheta) - ds*(sinB*(cosPsi*sinPhi - cosPhi*sinPsi*sinTheta) - cosAlphaL*cosB*(cosPhi*cosPsi + sinPhi*sinPsi*sinTheta)) + ZB3*(cosPhi*cosPsi + sinPhi*sinPsi*sinTheta)) - M2*(ds*(sinB*(cosPsi*sinPhi - cosPhi*sinPsi*sinTheta) + cosAlphaR*cosB*(cosPhi*cosPsi + sinPhi*sinPsi*sinTheta)) + YB2*(cosPsi*sinPhi - cosPhi*sinPsi*sinTheta) + ZB2*(cosPhi*cosPsi + sinPhi*sinPsi*sinTheta)), M2*cosTheta*(YB2*cosPhi - ZB2*sinPhi + ds*cosPhi*sinB - ds*cosAlphaR*cosB*sinPhi) - M3*cosTheta*(ZB3*sinPhi - YB3*cosPhi + ds*cosPhi*sinB + ds*cosAlphaL*cosB*sinPhi) + M1*cosTheta*(YB1*cosPhi - ZB1*sinPhi),
        Izz2*cosPhi + Iyy2*pow(cosB,2)*cosPhi - Izz2*pow(cosB,2)*cosPhi + M2*pow(ds,2)*pow(cosB,2)*cosPhi + Iyy2*cosAlphaR*cosB*sinB*sinPhi - Izz2*cosAlphaR*cosB*sinB*sinPhi + M2*pow(ds,2)*cosAlphaR*cosB*sinB*sinPhi + M2*ZB2*ds*cosAlphaR*cosB*cosPhi + M2*XB2*ds*cosB*cosPhi*sinAlphaR + M2*YB2*ds*cosAlphaR*cosB*sinPhi, Izz3*cosPhi + Iyy3*pow(cosB,2)*cosPhi - Izz3*pow(cosB,2)*cosPhi + M3*pow(ds,2)*pow(cosB,2)*cosPhi - Iyy3*cosAlphaL*cosB*sinB*sinPhi + Izz3*cosAlphaL*cosB*sinB*sinPhi - M3*pow(ds,2)*cosAlphaL*cosB*sinB*sinPhi + M3*ZB3*ds*cosAlphaL*cosB*cosPhi + M3*XB3*ds*cosB*cosPhi*sinAlphaL + M3*YB3*ds*cosAlphaL*cosB*sinPhi, M1*XB1*ZB1*sinPhi - M1*XB1*YB1*cosPhi - M2*XB2*YB2*cosPhi - M3*XB3*YB3*cosPhi - Ixz1*sinPhi + M2*XB2*ZB2*sinPhi + M3*XB3*ZB3*sinPhi + Ixx3*cosAlphaL*sinAlphaL*sinPhi + Ixx2*cosAlphaR*sinAlphaR*sinPhi - Iyy3*cosAlphaL*sinAlphaL*sinPhi - Iyy2*cosAlphaR*sinAlphaR*sinPhi + Iyy3*cosB*cosPhi*sinAlphaL*sinB - Iyy2*cosB*cosPhi*sinAlphaR*sinB - Izz3*cosB*cosPhi*sinAlphaL*sinB + Izz2*cosB*cosPhi*sinAlphaR*sinB + Iyy3*cosAlphaL*pow(cosB,2)*sinAlphaL*sinPhi + Iyy2*cosAlphaR*pow(cosB,2)*sinAlphaR*sinPhi - Izz3*cosAlphaL*pow(cosB,2)*sinAlphaL*sinPhi - Izz2*cosAlphaR*pow(cosB,2)*sinAlphaR*sinPhi - M2*XB2*ds*cosPhi*sinB + M3*XB3*ds*cosPhi*sinB + M3*pow(ds,2)*cosB*cosPhi*sinAlphaL*sinB - M2*pow(ds,2)*cosB*cosPhi*sinAlphaR*sinB + M3*XB3*ds*cosAlphaL*cosB*sinPhi + M2*XB2*ds*cosAlphaR*cosB*sinPhi - M3*YB3*ds*cosB*cosPhi*sinAlphaL - M2*YB2*ds*cosB*cosPhi*sinAlphaR + M3*ZB3*ds*cosB*sinAlphaL*sinPhi + M2*ZB2*ds*cosB*sinAlphaR*sinPhi + M3*pow(ds,2)*cosAlphaL*pow(cosB,2)*sinAlphaL*sinPhi + M2*pow(ds,2)*cosAlphaR*pow(cosB,2)*sinAlphaR*sinPhi, Ixx2 + Ixx3 + Izz1 + M1*pow(XB1,2) + M2*pow(XB2,2) + M3*pow(XB3,2) + M1*pow(YB1,2) + M2*pow(YB2,2) + M3*pow(YB3,2) + M2*pow(ds,2) + M3*pow(ds,2) - Ixx3*pow(cosAlphaL,2) - Ixx2*pow(cosAlphaR,2) + Iyy3*pow(cosAlphaL,2) + Iyy2*pow(cosAlphaR,2) - Ixx2*pow(cosPhi,2) - Ixx3*pow(cosPhi,2) + Iyy1*pow(cosPhi,2) - Izz1*pow(cosPhi,2) + Izz2*pow(cosPhi,2) + Izz3*pow(cosPhi,2) - M1*pow(YB1,2)*pow(cosPhi,2) - M2*pow(YB2,2)*pow(cosPhi,2) - M3*pow(YB3,2)*pow(cosPhi,2) + M1*pow(ZB1,2)*pow(cosPhi,2) + M2*pow(ZB2,2)*pow(cosPhi,2) + M3*pow(ZB3,2)*pow(cosPhi,2) - M2*pow(ds,2)*pow(cosPhi,2) - M3*pow(ds,2)*pow(cosPhi,2) - Iyy3*pow(cosAlphaL,2)*pow(cosB,2) - Iyy2*pow(cosAlphaR,2)*pow(cosB,2) + Izz3*pow(cosAlphaL,2)*pow(cosB,2) + Izz2*pow(cosAlphaR,2)*pow(cosB,2) + Ixx3*pow(cosAlphaL,2)*pow(cosPhi,2) + Ixx2*pow(cosAlphaR,2)*pow(cosPhi,2) - Iyy3*pow(cosAlphaL,2)*pow(cosPhi,2) - Iyy2*pow(cosAlphaR,2)*pow(cosPhi,2) + Iyy2*pow(cosB,2)*pow(cosPhi,2) + Iyy3*pow(cosB,2)*pow(cosPhi,2) - Izz2*pow(cosB,2)*pow(cosPhi,2) - Izz3*pow(cosB,2)*pow(cosPhi,2) + 2*M2*YB2*ds*sinB - 2*M3*YB3*ds*sinB - M3*pow(ds,2)*pow(cosAlphaL,2)*pow(cosB,2) - M2*pow(ds,2)*pow(cosAlphaR,2)*pow(cosB,2) + M2*pow(ds,2)*pow(cosB,2)*pow(cosPhi,2) + M3*pow(ds,2)*pow(cosB,2)*pow(cosPhi,2) + Iyy3*pow(cosAlphaL,2)*pow(cosB,2)*pow(cosPhi,2) + Iyy2*pow(cosAlphaR,2)*pow(cosB,2)*pow(cosPhi,2) - Izz3*pow(cosAlphaL,2)*pow(cosB,2)*pow(cosPhi,2) - Izz2*pow(cosAlphaR,2)*pow(cosB,2)*pow(cosPhi,2) - 2*M2*YB2*ds*pow(cosPhi,2)*sinB + 2*M3*YB3*ds*pow(cosPhi,2)*sinB + M3*pow(ds,2)*pow(cosAlphaL,2)*pow(cosB,2)*pow(cosPhi,2) + M2*pow(ds,2)*pow(cosAlphaR,2)*pow(cosB,2)*pow(cosPhi,2) + 2*M3*XB3*ds*cosB*sinAlphaL + 2*M2*XB2*ds*cosB*sinAlphaR + 2*M1*YB1*ZB1*cosPhi*sinPhi + 2*M2*YB2*ZB2*cosPhi*sinPhi + 2*M3*YB3*ZB3*cosPhi*sinPhi - 2*Iyy3*cosAlphaL*cosB*cosPhi*sinB*sinPhi + 2*Iyy2*cosAlphaR*cosB*cosPhi*sinB*sinPhi + 2*Izz3*cosAlphaL*cosB*cosPhi*sinB*sinPhi - 2*Izz2*cosAlphaR*cosB*cosPhi*sinB*sinPhi + 2*M2*ZB2*ds*cosPhi*sinB*sinPhi - 2*M3*ZB3*ds*cosPhi*sinB*sinPhi + 2*M3*ZB3*ds*cosAlphaL*cosB*pow(cosPhi,2) + 2*M2*ZB2*ds*cosAlphaR*cosB*pow(cosPhi,2) + 2*M3*YB3*ds*cosAlphaL*cosB*cosPhi*sinPhi + 2*M2*YB2*ds*cosAlphaR*cosB*cosPhi*sinPhi - 2*M3*pow(ds,2)*cosAlphaL*cosB*cosPhi*sinB*sinPhi + 2*M2*pow(ds,2)*cosAlphaR*cosB*cosPhi*sinB*sinPhi, Ixz1*sinPhi*sinTheta + M1*YB1*ZB1*cosTheta + M2*YB2*ZB2*cosTheta + M3*YB3*ZB3*cosTheta - Ixx2*cosPhi*cosTheta*sinPhi - Ixx3*cosPhi*cosTheta*sinPhi + Iyy1*cosPhi*cosTheta*sinPhi - Izz1*cosPhi*cosTheta*sinPhi + Izz2*cosPhi*cosTheta*sinPhi + Izz3*cosPhi*cosTheta*sinPhi - 2*M1*YB1*ZB1*pow(cosPhi,2)*cosTheta - 2*M2*YB2*ZB2*pow(cosPhi,2)*cosTheta - 2*M3*YB3*ZB3*pow(cosPhi,2)*cosTheta - Iyy3*cosAlphaL*cosB*sinB*cosTheta + Iyy2*cosAlphaR*cosB*sinB*cosTheta + Izz3*cosAlphaL*cosB*sinB*cosTheta - Izz2*cosAlphaR*cosB*sinB*cosTheta - Ixx3*cosAlphaL*sinAlphaL*sinPhi*sinTheta - Ixx2*cosAlphaR*sinAlphaR*sinPhi*sinTheta + Iyy3*cosAlphaL*sinAlphaL*sinPhi*sinTheta + Iyy2*cosAlphaR*sinAlphaR*sinPhi*sinTheta - M1*pow(YB1,2)*cosPhi*cosTheta*sinPhi - M2*pow(YB2,2)*cosPhi*cosTheta*sinPhi - M3*pow(YB3,2)*cosPhi*cosTheta*sinPhi + M1*pow(ZB1,2)*cosPhi*cosTheta*sinPhi + M2*pow(ZB2,2)*cosPhi*cosTheta*sinPhi + M3*pow(ZB3,2)*cosPhi*cosTheta*sinPhi - M2*pow(ds,2)*cosPhi*cosTheta*sinPhi - M3*pow(ds,2)*cosPhi*cosTheta*sinPhi + M2*ZB2*ds*sinB*cosTheta - M3*ZB3*ds*sinB*cosTheta + M1*XB1*YB1*cosPhi*sinTheta + M2*XB2*YB2*cosPhi*sinTheta + M3*XB3*YB3*cosPhi*sinTheta + Ixx3*pow(cosAlphaL,2)*cosPhi*cosTheta*sinPhi + Ixx2*pow(cosAlphaR,2)*cosPhi*cosTheta*sinPhi - Iyy3*pow(cosAlphaL,2)*cosPhi*cosTheta*sinPhi - Iyy2*pow(cosAlphaR,2)*cosPhi*cosTheta*sinPhi + Iyy2*pow(cosB,2)*cosPhi*cosTheta*sinPhi + Iyy3*pow(cosB,2)*cosPhi*cosTheta*sinPhi - Izz2*pow(cosB,2)*cosPhi*cosTheta*sinPhi - Izz3*pow(cosB,2)*cosPhi*cosTheta*sinPhi - M1*XB1*ZB1*sinPhi*sinTheta - M2*XB2*ZB2*sinPhi*sinTheta - M3*XB3*ZB3*sinPhi*sinTheta - M3*pow(ds,2)*cosAlphaL*cosB*sinB*cosTheta + M2*pow(ds,2)*cosAlphaR*cosB*sinB*cosTheta - Iyy3*cosB*cosPhi*sinAlphaL*sinB*sinTheta + Iyy2*cosB*cosPhi*sinAlphaR*sinB*sinTheta + Izz3*cosB*cosPhi*sinAlphaL*sinB*sinTheta - Izz2*cosB*cosPhi*sinAlphaR*sinB*sinTheta + M3*YB3*ds*cosAlphaL*cosB*cosTheta + M2*YB2*ds*cosAlphaR*cosB*cosTheta + 2*Iyy3*cosAlphaL*cosB*pow(cosPhi,2)*sinB*cosTheta - 2*Iyy2*cosAlphaR*cosB*pow(cosPhi,2)*sinB*cosTheta - 2*Izz3*cosAlphaL*cosB*pow(cosPhi,2)*sinB*cosTheta + 2*Izz2*cosAlphaR*cosB*pow(cosPhi,2)*sinB*cosTheta - Iyy3*cosAlphaL*pow(cosB,2)*sinAlphaL*sinPhi*sinTheta - Iyy2*cosAlphaR*pow(cosB,2)*sinAlphaR*sinPhi*sinTheta + Izz3*cosAlphaL*pow(cosB,2)*sinAlphaL*sinPhi*sinTheta + Izz2*cosAlphaR*pow(cosB,2)*sinAlphaR*sinPhi*sinTheta + M2*XB2*ds*cosPhi*sinB*sinTheta - M3*XB3*ds*cosPhi*sinB*sinTheta + M2*pow(ds,2)*pow(cosB,2)*cosPhi*cosTheta*sinPhi + M3*pow(ds,2)*pow(cosB,2)*cosPhi*cosTheta*sinPhi + Iyy3*pow(cosAlphaL,2)*pow(cosB,2)*cosPhi*cosTheta*sinPhi + Iyy2*pow(cosAlphaR,2)*pow(cosB,2)*cosPhi*cosTheta*sinPhi - Izz3*pow(cosAlphaL,2)*pow(cosB,2)*cosPhi*cosTheta*sinPhi - Izz2*pow(cosAlphaR,2)*pow(cosB,2)*cosPhi*cosTheta*sinPhi - 2*M2*ZB2*ds*pow(cosPhi,2)*sinB*cosTheta + 2*M3*ZB3*ds*pow(cosPhi,2)*sinB*cosTheta + 2*M3*pow(ds,2)*cosAlphaL*cosB*pow(cosPhi,2)*sinB*cosTheta - 2*M2*pow(ds,2)*cosAlphaR*cosB*pow(cosPhi,2)*sinB*cosTheta - M3*XB3*ds*cosAlphaL*cosB*sinPhi*sinTheta - M2*XB2*ds*cosAlphaR*cosB*sinPhi*sinTheta + M3*YB3*ds*cosB*cosPhi*sinAlphaL*sinTheta + M2*YB2*ds*cosB*cosPhi*sinAlphaR*sinTheta - 2*M2*YB2*ds*cosPhi*sinB*cosTheta*sinPhi + 2*M3*YB3*ds*cosPhi*sinB*cosTheta*sinPhi - M3*ZB3*ds*cosB*sinAlphaL*sinPhi*sinTheta - M2*ZB2*ds*cosB*sinAlphaR*sinPhi*sinTheta - M3*pow(ds,2)*cosAlphaL*pow(cosB,2)*sinAlphaL*sinPhi*sinTheta - M2*pow(ds,2)*cosAlphaR*pow(cosB,2)*sinAlphaR*sinPhi*sinTheta - 2*M3*YB3*ds*cosAlphaL*cosB*pow(cosPhi,2)*cosTheta - 2*M2*YB2*ds*cosAlphaR*cosB*pow(cosPhi,2)*cosTheta + M3*pow(ds,2)*pow(cosAlphaL,2)*pow(cosB,2)*cosPhi*cosTheta*sinPhi + M2*pow(ds,2)*pow(cosAlphaR,2)*pow(cosB,2)*cosPhi*cosTheta*sinPhi - M3*pow(ds,2)*cosB*cosPhi*sinAlphaL*sinB*sinTheta + M2*pow(ds,2)*cosB*cosPhi*sinAlphaR*sinB*sinTheta + 2*M3*ZB3*ds*cosAlphaL*cosB*cosPhi*cosTheta*sinPhi + 2*M2*ZB2*ds*cosAlphaR*cosB*cosPhi*cosTheta*sinPhi, M1*cosPsi*(ZB1*cosPhi*cosTheta - XB1*sinTheta + YB1*cosTheta*sinPhi) - M3*cosPsi*(XB3*sinTheta - ZB3*cosPhi*cosTheta - YB3*cosTheta*sinPhi + ds*cosB*sinAlphaL*sinTheta + ds*sinB*cosTheta*sinPhi - ds*cosAlphaL*cosB*cosPhi*cosTheta) + M2*cosPsi*(ZB2*cosPhi*cosTheta - XB2*sinTheta + YB2*cosTheta*sinPhi - ds*cosB*sinAlphaR*sinTheta + ds*sinB*cosTheta*sinPhi + ds*cosAlphaR*cosB*cosPhi*cosTheta), M1*sinPsi*(ZB1*cosPhi*cosTheta - XB1*sinTheta + YB1*cosTheta*sinPhi) - M3*sinPsi*(XB3*sinTheta - ZB3*cosPhi*cosTheta - YB3*cosTheta*sinPhi + ds*cosB*sinAlphaL*sinTheta + ds*sinB*cosTheta*sinPhi - ds*cosAlphaL*cosB*cosPhi*cosTheta) + M2*sinPsi*(ZB2*cosPhi*cosTheta - XB2*sinTheta + YB2*cosTheta*sinPhi - ds*cosB*sinAlphaR*sinTheta + ds*sinB*cosTheta*sinPhi + ds*cosAlphaR*cosB*cosPhi*cosTheta), - M3*(XB3*cosTheta + ZB3*cosPhi*sinTheta + YB3*sinPhi*sinTheta - ds*sinB*sinPhi*sinTheta + ds*cosB*sinAlphaL*cosTheta + ds*cosAlphaL*cosB*cosPhi*sinTheta) - M2*(XB2*cosTheta + ZB2*cosPhi*sinTheta + YB2*sinPhi*sinTheta + ds*sinB*sinPhi*sinTheta + ds*cosB*sinAlphaR*cosTheta + ds*cosAlphaR*cosB*cosPhi*sinTheta) - M1*(XB1*cosTheta + ZB1*cosPhi*sinTheta + YB1*sinPhi*sinTheta),
        Izz2*cosTheta*sinPhi + Iyy2*pow(cosB,2)*cosTheta*sinPhi - Izz2*pow(cosB,2)*cosTheta*sinPhi + Iyy2*cosB*sinAlphaR*sinB*sinTheta - Izz2*cosB*sinAlphaR*sinB*sinTheta + M2*pow(ds,2)*pow(cosB,2)*cosTheta*sinPhi - Iyy2*cosAlphaR*cosB*cosPhi*sinB*cosTheta + Izz2*cosAlphaR*cosB*cosPhi*sinB*cosTheta + M2*pow(ds,2)*cosB*sinAlphaR*sinB*sinTheta + M2*YB2*ds*cosB*sinAlphaR*sinTheta - M2*YB2*ds*cosAlphaR*cosB*cosPhi*cosTheta + M2*ZB2*ds*cosAlphaR*cosB*cosTheta*sinPhi + M2*XB2*ds*cosB*sinAlphaR*cosTheta*sinPhi - M2*pow(ds,2)*cosAlphaR*cosB*cosPhi*sinB*cosTheta, Izz3*cosTheta*sinPhi + Iyy3*pow(cosB,2)*cosTheta*sinPhi - Izz3*pow(cosB,2)*cosTheta*sinPhi - Iyy3*cosB*sinAlphaL*sinB*sinTheta + Izz3*cosB*sinAlphaL*sinB*sinTheta + M3*pow(ds,2)*pow(cosB,2)*cosTheta*sinPhi + Iyy3*cosAlphaL*cosB*cosPhi*sinB*cosTheta - Izz3*cosAlphaL*cosB*cosPhi*sinB*cosTheta - M3*pow(ds,2)*cosB*sinAlphaL*sinB*sinTheta + M3*YB3*ds*cosB*sinAlphaL*sinTheta - M3*YB3*ds*cosAlphaL*cosB*cosPhi*cosTheta + M3*ZB3*ds*cosAlphaL*cosB*cosTheta*sinPhi + M3*XB3*ds*cosB*sinAlphaL*cosTheta*sinPhi + M3*pow(ds,2)*cosAlphaL*cosB*cosPhi*sinB*cosTheta, Ixz1*cosPhi*cosTheta - Iyy2*sinTheta - Iyy3*sinTheta - Ixx1*sinTheta - M1*pow(YB1,2)*sinTheta - M2*pow(YB2,2)*sinTheta - M3*pow(YB3,2)*sinTheta - M1*pow(ZB1,2)*sinTheta - M2*pow(ZB2,2)*sinTheta - M3*pow(ZB3,2)*sinTheta - M2*pow(ds,2)*sinTheta - M3*pow(ds,2)*sinTheta - Ixx3*pow(cosAlphaL,2)*sinTheta - Ixx2*pow(cosAlphaR,2)*sinTheta + Iyy3*pow(cosAlphaL,2)*sinTheta + Iyy2*pow(cosAlphaR,2)*sinTheta + Iyy2*pow(cosB,2)*sinTheta + Iyy3*pow(cosB,2)*sinTheta - Izz2*pow(cosB,2)*sinTheta - Izz3*pow(cosB,2)*sinTheta + M2*pow(ds,2)*pow(cosB,2)*sinTheta + M3*pow(ds,2)*pow(cosB,2)*sinTheta - Iyy3*pow(cosAlphaL,2)*pow(cosB,2)*sinTheta - Iyy2*pow(cosAlphaR,2)*pow(cosB,2)*sinTheta + Izz3*pow(cosAlphaL,2)*pow(cosB,2)*sinTheta + Izz2*pow(cosAlphaR,2)*pow(cosB,2)*sinTheta - M3*pow(ds,2)*pow(cosAlphaL,2)*pow(cosB,2)*sinTheta - M2*pow(ds,2)*pow(cosAlphaR,2)*pow(cosB,2)*sinTheta - Ixx3*cosAlphaL*cosPhi*sinAlphaL*cosTheta - Ixx2*cosAlphaR*cosPhi*sinAlphaR*cosTheta + Iyy3*cosAlphaL*cosPhi*sinAlphaL*cosTheta + Iyy2*cosAlphaR*cosPhi*sinAlphaR*cosTheta - M1*XB1*ZB1*cosPhi*cosTheta - M2*XB2*ZB2*cosPhi*cosTheta - M3*XB3*ZB3*cosPhi*cosTheta - M1*XB1*YB1*cosTheta*sinPhi - M2*XB2*YB2*cosTheta*sinPhi - M3*XB3*YB3*cosTheta*sinPhi - 2*M2*YB2*ds*sinB*sinTheta + 2*M3*YB3*ds*sinB*sinTheta + Iyy3*cosB*sinAlphaL*sinB*cosTheta*sinPhi - Iyy2*cosB*sinAlphaR*sinB*cosTheta*sinPhi - Izz3*cosB*sinAlphaL*sinB*cosTheta*sinPhi + Izz2*cosB*sinAlphaR*sinB*cosTheta*sinPhi - Iyy3*cosAlphaL*pow(cosB,2)*cosPhi*sinAlphaL*cosTheta - Iyy2*cosAlphaR*pow(cosB,2)*cosPhi*sinAlphaR*cosTheta + Izz3*cosAlphaL*pow(cosB,2)*cosPhi*sinAlphaL*cosTheta + Izz2*cosAlphaR*pow(cosB,2)*cosPhi*sinAlphaR*cosTheta - 2*M3*ZB3*ds*cosAlphaL*cosB*sinTheta - 2*M2*ZB2*ds*cosAlphaR*cosB*sinTheta - M2*XB2*ds*sinB*cosTheta*sinPhi + M3*XB3*ds*sinB*cosTheta*sinPhi - M3*XB3*ds*cosAlphaL*cosB*cosPhi*cosTheta - M2*XB2*ds*cosAlphaR*cosB*cosPhi*cosTheta - M3*ZB3*ds*cosB*cosPhi*sinAlphaL*cosTheta - M2*ZB2*ds*cosB*cosPhi*sinAlphaR*cosTheta - M3*pow(ds,2)*cosAlphaL*pow(cosB,2)*cosPhi*sinAlphaL*cosTheta - M2*pow(ds,2)*cosAlphaR*pow(cosB,2)*cosPhi*sinAlphaR*cosTheta - M3*YB3*ds*cosB*sinAlphaL*cosTheta*sinPhi - M2*YB2*ds*cosB*sinAlphaR*cosTheta*sinPhi + M3*pow(ds,2)*cosB*sinAlphaL*sinB*cosTheta*sinPhi - M2*pow(ds,2)*cosB*sinAlphaR*sinB*cosTheta*sinPhi, Ixz1*sinPhi*sinTheta + M1*YB1*ZB1*cosTheta + M2*YB2*ZB2*cosTheta + M3*YB3*ZB3*cosTheta - Ixx2*cosPhi*cosTheta*sinPhi - Ixx3*cosPhi*cosTheta*sinPhi + Iyy1*cosPhi*cosTheta*sinPhi - Izz1*cosPhi*cosTheta*sinPhi + Izz2*cosPhi*cosTheta*sinPhi + Izz3*cosPhi*cosTheta*sinPhi - 2*M1*YB1*ZB1*pow(cosPhi,2)*cosTheta - 2*M2*YB2*ZB2*pow(cosPhi,2)*cosTheta - 2*M3*YB3*ZB3*pow(cosPhi,2)*cosTheta - Iyy3*cosAlphaL*cosB*sinB*cosTheta + Iyy2*cosAlphaR*cosB*sinB*cosTheta + Izz3*cosAlphaL*cosB*sinB*cosTheta - Izz2*cosAlphaR*cosB*sinB*cosTheta - Ixx3*cosAlphaL*sinAlphaL*sinPhi*sinTheta - Ixx2*cosAlphaR*sinAlphaR*sinPhi*sinTheta + Iyy3*cosAlphaL*sinAlphaL*sinPhi*sinTheta + Iyy2*cosAlphaR*sinAlphaR*sinPhi*sinTheta - M1*pow(YB1,2)*cosPhi*cosTheta*sinPhi - M2*pow(YB2,2)*cosPhi*cosTheta*sinPhi - M3*pow(YB3,2)*cosPhi*cosTheta*sinPhi + M1*pow(ZB1,2)*cosPhi*cosTheta*sinPhi + M2*pow(ZB2,2)*cosPhi*cosTheta*sinPhi + M3*pow(ZB3,2)*cosPhi*cosTheta*sinPhi - M2*pow(ds,2)*cosPhi*cosTheta*sinPhi - M3*pow(ds,2)*cosPhi*cosTheta*sinPhi + M2*ZB2*ds*sinB*cosTheta - M3*ZB3*ds*sinB*cosTheta + M1*XB1*YB1*cosPhi*sinTheta + M2*XB2*YB2*cosPhi*sinTheta + M3*XB3*YB3*cosPhi*sinTheta + Ixx3*pow(cosAlphaL,2)*cosPhi*cosTheta*sinPhi + Ixx2*pow(cosAlphaR,2)*cosPhi*cosTheta*sinPhi - Iyy3*pow(cosAlphaL,2)*cosPhi*cosTheta*sinPhi - Iyy2*pow(cosAlphaR,2)*cosPhi*cosTheta*sinPhi + Iyy2*pow(cosB,2)*cosPhi*cosTheta*sinPhi + Iyy3*pow(cosB,2)*cosPhi*cosTheta*sinPhi - Izz2*pow(cosB,2)*cosPhi*cosTheta*sinPhi - Izz3*pow(cosB,2)*cosPhi*cosTheta*sinPhi - M1*XB1*ZB1*sinPhi*sinTheta - M2*XB2*ZB2*sinPhi*sinTheta - M3*XB3*ZB3*sinPhi*sinTheta - M3*pow(ds,2)*cosAlphaL*cosB*sinB*cosTheta + M2*pow(ds,2)*cosAlphaR*cosB*sinB*cosTheta - Iyy3*cosB*cosPhi*sinAlphaL*sinB*sinTheta + Iyy2*cosB*cosPhi*sinAlphaR*sinB*sinTheta + Izz3*cosB*cosPhi*sinAlphaL*sinB*sinTheta - Izz2*cosB*cosPhi*sinAlphaR*sinB*sinTheta + M3*YB3*ds*cosAlphaL*cosB*cosTheta + M2*YB2*ds*cosAlphaR*cosB*cosTheta + 2*Iyy3*cosAlphaL*cosB*pow(cosPhi,2)*sinB*cosTheta - 2*Iyy2*cosAlphaR*cosB*pow(cosPhi,2)*sinB*cosTheta - 2*Izz3*cosAlphaL*cosB*pow(cosPhi,2)*sinB*cosTheta + 2*Izz2*cosAlphaR*cosB*pow(cosPhi,2)*sinB*cosTheta - Iyy3*cosAlphaL*pow(cosB,2)*sinAlphaL*sinPhi*sinTheta - Iyy2*cosAlphaR*pow(cosB,2)*sinAlphaR*sinPhi*sinTheta + Izz3*cosAlphaL*pow(cosB,2)*sinAlphaL*sinPhi*sinTheta + Izz2*cosAlphaR*pow(cosB,2)*sinAlphaR*sinPhi*sinTheta + M2*XB2*ds*cosPhi*sinB*sinTheta - M3*XB3*ds*cosPhi*sinB*sinTheta + M2*pow(ds,2)*pow(cosB,2)*cosPhi*cosTheta*sinPhi + M3*pow(ds,2)*pow(cosB,2)*cosPhi*cosTheta*sinPhi + Iyy3*pow(cosAlphaL,2)*pow(cosB,2)*cosPhi*cosTheta*sinPhi + Iyy2*pow(cosAlphaR,2)*pow(cosB,2)*cosPhi*cosTheta*sinPhi - Izz3*pow(cosAlphaL,2)*pow(cosB,2)*cosPhi*cosTheta*sinPhi - Izz2*pow(cosAlphaR,2)*pow(cosB,2)*cosPhi*cosTheta*sinPhi - 2*M2*ZB2*ds*pow(cosPhi,2)*sinB*cosTheta + 2*M3*ZB3*ds*pow(cosPhi,2)*sinB*cosTheta + 2*M3*pow(ds,2)*cosAlphaL*cosB*pow(cosPhi,2)*sinB*cosTheta - 2*M2*pow(ds,2)*cosAlphaR*cosB*pow(cosPhi,2)*sinB*cosTheta - M3*XB3*ds*cosAlphaL*cosB*sinPhi*sinTheta - M2*XB2*ds*cosAlphaR*cosB*sinPhi*sinTheta + M3*YB3*ds*cosB*cosPhi*sinAlphaL*sinTheta + M2*YB2*ds*cosB*cosPhi*sinAlphaR*sinTheta - 2*M2*YB2*ds*cosPhi*sinB*cosTheta*sinPhi + 2*M3*YB3*ds*cosPhi*sinB*cosTheta*sinPhi - M3*ZB3*ds*cosB*sinAlphaL*sinPhi*sinTheta - M2*ZB2*ds*cosB*sinAlphaR*sinPhi*sinTheta - M3*pow(ds,2)*cosAlphaL*pow(cosB,2)*sinAlphaL*sinPhi*sinTheta - M2*pow(ds,2)*cosAlphaR*pow(cosB,2)*sinAlphaR*sinPhi*sinTheta - 2*M3*YB3*ds*cosAlphaL*cosB*pow(cosPhi,2)*cosTheta - 2*M2*YB2*ds*cosAlphaR*cosB*pow(cosPhi,2)*cosTheta + M3*pow(ds,2)*pow(cosAlphaL,2)*pow(cosB,2)*cosPhi*cosTheta*sinPhi + M2*pow(ds,2)*pow(cosAlphaR,2)*pow(cosB,2)*cosPhi*cosTheta*sinPhi - M3*pow(ds,2)*cosB*cosPhi*sinAlphaL*sinB*sinTheta + M2*pow(ds,2)*cosB*cosPhi*sinAlphaR*sinB*sinTheta + 2*M3*ZB3*ds*cosAlphaL*cosB*cosPhi*cosTheta*sinPhi + 2*M2*ZB2*ds*cosAlphaR*cosB*cosPhi*cosTheta*sinPhi, sinTheta*(Ixx1*sinTheta - Ixz1*cosPhi*cosTheta) + M1*pow((YB1*(cosPhi*cosPsi + sinPhi*sinPsi*sinTheta) - ZB1*(cosPsi*sinPhi - cosPhi*sinPsi*sinTheta) + XB1*cosTheta*sinPsi),2) + pow((ZB1*(sinPhi*sinPsi + cosPhi*cosPsi*sinTheta) - YB1*(cosPhi*sinPsi - cosPsi*sinPhi*sinTheta) + XB1*cosPsi*cosTheta),2) + Izz3*pow((cosB*sinAlphaL*sinTheta + sinB*cosTheta*sinPhi - cosAlphaL*cosB*cosPhi*cosTheta),2)
        + Izz2*pow((sinB*cosTheta*sinPhi - cosB*sinAlphaR*sinTheta + cosAlphaR*cosB*cosPhi*cosTheta),2) + M3*(pow((ZB3*(sinPhi*sinPsi + cosPhi*cosPsi*sinTheta) - YB3*(cosPhi*sinPsi - cosPsi*sinPhi*sinTheta) + ds*(sinB*(cosPhi*sinPsi - cosPsi*sinPhi*sinTheta) + cosAlphaL*cosB*(sinPhi*sinPsi + cosPhi*cosPsi*sinTheta) + cosB*cosPsi*sinAlphaL*cosTheta) + XB3*cosPsi*cosTheta),2) + pow((YB3*(cosPhi*cosPsi + sinPhi*sinPsi*sinTheta) - ZB3*(cosPsi*sinPhi - cosPhi*sinPsi*sinTheta) - ds*(sinB*(cosPhi*cosPsi + sinPhi*sinPsi*sinTheta) + cosAlphaL*cosB*(cosPsi*sinPhi - cosPhi*sinPsi*sinTheta) - cosB*sinAlphaL*cosTheta*sinPsi) + XB3*cosTheta*sinPsi),2)) + M2*(pow((ZB2*(sinPhi*sinPsi + cosPhi*cosPsi*sinTheta) - YB2*(cosPhi*sinPsi - cosPsi*sinPhi*sinTheta) + ds*(cosAlphaR*cosB*(sinPhi*sinPsi + cosPhi*cosPsi*sinTheta) - sinB*(cosPhi*sinPsi - cosPsi*sinPhi*sinTheta) + cosB*cosPsi*sinAlphaR*cosTheta) + XB2*cosPsi*cosTheta),2) + pow((YB2*(cosPhi*cosPsi + sinPhi*sinPsi*sinTheta) - ZB2*(cosPsi*sinPhi - cosPhi*sinPsi*sinTheta) + ds*(sinB*(cosPhi*cosPsi + sinPhi*sinPsi*sinTheta) - cosAlphaR*cosB*(cosPsi*sinPhi - cosPhi*sinPsi*sinTheta) + cosB*sinAlphaR*cosTheta*sinPsi) + XB2*cosTheta*sinPsi),2)) + Iyy3*pow((cosB*cosTheta*sinPhi - sinAlphaL*sinB*sinTheta + cosAlphaL*cosPhi*sinB*cosTheta),2) + Iyy2*pow((cosB*cosTheta*sinPhi + sinAlphaR*sinB*sinTheta - cosAlphaR*cosPhi*sinB*cosTheta),2) + Ixx3*pow((cosAlphaL*sinTheta + cosPhi*sinAlphaL*cosTheta),2) + Ixx2*pow((cosAlphaR*sinTheta + cosPhi*sinAlphaR*cosTheta),2) - cosPhi*cosTheta*(Ixz1*sinTheta - Izz1*cosPhi*cosTheta) + Iyy1*pow(cosTheta,2)*pow(sinPhi,2), - M3*(YB3*(cosPhi*cosPsi + sinPhi*sinPsi*sinTheta) - ZB3*(cosPsi*sinPhi - cosPhi*sinPsi*sinTheta) - ds*(sinB*(cosPhi*cosPsi + sinPhi*sinPsi*sinTheta) + cosAlphaL*cosB*(cosPsi*sinPhi - cosPhi*sinPsi*sinTheta) - cosB*sinAlphaL*cosTheta*sinPsi) + XB3*cosTheta*sinPsi) - M2*(YB2*(cosPhi*cosPsi + sinPhi*sinPsi*sinTheta) - ZB2*(cosPsi*sinPhi - cosPhi*sinPsi*sinTheta) + ds*(sinB*(cosPhi*cosPsi + sinPhi*sinPsi*sinTheta) - cosAlphaR*cosB*(cosPsi*sinPhi - cosPhi*sinPsi*sinTheta) + cosB*sinAlphaR*cosTheta*sinPsi) + XB2*cosTheta*sinPsi) - M1*(YB1*(cosPhi*cosPsi + sinPhi*sinPsi*sinTheta) - ZB1*(cosPsi*sinPhi - cosPhi*sinPsi*sinTheta) + XB1*cosTheta*sinPsi), M1*(ZB1*(sinPhi*sinPsi + cosPhi*cosPsi*sinTheta) - YB1*(cosPhi*sinPsi - cosPsi*sinPhi*sinTheta) + XB1*cosPsi*cosTheta) + M3*(ZB3*(sinPhi*sinPsi + cosPhi*cosPsi*sinTheta) - YB3*(cosPhi*sinPsi - cosPsi*sinPhi*sinTheta) + ds*(sinB*(cosPhi*sinPsi - cosPsi*sinPhi*sinTheta) + cosAlphaL*cosB*(sinPhi*sinPsi + cosPhi*cosPsi*sinTheta) + cosB*cosPsi*sinAlphaL*cosTheta) + XB3*cosPsi*cosTheta) + M2*(ZB2*(sinPhi*sinPsi + cosPhi*cosPsi*sinTheta) - YB2*(cosPhi*sinPsi - cosPsi*sinPhi*sinTheta) + ds*(cosAlphaR*cosB*(sinPhi*sinPsi + cosPhi*cosPsi*sinTheta) - sinB*(cosPhi*sinPsi - cosPsi*sinPhi*sinTheta) + cosB*cosPsi*sinAlphaR*cosTheta) + XB2*cosPsi*cosTheta), 0,
        M2*ds*cosAlphaR*cosB*cosPsi*cosTheta - M2*ds*cosB*sinAlphaR*(sinPhi*sinPsi + cosPhi*cosPsi*sinTheta), M3*ds*cosAlphaL*cosB*cosPsi*cosTheta - M3*ds*cosB*sinAlphaL*(sinPhi*sinPsi + cosPhi*cosPsi*sinTheta), M1*(YB1*(sinPhi*sinPsi + cosPhi*cosPsi*sinTheta) + ZB1*(cosPhi*sinPsi - cosPsi*sinPhi*sinTheta)) + M3*(YB3*(sinPhi*sinPsi + cosPhi*cosPsi*sinTheta) - ds*(sinB*(sinPhi*sinPsi + cosPhi*cosPsi*sinTheta) - cosAlphaL*cosB*(cosPhi*sinPsi - cosPsi*sinPhi*sinTheta)) + ZB3*(cosPhi*sinPsi - cosPsi*sinPhi*sinTheta)) + M2*(ds*(sinB*(sinPhi*sinPsi + cosPhi*cosPsi*sinTheta) + cosAlphaR*cosB*(cosPhi*sinPsi - cosPsi*sinPhi*sinTheta)) + YB2*(sinPhi*sinPsi + cosPhi*cosPsi*sinTheta) + ZB2*(cosPhi*sinPsi - cosPsi*sinPhi*sinTheta)), M1*cosPsi*(ZB1*cosPhi*cosTheta - XB1*sinTheta + YB1*cosTheta*sinPhi) - M3*cosPsi*(XB3*sinTheta - ZB3*cosPhi*cosTheta - YB3*cosTheta*sinPhi + ds*cosB*sinAlphaL*sinTheta + ds*sinB*cosTheta*sinPhi - ds*cosAlphaL*cosB*cosPhi*cosTheta) + M2*cosPsi*(ZB2*cosPhi*cosTheta - XB2*sinTheta + YB2*cosTheta*sinPhi - ds*cosB*sinAlphaR*sinTheta + ds*sinB*cosTheta*sinPhi + ds*cosAlphaR*cosB*cosPhi*cosTheta), - M3*(YB3*(cosPhi*cosPsi + sinPhi*sinPsi*sinTheta) - ZB3*(cosPsi*sinPhi - cosPhi*sinPsi*sinTheta) - ds*(sinB*(cosPhi*cosPsi + sinPhi*sinPsi*sinTheta) + cosAlphaL*cosB*(cosPsi*sinPhi - cosPhi*sinPsi*sinTheta) - cosB*sinAlphaL*cosTheta*sinPsi) + XB3*cosTheta*sinPsi) - M2*(YB2*(cosPhi*cosPsi + sinPhi*sinPsi*sinTheta) - ZB2*(cosPsi*sinPhi - cosPhi*sinPsi*sinTheta) + ds*(sinB*(cosPhi*cosPsi + sinPhi*sinPsi*sinTheta) - cosAlphaR*cosB*(cosPsi*sinPhi - cosPhi*sinPsi*sinTheta) + cosB*sinAlphaR*cosTheta*sinPsi) + XB2*cosTheta*sinPsi) - M1*(YB1*(cosPhi*cosPsi + sinPhi*sinPsi*sinTheta) - ZB1*(cosPsi*sinPhi - cosPhi*sinPsi*sinTheta) + XB1*cosTheta*sinPsi), M1 + M2 + M3, 0, 0,
        M2*ds*cosB*sinAlphaR*(cosPsi*sinPhi - cosPhi*sinPsi*sinTheta) + M2*ds*cosAlphaR*cosB*cosTheta*sinPsi, M3*ds*cosB*sinAlphaL*(cosPsi*sinPhi - cosPhi*sinPsi*sinTheta) + M3*ds*cosAlphaL*cosB*cosTheta*sinPsi, - M1*(YB1*(cosPsi*sinPhi - cosPhi*sinPsi*sinTheta) + ZB1*(cosPhi*cosPsi + sinPhi*sinPsi*sinTheta)) - M3*(YB3*(cosPsi*sinPhi - cosPhi*sinPsi*sinTheta) - ds*(sinB*(cosPsi*sinPhi - cosPhi*sinPsi*sinTheta) - cosAlphaL*cosB*(cosPhi*cosPsi + sinPhi*sinPsi*sinTheta)) + ZB3*(cosPhi*cosPsi + sinPhi*sinPsi*sinTheta)) - M2*(ds*(sinB*(cosPsi*sinPhi - cosPhi*sinPsi*sinTheta) + cosAlphaR*cosB*(cosPhi*cosPsi + sinPhi*sinPsi*sinTheta)) + YB2*(cosPsi*sinPhi - cosPhi*sinPsi*sinTheta) + ZB2*(cosPhi*cosPsi + sinPhi*sinPsi*sinTheta)), M1*sinPsi*(ZB1*cosPhi*cosTheta - XB1*sinTheta + YB1*cosTheta*sinPhi) - M3*sinPsi*(XB3*sinTheta - ZB3*cosPhi*cosTheta - YB3*cosTheta*sinPhi + ds*cosB*sinAlphaL*sinTheta + ds*sinB*cosTheta*sinPhi - ds*cosAlphaL*cosB*cosPhi*cosTheta) + M2*sinPsi*(ZB2*cosPhi*cosTheta - XB2*sinTheta + YB2*cosTheta*sinPhi - ds*cosB*sinAlphaR*sinTheta + ds*sinB*cosTheta*sinPhi + ds*cosAlphaR*cosB*cosPhi*cosTheta), M1*(ZB1*(sinPhi*sinPsi + cosPhi*cosPsi*sinTheta) - YB1*(cosPhi*sinPsi - cosPsi*sinPhi*sinTheta) + XB1*cosPsi*cosTheta) + M3*(ZB3*(sinPhi*sinPsi + cosPhi*cosPsi*sinTheta) - YB3*(cosPhi*sinPsi - cosPsi*sinPhi*sinTheta) + ds*(sinB*(cosPhi*sinPsi - cosPsi*sinPhi*sinTheta) + cosAlphaL*cosB*(sinPhi*sinPsi + cosPhi*cosPsi*sinTheta) + cosB*cosPsi*sinAlphaL*cosTheta) + XB3*cosPsi*cosTheta) + M2*(ZB2*(sinPhi*sinPsi + cosPhi*cosPsi*sinTheta) - YB2*(cosPhi*sinPsi - cosPsi*sinPhi*sinTheta) + ds*(cosAlphaR*cosB*(sinPhi*sinPsi + cosPhi*cosPsi*sinTheta) - sinB*(cosPhi*sinPsi - cosPsi*sinPhi*sinTheta) + cosB*cosPsi*sinAlphaR*cosTheta) + XB2*cosPsi*cosTheta), 0, M1 + M2 + M3, 0,
        -M2*ds*cosB*(cosAlphaR*sinTheta + cosPhi*sinAlphaR*cosTheta), -M3*ds*cosB*(cosAlphaL*sinTheta + cosPhi*sinAlphaL*cosTheta), M2*cosTheta*(YB2*cosPhi - ZB2*sinPhi + ds*cosPhi*sinB - ds*cosAlphaR*cosB*sinPhi) - M3*cosTheta*(ZB3*sinPhi - YB3*cosPhi + ds*cosPhi*sinB + ds*cosAlphaL*cosB*sinPhi) + M1*cosTheta*(YB1*cosPhi - ZB1*sinPhi), - M3*(XB3*cosTheta + ZB3*cosPhi*sinTheta + YB3*sinPhi*sinTheta - ds*sinB*sinPhi*sinTheta + ds*cosB*sinAlphaL*cosTheta + ds*cosAlphaL*cosB*cosPhi*sinTheta) - M2*(XB2*cosTheta + ZB2*cosPhi*sinTheta + YB2*sinPhi*sinTheta + ds*sinB*sinPhi*sinTheta + ds*cosB*sinAlphaR*cosTheta + ds*cosAlphaR*cosB*cosPhi*sinTheta) - M1*(XB1*cosTheta + ZB1*cosPhi*sinTheta + YB1*sinPhi*sinTheta), 0, 0, 0, M1 + M2 + M3;

return M;
      
}
