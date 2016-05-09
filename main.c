#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "matrixes.h"

double buffermatrix[4][4];
double buffermatrix2[4][4];
double buffermatrix3[4][4];
double inverse[4][4];
double inverse2[4][4];

int main(int argc, char *argv[])
{
   
    double a, b, c, i;
 
    double possibility1Phi1=0;
    double possibility2Phi1=0;
    int y,x, inversepossilbe=0;
 
      
      c=50;

  initdhmatrixALL();
 matrixmultiplication(dhmatrix01, dhmatrix12,buffermatrix);
  matrixmultiplication(buffermatrix, dhmatrix23,buffermatrix);
  matrixmultiplication(buffermatrix, dhmatrix34,buffermatrix);
  matrixmultiplication(buffermatrix, dhmatrix45,buffermatrix);
  matrixmultiplication(buffermatrix, dhmatrix5TCP,buffermatrix);
  matrixmultiplication(buffermatrix, dhmatrixTCPhilf,buffermatrix);
  matrixmultiplication(buffermatrix, dhmatrixHilfEnd,buffermatrix);
  matrixmultiplication(dhmatrixTCPhilf, dhmatrixHilfEnd,buffermatrix2); //A TCP END
  inversepossilbe= gluInvertMatrix(buffermatrix2,inverse);
 if(inversepossilbe!=0)printf("ALERT");
 //inversepossilbe= gluInvertMatrix(dhmatrix01,inverse2);
 //matrixmultiplication(invers2,buffermatrix2,buffermatrix2);
 matrixmultiplication( buffermatrix, inverse, buffermatrix3);
 
 for (x=0;x<4;x++)
 {
     for(y=0;y<4;y++)
     {
          printf("%.3f at m1 position %d %d\n",buffermatrix3[x][y]*180/PI,x,y);

                         
     }    
 }
 
 a=-(buffermatrix3[1][3])+ 32*buffermatrix3[1][2];
 b= buffermatrix3[3][0] - 32 * buffermatrix3 [0][2];
 
    possibility1Phi1 = atan2(c,(-1* sqrt(a*a + b*b - c*c))) - atan2(a,b);
    possibility2Phi1 = atan2(c, sqrt(a*a + b*b - c*c)) - atan2(a,b);
    printf("a= %.3f \n",a);
    printf("nr.1  %.3f \n", possibility1Phi1);
    printf("nr.2  %.3f \n", possibility2Phi1);
  printf("Hello world \n");
  system("PAUSE");	
  return 0;
}
