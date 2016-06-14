 #include "dhmatrix.h"
 #include "matrixes.h"
 #include <math.h>
 
 double dhmatrix01[4][4];
 double dhmatrix12[4][4];
 double dhmatrix23[4][4];
 double dhmatrix34[4][4];
 double dhmatrix45[4][4];
 double dhmatrix5TCP[4][4];
 double dhmatrixTCPhilf[4][4];
 double dhmatrixHilfEnd[4][4];
 double dhmatrix0End[4][4];
 double dhmatrixEndTCP[4][4];
 
 double phi1= 0;
 double phi2= 0;
 double phi3= 0;
 double phi4= 0;
 double phi5= 0;
 double phi6= 0;
 
 void initdhmatrix01(double phi1)
{
   dhmatrix01[0][0]=cos(phi1);
   dhmatrix01[0][1]=0;
   dhmatrix01[0][2]=sin(phi1);
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


void initdhmatrix12(double phi2)
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
 
void initdhmatrix23(double phi3)
{
   dhmatrix23[0][0]= cos(phi3);
   dhmatrix23[0][1]= 0;
   dhmatrix23[0][2]= sin(phi3);
   dhmatrix23[0][3]= A3*cos(phi3);  
   dhmatrix23[1][0]= sin(phi3);
   dhmatrix23[1][1]= 0;
   dhmatrix23[1][2]= -cos(phi3);
   dhmatrix23[1][3]= A3*sin(phi3);
   dhmatrix23[2][0]= 0;
   dhmatrix23[2][1]= 1;
   dhmatrix23[2][2]= 0;
   dhmatrix23[2][3]= D3;
   dhmatrix23[3][0]= 0;
   dhmatrix23[3][1]= 0;
   dhmatrix23[3][2]= 0;
   dhmatrix23[3][3]= 1;
}

void initdhmatrix34(double phi4)
{
     dhmatrix34[0][0]= cos(phi4);
     dhmatrix34[0][1]= 0;
     dhmatrix34[0][2]= -sin(phi4);
     dhmatrix34[0][3]= 0;
     dhmatrix34[1][0]=  sin(phi4);
     dhmatrix34[1][1]= 0;
     dhmatrix34[1][2]= cos(phi4);
     dhmatrix34[1][3]= 0;
     dhmatrix34[2][0]= 0;
     dhmatrix34[2][1]= -1;
     dhmatrix34[2][2]= 0;
     dhmatrix34[2][3]= D4;
     dhmatrix34[3][0]= 0;
     dhmatrix34[3][1]= 0;
     dhmatrix34[3][2]= 0;
     dhmatrix34[3][3]= 1;
     
}

void initdhmatrix45(double phi5)
{
      dhmatrix45[0][0]= cos(phi5);
      dhmatrix45[0][1]= 0;
      dhmatrix45[0][2]= sin(phi5);
      dhmatrix45[0][3]= 0;
      dhmatrix45[1][0]= sin(phi5);
      dhmatrix45[1][1]= 0;
      dhmatrix45[1][2]= -cos(phi5);
      dhmatrix45[1][3]= 0;
      dhmatrix45[2][0]= 0;
      dhmatrix45[2][1]= 1;
      dhmatrix45[2][2]= 0;
      dhmatrix45[2][3]= 0; 
      dhmatrix45[3][0]= 0;
      dhmatrix45[3][1]= 0;
      dhmatrix45[3][2]= 0;
      dhmatrix45[3][3]= 1;
}

void initdhmatrix5TCP(double phi6)
{
     dhmatrix5TCP[0][0]= cos(phi6);
     dhmatrix5TCP[0][1]= -sin(phi6);
     dhmatrix5TCP[0][2]= 0;
     dhmatrix5TCP[0][3]= 0;
     dhmatrix5TCP[1][0]= sin(phi6);
     dhmatrix5TCP[1][1]= cos(phi6);
     dhmatrix5TCP[1][2]= 0;
     dhmatrix5TCP[1][3]= 0;
     dhmatrix5TCP[2][0]= 0;
     dhmatrix5TCP[2][1]= 0;
     dhmatrix5TCP[2][2]= 1;
     dhmatrix5TCP[2][3]= D6;
     dhmatrix5TCP[3][0]= 0;
     dhmatrix5TCP[3][1]= 0;
     dhmatrix5TCP[3][2]= 0;
     dhmatrix5TCP[3][3]= 1;
}

void initdhmatrixTCPhilf(void)
{
     dhmatrixTCPhilf[0][0]= cos(PHIW);
     dhmatrixTCPhilf[0][1]= -sin(PHIW)*cos(OMEGA);
     dhmatrixTCPhilf[0][2]= sin(PHIW)*sin(OMEGA);
     dhmatrixTCPhilf[0][3]= 0;
     dhmatrixTCPhilf[1][0]= sin(PHIW);
     dhmatrixTCPhilf[1][1]= cos(PHIW)*cos(OMEGA);
     dhmatrixTCPhilf[1][2]= -cos(PHIW)*sin(OMEGA);
     dhmatrixTCPhilf[1][3]=0;
     dhmatrixTCPhilf[2][0]= 0;
     dhmatrixTCPhilf[2][1]= sin(OMEGA);
     dhmatrixTCPhilf[2][2]= cos(OMEGA);
     dhmatrixTCPhilf[2][3]= LW;
     dhmatrixTCPhilf[3][0]= 0;
     dhmatrixTCPhilf[3][1]= 0;
     dhmatrixTCPhilf[3][2]= 0;
     dhmatrixTCPhilf[3][3]= 1;
         
}

void initdhmatrixHilfEnd(void)
{
     dhmatrixHilfEnd[0][0]= cos(PHIW);
     dhmatrixHilfEnd[0][1]= -sin(PHIW)*cos(OMEGA);
     dhmatrixHilfEnd[0][2]= sin(PHIW)*sin(OMEGA);
     dhmatrixHilfEnd[0][3]= AW * cos(PHIW);
     dhmatrixHilfEnd[1][0]=  sin(PHIW);
     dhmatrixHilfEnd[1][1]= cos(PHIW)*cos(OMEGA);
     dhmatrixHilfEnd[1][2]= -cos(PHIW)*sin(OMEGA);
     dhmatrixHilfEnd[1][3]= AW * sin(PHIW);
     dhmatrixHilfEnd[2][0]= 0;
     dhmatrixHilfEnd[2][1]= sin(OMEGA);
     dhmatrixHilfEnd[2][2]= cos(OMEGA);
     dhmatrixHilfEnd[2][3]= LW;
     dhmatrixHilfEnd[3][0]= 0;
     dhmatrixHilfEnd[3][1]= 0;
     dhmatrixHilfEnd[3][2]= 0;
     dhmatrixHilfEnd[3][3]= 1;
}

void initdhmatrixALL(void)
{
     initdhmatrix01(phi1);
     initdhmatrix12(phi2);
     initdhmatrix23(phi3);
     initdhmatrix34(phi4);
     initdhmatrix45(phi5);
     initdhmatrix5TCP(phi6);
     initdhmatrixTCPhilf();
     initdhmatrixHilfEnd();
}

void calc_Matrix_T_0_End()
{
      matrixmultiplication(dhmatrix01, dhmatrix12,buffermatrix);
      matrixmultiplication(buffermatrix, dhmatrix23,buffermatrix2);
      matrixmultiplication(buffermatrix2, dhmatrix34,buffermatrix);
      matrixmultiplication(buffermatrix, dhmatrix45,buffermatrix2);
      matrixmultiplication(buffermatrix2, dhmatrix5TCP,buffermatrix);
      matrixmultiplication(buffermatrix, dhmatrixTCPhilf,buffermatrix2);
      matrixmultiplication(buffermatrix2, dhmatrixHilfEnd,dhmatrix0End);//T 0 End
     
}

void calc_Matrix_A_End_TCP()
{
     matrixmultiplication(dhmatrixTCPhilf, dhmatrixHilfEnd ,dhmatrixEndTCP); //A TCP END
}

