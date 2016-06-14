#ifndef _DHMATRIX_H
#define _DHMATRIX_H


extern double dhmatrix01[4][4];
extern double dhmatrix12[4][4];
extern double dhmatrix23[4][4];
extern double dhmatrix34[4][4];
extern double dhmatrix45[4][4];
extern double dhmatrix5TCP[4][4];
extern double dhmatrixTCPhilf[4][4];
extern double dhmatrixHilfEnd[4][4];
extern double dhmatrix0End[4][4];
extern double dhmatrixEndTCP[4][4];


extern double phi1;
extern double phi2;
extern double phi3;
extern double phi4;
extern double phi5;
extern double phi6;

void initdhmatrix01(double phi1);
void initdhmatrix12(double phi2);
void initdhmatrix23(double phi3);
void initdhmatrix34(double phi4);
void initdhmatrix45(double phi5);
void initdhmatrix5TCP(double phi6);
void initdhmatrixTCPhilf();
void initdhmatrixHilfEnd();
void initdhmatrixALL();
void calc_Matrix_T_0_End();
void calc_Matrix_A_End_TCP();

#endif
