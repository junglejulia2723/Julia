#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#include "matrixes.h"
#include "angles.h"






double inverse[4][4];
double inverse2[4][4];


int main(int argc, char *argv[])
{
   
    double possibilities_phi1[2];//all possible angles are stored in arrays, could be changed to tree implementation
    double possibilities_phi2[4];
    double possibilities_phi3[8];
    int y,x, inversepossilbe=0;
   

      initdhmatrixALL();
      calc_Matrix_T_0_End();
      calc_Matrix_A_End_TCP();
      
      if(gluInvertMatrix(dhmatrixEndTCP,inverse)!=0)printf("ALERT");
      
      matrixmultiplication(dhmatrix0End,inverse,inverse0);//Matrix für Phi1, achtung im Excel sheet ist die letzte Spalte an erster Stelle
      
      initRotationMatrix(rotationA, rotationB, rotationC,  positionVectorX,  positionVectorY, positionVectorZ, rotationUserMatrix);
      /* needed if other coordinate system is used
      initRotationMatrix(rotationWorkpiece_x,rotationWorkpiece_y,rotationWorkpiece_z, shiftWorkpiece_x,shiftWorkpiece_y,shiftWorkpiece_z,rotationWorkpieceMatrix);
      setOrientationTCP();
      matrixmultiplication( rotationWorkpieceMatrix,rotationUserMatrix, workpiece_to_base);
      matrixmultiplication(orientationTCP, rotationUserMatrix, entered_orientation);
    */
     calc_first_Matrix_for_Angles();
     
         possibilities_phi1[0] = phi1_solution1(ph1_inverse0);
         possibilities_phi1[1]= phi1_solution2(ph1_inverse0);
         calc_odd_Matrix_for_Angles(ph1_inverse0,possibilities_phi1[0]);
         possibilities_phi2[0] = phi2_solution1(odd_inverse);
         possibilities_phi2[1] = phi2_solution2(odd_inverse);
         calc_even_Matrix_for_Angles(odd_inverse,possibilities_phi2[0]);
         possibilities_phi3[0] = phi2_solution1(even_inverse);
         possibilities_phi3[1] = phi2_solution2(even_inverse);
         printf("nr.1  %f \n", possibilities_phi3[0]);
         printf("nr.2  %f \n", possibilities_phi3[1]);
         printf("nr.1  %.3f \n", toDeg(possibilities_phi3[0]));
         printf("nr.2  %.3f \n", toDeg( possibilities_phi3[1]));

         for (x=0;x<3;x++)
         {
             for(y=0;y<4;y++)
             {
                  printf("%f at m1 position %d %d\n", even_inverse[x][y],x,y);                  
             }    
         }
       
     
        printf("Hello world \n");
        system("PAUSE");	
        return 0;
}
