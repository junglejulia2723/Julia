#include "userspace.h"
#include <math.h>


double endeffector_x =197;
double endeffector_y=-50;
double endeffector_z=80.5;

double shiftWorkpiece_x =30;
double shiftWorkpiece_y=90;
double shiftWorkpiece_z=10;
double rotationWorkpiece_x= toRad(90);
double rotationWorkpiece_y=toRad(0);
double rotationWorkpiece_z=toRad(0);
double rotationWorkpieceMatrix[4][4]; //Orientierung Werkstückkoordinatensystem
double orientationTCP[4][4]; //Orientierung TCP
double tcp_to_base[4][4];
double workpiece_to_base[4][4];//Werkstückkoorinaten in Basis
double entered_orientation[4][4];//Eingegebene Orientierung

void initRotationMatrix(double a, double b, double c, double positionVectorX, double positionVectorY, double positionVectorZ,double rotationMatrix[4][4])
{
     rotationMatrix[0][0]= cos(a)*cos(b);
     rotationMatrix[0][1]= -sin(a)*cos(c)-cos(a)*sin(b)*sin(c);
     rotationMatrix[0][2]= sin(a)*sin(c)-cos(a)*sin(b)*cos(c);
     rotationMatrix[0][3]= positionVectorX;
     rotationMatrix[1][0]= sin(a)*cos(b);
     rotationMatrix[1][1]= cos(a)*cos(c)-sin(a)*sin(b)*sin(c);
     rotationMatrix[1][2]= -cos(a)*sin(c)-sin(a)*sin(b)*cos(c);
     rotationMatrix[1][3]= positionVectorY;
     rotationMatrix[2][0]= sin(b);
     rotationMatrix[2][1]=cos(b)*sin(c);
     rotationMatrix[2][2]=cos(b)*cos(c);
     rotationMatrix[2][3]=positionVectorZ;
     rotationMatrix[3][0]=0;
     rotationMatrix[3][1]=0;
     rotationMatrix[3][2]=0;
     rotationMatrix[3][3]=1;

}
void setOrientationTCP(double positionVectorX,double positionVectorY, double positionVectorZ)
{
     orientationTCP[0][0]=0;
     orientationTCP[0][1]=-1;
     orientationTCP[0][2]= 6.1257*exp(-17);
     orientationTCP[0][3]=positionVectorX;
     orientationTCP[1][0]=-1;
     orientationTCP[1][1]=-3.7525*exp(-33);
     orientationTCP[1][2]= -6.1257*exp(-17);
     orientationTCP[1][3]= positionVectorY;
     orientationTCP[2][0]=6.1257*exp(-17);
     orientationTCP[2][1]=-6.1257*exp(-17);
     orientationTCP[2][2]= -1;
     orientationTCP[2][3]=  positionVectorZ;
     orientationTCP[3][0]=0;
     orientationTCP[3][1]=0;
     orientationTCP[3][2]=0;
     orientationTCP[3][3]=1;
     
}
