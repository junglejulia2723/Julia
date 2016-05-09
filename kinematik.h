#ifndef _KINEMATIK_H /* Include guard */
#define _KINEMATIK_H


 
#define PHI3 -115.914843
#define PHI4 -49.1720569
#define PHI5 40.102183
#define PHI6 -28,1593876
#define PHIOMEGA 90
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

extern double phi1;
extern double phi2;
extern double dhmatrix01[4][4];
extern double dhmatrix12[4][4];
void initdhmatrix01();
void initdhmatrix12();
#endif
