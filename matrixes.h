#ifndef _MATRIXES_H /* Include guard */
#define _MATRIXES_H




#define PHIW 90
#define OMEGA -90
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
#define PI 3.141593

extern double phi1;
extern double phi2;
extern  double phi3;
extern  double phi4;
extern  double phi5;
extern  double phi6;
extern double dhmatrix01[4][4];
extern double dhmatrix12[4][4];
extern double dhmatrix23[4][4];
extern double dhmatrix34[4][4];
extern double dhmatrix45[4][4];
extern double dhmatrix5TCP[4][4];
extern double dhmatrixTCPhilf[4][4];
extern double dhmatrixHilfEnd[4][4];
extern double buffermatrix[4][4];
extern double buffermatrix[4][4];
void initdhmatrix01();
void initdhmatrix12();
void initdhmatrix23();
void initdhmatrix34();
void initdhmatrix45();
void initdhmatrix5TCP();
void initdhmatrixTCPhilf();
void initdhmatrixHilfEnd();
void initdhmatrixALL();
void matrixmultiplication(double matrix1[4][4], double matrix2[4][4], double buffermatrix[4][4]);
int gluInvertMatrix(double matrix[4][4], double invOut[4][4]);
#endif
