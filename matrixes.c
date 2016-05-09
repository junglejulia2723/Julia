#include "matrixes.h"
#include <stdio.h>
#include <math.h>



 double dhmatrix01[4][4];
 double dhmatrix12[4][4];
 double dhmatrix23[4][4];
 double dhmatrix34[4][4];
 double dhmatrix45[4][4];
 double dhmatrix5TCP[4][4];
 double dhmatrixTCPhilf[4][4];
 double dhmatrixHilfEnd[4][4];
 double phi1= 162.60982*PI/180;
 double phi2=  -155.874949*PI/180;
 double phi3=  -115.915*PI/180;
 double phi4= -49.172*PI/180;
 double phi5= 40.102*PI/180;
 double phi6= -28.159*PI/180;
 
void initdhmatrix01(void)
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


void initdhmatrix12(void)
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
 
void initdhmatrix23(void)
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

void initdhmatrix34(void)
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

void initdhmatrix45(void)
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

void initdhmatrix5TCP(void)
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
     initdhmatrix01();
     initdhmatrix12();
     initdhmatrix23();
     initdhmatrix34();
     initdhmatrix45();
     initdhmatrix5TCP();
     initdhmatrixTCPhilf();
     initdhmatrixHilfEnd();
}

void matrixmultiplication(double matrix1[4][4], double matrix2[4][4], double buffermatrix[4][4])
{
       
       double sum=0;
      
       int i,j,k,x,y;
       
       for(i=0;i<=3;i++)
       {
          for(j=0;j<=3;j++)
          {
             for(k=0;k<=3;k++)
             {
                 sum+= matrix1[i][k]* matrix2[k][j];
               
             }
             buffermatrix[i][j]=sum;
          }
       }
       

   
}

int gluInvertMatrix(double matrix[4][4], double invOut[4][4])
{
    double inv[16], m[16], det;
    int i,x,y;
    i=0;
     for (x=0;x<4;x++)
     {
         for(y=0;y<4;y++)
         {
             m[i]= matrix[x][y];
             i++;
         }
     }   
        inv[0] = m[5]  * m[10] * m[15] - 
                 m[5]  * m[11] * m[14] - 
                 m[9]  * m[6]  * m[15] + 
                 m[9]  * m[7]  * m[14] +
                 m[13] * m[6]  * m[11] - 
                 m[13] * m[7]  * m[10];
    
        inv[4] = -m[4]  * m[10] * m[15] + 
                  m[4]  * m[11] * m[14] + 
                  m[8]  * m[6]  * m[15] - 
                  m[8]  * m[7]  * m[14] - 
                  m[12] * m[6]  * m[11] + 
                  m[12] * m[7]  * m[10];
    
        inv[8] = m[4]  * m[9] * m[15] - 
                 m[4]  * m[11] * m[13] - 
                 m[8]  * m[5] * m[15] + 
                 m[8]  * m[7] * m[13] + 
                 m[12] * m[5] * m[11] - 
                 m[12] * m[7] * m[9];
    
        inv[12] = -m[4]  * m[9] * m[14] + 
                   m[4]  * m[10] * m[13] +
                   m[8]  * m[5] * m[14] - 
                   m[8]  * m[6] * m[13] - 
                   m[12] * m[5] * m[10] + 
                   m[12] * m[6] * m[9];
    
        inv[1] = -m[1]  * m[10] * m[15] + 
                  m[1]  * m[11] * m[14] + 
                  m[9]  * m[2] * m[15] - 
                  m[9]  * m[3] * m[14] - 
                  m[13] * m[2] * m[11] + 
                  m[13] * m[3] * m[10];
    
        inv[5] = m[0]  * m[10] * m[15] - 
                 m[0]  * m[11] * m[14] - 
                 m[8]  * m[2] * m[15] + 
                 m[8]  * m[3] * m[14] + 
                 m[12] * m[2] * m[11] - 
                 m[12] * m[3] * m[10];
    
        inv[9] = -m[0]  * m[9] * m[15] + 
                  m[0]  * m[11] * m[13] + 
                  m[8]  * m[1] * m[15] - 
                  m[8]  * m[3] * m[13] - 
                  m[12] * m[1] * m[11] + 
                  m[12] * m[3] * m[9];
    
        inv[13] = m[0]  * m[9] * m[14] - 
                  m[0]  * m[10] * m[13] - 
                  m[8]  * m[1] * m[14] + 
                  m[8]  * m[2] * m[13] + 
                  m[12] * m[1] * m[10] - 
                  m[12] * m[2] * m[9];
    
        inv[2] = m[1]  * m[6] * m[15] - 
                 m[1]  * m[7] * m[14] - 
                 m[5]  * m[2] * m[15] + 
                 m[5]  * m[3] * m[14] + 
                 m[13] * m[2] * m[7] - 
                 m[13] * m[3] * m[6];
    
        inv[6] = -m[0]  * m[6] * m[15] + 
                  m[0]  * m[7] * m[14] + 
                  m[4]  * m[2] * m[15] - 
                  m[4]  * m[3] * m[14] - 
                  m[12] * m[2] * m[7] + 
                  m[12] * m[3] * m[6];
    
        inv[10] = m[0]  * m[5] * m[15] - 
                  m[0]  * m[7] * m[13] - 
                  m[4]  * m[1] * m[15] + 
                  m[4]  * m[3] * m[13] + 
                  m[12] * m[1] * m[7] - 
                  m[12] * m[3] * m[5];
    
        inv[14] = -m[0]  * m[5] * m[14] + 
                   m[0]  * m[6] * m[13] + 
                   m[4]  * m[1] * m[14] - 
                   m[4]  * m[2] * m[13] - 
                   m[12] * m[1] * m[6] + 
                   m[12] * m[2] * m[5];
    
        inv[3] = -m[1] * m[6] * m[11] + 
                  m[1] * m[7] * m[10] + 
                  m[5] * m[2] * m[11] - 
                  m[5] * m[3] * m[10] - 
                  m[9] * m[2] * m[7] + 
                  m[9] * m[3] * m[6];
    
        inv[7] = m[0] * m[6] * m[11] - 
                 m[0] * m[7] * m[10] - 
                 m[4] * m[2] * m[11] + 
                 m[4] * m[3] * m[10] + 
                 m[8] * m[2] * m[7] - 
                 m[8] * m[3] * m[6];
    
        inv[11] = -m[0] * m[5] * m[11] + 
                   m[0] * m[7] * m[9] + 
                   m[4] * m[1] * m[11] - 
                   m[4] * m[3] * m[9] - 
                   m[8] * m[1] * m[7] + 
                   m[8] * m[3] * m[5];
    
        inv[15] = m[0] * m[5] * m[10] - 
                  m[0] * m[6] * m[9] - 
                  m[4] * m[1] * m[10] + 
                  m[4] * m[2] * m[9] + 
                  m[8] * m[1] * m[6] - 
                  m[8] * m[2] * m[5];
    
        det = m[0] * inv[0] + m[1] * inv[4] + m[2] * inv[8] + m[3] * inv[12];
    
        if (det == 0)
            return 1;
    
        det = 1.0 / det;
        i=0;
        for (x=0;x<4;x++)
        {
          for(y=0;y<4;y++)
           {
            invOut[x][y] = inv[i] * det;
            i++;
           }
        }
        return 0;
}