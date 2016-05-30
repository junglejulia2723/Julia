#include "matrixes.h"




 double dhmatrix01[4][4];
 double dhmatrix12[4][4];
 double dhmatrix23[4][4];
 double dhmatrix34[4][4];
 double dhmatrix45[4][4];
 double dhmatrix5TCP[4][4];
 double dhmatrixTCPhilf[4][4];
 double dhmatrixHilfEnd[4][4];
 double dhmatrix0End[4][4];
 double buffermatrix[4][4];
 double buffermatrix2[4][4];
 double dhmatrixEndTCP[4][4];
 double ph1_inverse0[3][4];
 double even_inverse[3][4];
 double odd_inverse[3][4];
 double inverse0[4][4];
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
             sum=0;
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

void calc_first_Matrix_for_Angles()
{
     ph1_inverse0[0][0]=cos(PHIW)*rotationUserMatrix[0][0] + sin(PHIW)*(rotationUserMatrix[0][2]*sin(OMEGA)-rotationUserMatrix[0][1]*cos(OMEGA));
     ph1_inverse0[0][1]= sin(PHIW)*rotationUserMatrix[0][0]+ cos(PHIW)*(-rotationUserMatrix[0][2]*sin(OMEGA)+rotationUserMatrix[0][1]*cos(OMEGA));
     ph1_inverse0[0][2]=rotationUserMatrix[0][2]*cos(OMEGA)+rotationUserMatrix[0][1]*sin(OMEGA);
     ph1_inverse0[0][3]=rotationUserMatrix[0][3]-AW*rotationUserMatrix[0][2]-LW*(rotationUserMatrix[0][2]*cos(OMEGA)+rotationUserMatrix[0][1]*sin(OMEGA));
     ph1_inverse0[1][0]=cos(PHIW)*rotationUserMatrix[1][0]+sin(PHIW)*(rotationUserMatrix[1][2]*sin(OMEGA)-rotationUserMatrix[1][1]*cos(OMEGA));
     ph1_inverse0[1][1]=sin(PHIW)*rotationUserMatrix[1][0]+cos(PHIW)*(-rotationUserMatrix[1][2]*sin(OMEGA)+rotationUserMatrix[1][1]*cos(OMEGA));
     ph1_inverse0[1][2]=rotationUserMatrix[1][2]*cos(OMEGA)+rotationUserMatrix[1][1]*sin(OMEGA);
     ph1_inverse0[1][3]=rotationUserMatrix[1][3]-AW*rotationUserMatrix[1][2]-LW*(rotationUserMatrix[1][2]*cos(OMEGA)+rotationUserMatrix[1][1]*sin(OMEGA));
     ph1_inverse0[2][0]=cos(PHIW)*rotationUserMatrix[2][0]+sin(PHIW)*(rotationUserMatrix[2][2]*sin(OMEGA)-rotationUserMatrix[2][1]*cos(OMEGA));
     ph1_inverse0[2][1]=sin(PHIW)*rotationUserMatrix[2][0]+cos(PHIW)*(-rotationUserMatrix[2][2]*sin(OMEGA)+rotationUserMatrix[2][1]*cos(OMEGA));
     ph1_inverse0[2][2]=rotationUserMatrix[2][2]*cos(OMEGA)+rotationUserMatrix[2][1]*sin(OMEGA);
     ph1_inverse0[2][3]=rotationUserMatrix[2][3]-AW*rotationUserMatrix[2][2]-LW*(rotationUserMatrix[2][2]*cos(OMEGA)+rotationUserMatrix[2][1]*sin(OMEGA));
   
}

void calc_second_Matrix_for_Angles(double previous_inverse[3][4], double angle)
{
      odd_inverse[0][0]= previous_inverse[0][0]*cos(angle)+previous_inverse[1][0]*sin(angle);
      odd_inverse[0][1]= previous_inverse[0][1]*cos(angle)+previous_inverse[1][1]*sin(angle);
      odd_inverse[0][2]= previous_inverse[0][2]*cos(angle)+previous_inverse[1][2]*sin(angle);
      odd_inverse[0][3]= previous_inverse[0][3]*cos(angle)+previous_inverse[1][3]*sin(angle)-A1;
      odd_inverse[1][0]= previous_inverse[2][0];
      odd_inverse[1][1]= previous_inverse[2][1];
      odd_inverse[1][2]= previous_inverse[2][2];
      odd_inverse[1][3]= previous_inverse[2][3]-D1;
      odd_inverse[2][0]= previous_inverse[0][0]*sin(angle)-previous_inverse[1][0]*cos(angle);
      odd_inverse[2][1]= previous_inverse[0][1]*sin(angle)-previous_inverse[1][1]*cos(angle);
      odd_inverse[2][2]= previous_inverse[0][2]*sin(angle)-previous_inverse[1][2]*cos(angle);
      odd_inverse[2][3]= previous_inverse[0][3]*sin(angle)-previous_inverse[1][3]*cos(angle);
}

void calc_third_Matrix_for_Angles(double previous_inverse[3][4], double angle)
{
      even_inverse[0][0]= previous_inverse[1][0]*cos(angle)-previous_inverse[0][0]*sin(angle);
      even_inverse[0][1]= previous_inverse[1][1]*cos(angle)-previous_inverse[0][1]*sin(angle);
      even_inverse[0][2]= previous_inverse[1][2]*cos(angle)-previous_inverse[0][2]*sin(angle);
      even_inverse[0][3]= previous_inverse[1][3]*cos(angle)-previous_inverse[0][3]*sin(angle)-A2;
      even_inverse[1][0]= -previous_inverse[1][0]*sin(angle)-previous_inverse[0][0]*cos(angle);
      even_inverse[1][1]= -previous_inverse[0][1]*cos(angle)-previous_inverse[1][1]*sin(angle);
      even_inverse[1][2]= -previous_inverse[0][2]*cos(angle)-previous_inverse[1][2]*sin(angle);
      even_inverse[1][3]= -previous_inverse[0][3]*cos(angle)-previous_inverse[1][3]*sin(angle);
      even_inverse[2][0]= previous_inverse[2][0];
      even_inverse[2][1]= previous_inverse[2][1];
      even_inverse[2][2]= previous_inverse[2][2];
      even_inverse[2][3]= previous_inverse[2][3];  
     
}

void calc_fourth_Matrix_for_Angles(double previous_inverse[3][4], double angle)
{
 		odd_inverse[0][0]= previous_inverse[0][0]*cos(angle)+previous_inverse[1][0]*sin(angle);
      odd_inverse[0][1]= previous_inverse[0][1]*cos(angle)+previous_inverse[1][1]*sin(angle);
      odd_inverse[0][2]= previous_inverse[0][2]*cos(angle)+previous_inverse[1][2]*sin(angle);
      odd_inverse[0][3]= previous_inverse[0][3]*cos(angle)+previous_inverse[1][3]*sin(angle)-A3;
      odd_inverse[1][0]= previous_inverse[2][0];
      odd_inverse[1][1]= previous_inverse[2][1];
      odd_inverse[1][2]= previous_inverse[2][2];
      odd_inverse[1][3]= previous_inverse[2][3]-D3;
      odd_inverse[2][0]= previous_inverse[0][0]*sin(angle)-previous_inverse[1][0]*cos(angle);
      odd_inverse[2][1]= previous_inverse[0][1]*sin(angle)-previous_inverse[1][1]*cos(angle);
      odd_inverse[2][2]= previous_inverse[0][2]*sin(angle)-previous_inverse[1][2]*cos(angle);
      odd_inverse[2][3]= previous_inverse[0][3]*sin(angle)-previous_inverse[1][3]*cos(angle);
}

