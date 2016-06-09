#ifndef _MATRIXES_H /* Include guard */
#define _MATRIXES_H
#include "userspace.h"
#include <stdio.h>
#include <math.h>

#define PI 3.141592653589793
#define toDeg(x) x*180/PI
#define toRad(x) x*PI/180



#define PHIW toRad(90)
#define OMEGA toRad(-90)
#define A1 40
#define A2 80
#define A3 -7.5
#define A4 0
#define A5 0
#define A6 0
#define D1 38
#define D2 0
#define D3 50
#define D4 55
#define D5 0
#define D6 32
#define LW 70
#define AW 30


extern double phi1;
extern double phi2;
extern double phi3;
extern double phi4;
extern double phi5;
extern double phi6;
extern double dhmatrix01[4][4];
extern double dhmatrix12[4][4];
extern double dhmatrix23[4][4];
extern double dhmatrix34[4][4];
extern double dhmatrix45[4][4];
extern double dhmatrix5TCP[4][4];
extern double dhmatrixTCPhilf[4][4];
extern double dhmatrixHilfEnd[4][4];
extern double dhmatrix0End[4][4];
extern double buffermatrix[4][4];
extern double buffermatrix2[4][4];
extern double dhmatrixEndTCP[4][4];
extern double ph1_inverse0[3][4];
extern double odd_inverse[3][4];
extern double even_inverse[3][4];
extern double inverse0[4][4];
void initdhmatrix01(double phi1);
void initdhmatrix12(double phi2);
void initdhmatrix23(double phi3);
void initdhmatrix34(double phi4);
void initdhmatrix45(double phi5);
void initdhmatrix5TCP(double phi6);
void initdhmatrixTCPhilf();
void initdhmatrixHilfEnd();
void initdhmatrixALL();
void matrixmultiplication(double matrix1[4][4], double matrix2[4][4], double buffermatrix[4][4]);
int gluInvertMatrix(double matrix[4][4], double invOut[4][4]);
void calc_Matrix_T_0_End();
void calc_Matrix_A_End_TCP();
void calc_first_Matrix_for_Angles();
void calc_second_Matrix_for_Angles(double previous_inverse[3][4], double angle);
void calc_third_Matrix_for_Angles(double previous_inverse[3][4], double angle);
void calc_fourth_Matrix_for_Angles(double previous_inverse[3][4], double angle);
#endif
