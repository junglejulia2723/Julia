#include "kinematik.h"



 double dhmatrix01[4][4];
 double dhmatrix12[4][4];
 double phi1= 162.60982;
 double phi2=  -155.874949;
 
void initdhmatrix01()
{
   dhmatrix01[0][0]=cos(phi1);
   dhmatrix01[0][1]=0;
   dhmatrix01[0][2] = sin(phi1);
   dhmatrix01[0][3] = A1 * cos(phi1);
   dhmatrix01[1][0]=sin(phi1);
   dhmatrix01[1][1]= 0;
   dhmatrix01[1][2]= -cos(phi1);
   dhmatrix01[1][3]= A1 * sin(phi1);
   dhmatrix01[2][0]=0;
   dhmatrix01[2][1]=1;
   dhmatrix01[2][2]=0;
   dhmatrix01[2][3]=D1;
   dhmatrix01[3][0]=0;
   dhmatrix01[3][1]=0;
   dhmatrix01[3][2]=0;
   dhmatrix01[3][3]=1;
}


void initdhmatrix12()
{
   dhmatrix12[0][0]= -sin(phi2);
   dhmatrix12[0][1]= -cos(phi2);
   dhmatrix12[0][2] = 0;
   dhmatrix12[0][3] = -A2*sin(phi2);
   dhmatrix12[1][0]=cos(phi2);
   dhmatrix12[1][1]=-sin(phi2);
   dhmatrix12[1][2]= 0;
   dhmatrix12[1][3]=A2*cos(phi2);
   dhmatrix12[2][0]=0;
   dhmatrix12[2][1]=0;
   dhmatrix12[2][2]=1;
   dhmatrix12[2][3]=0;
   dhmatrix12[3][0]=0;
   dhmatrix12[3][1]=0;
   dhmatrix12[3][2]=0;
   dhmatrix12[3][3]=1;
}
 

