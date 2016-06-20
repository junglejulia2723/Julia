#ifndef _USERSPACE_H /* Include guard */
#define _USERSPACE_H


#define PI 3.141592653589793
#define toRad(x) x*PI/180

extern double shiftWorkpiece_x;
extern double shiftWorkpiece_y;
extern double shiftWorkpiece_z;
extern double rotationWorkpiece_x;
extern double rotationWorkpiece_y;
extern double rotationWorkpiece_z;
extern double endeffector_x;
extern double endeffector_y;
extern double endeffector_z;
extern double orientationEndeffector_x;
extern double orientationEndeffector_y;
extern double orientationEndeffector_z;

extern double rotationWorkpieceMatrix[4][4];
extern double orientationTCP[4][4];
extern double tcp_to_base[4][4];
extern double workpiece_to_base[4][4];
extern double entered_orientation[4][4];
void initRotationMatrix(double a, double b, double c,double positionVectorX, double positionVectorY, double positionVectorZ,  double  matrix[4][4]);
void setOrientationTCP(double positionVectorX,double positionVectorY, double positionVectorZ);
#endif
