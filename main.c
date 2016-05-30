#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#include "matrixes.h"
#include "angles.h"
#include "userspace.h"






double inverse[4][4];
double inverse2[4][4];


int main(int argc, char *argv[])
{
   
    double possibilities_phi1[2];//all possible angles are stored in arrays, could be changed to tree implementation
    double possibilities_phi2[4];
    double possibilities_phi3[8];
    double possibilities_phi4[16];
    double possibilities_phi5[32];
    double possibilities_phi6[32];
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
         calc_second_Matrix_for_Angles(ph1_inverse0,possibilities_phi1[0]);
         possibilities_phi2[0] = phi2_solution1(odd_inverse);
         possibilities_phi2[1] = phi2_solution2(odd_inverse);
         calc_third_Matrix_for_Angles(odd_inverse,possibilities_phi2[0]);
         possibilities_phi3[0] = phi3_solution1(even_inverse);
         possibilities_phi3[1] = phi3_solution2(even_inverse);
         calc_fourth_Matrix_for_Angles(even_inverse,possibilities_phi3[0]);
         possibilities_phi4[0]= phi4_solution1(even_inverse,possibilities_phi3[0]);
         possibilities_phi4[1] = phi4_solution2(possibilities_phi4[0]);
         possibilities_phi5[0]= phi5_solution1(odd_inverse,possibilities_phi4[0]);
         possibilities_phi5[1] = phi5_solution2(possibilities_phi5[0]);
         possibilities_phi5[2]= phi5_solution1(odd_inverse,possibilities_phi4[1]);
         possibilities_phi5[3] = phi5_solution2(possibilities_phi5[2]);
         possibilities_phi6[0]= phi6_solution1(odd_inverse,possibilities_phi4[0]);
         possibilities_phi6[1] = phi6_solution2(possibilities_phi6[0]);
         possibilities_phi6[2]= phi6_solution1(odd_inverse,possibilities_phi4[1]);
         possibilities_phi6[3] = phi6_solution2(possibilities_phi6[2]);
         calc_fourth_Matrix_for_Angles(even_inverse,possibilities_phi3[1]);
		 possibilities_phi4[2]= phi4_solution1(even_inverse,possibilities_phi3[1]);
         possibilities_phi4[3] = phi4_solution2(possibilities_phi4[2]);
         possibilities_phi5[4]= phi5_solution1(odd_inverse,possibilities_phi4[2]);
         possibilities_phi5[5] = phi5_solution2(possibilities_phi5[4]);
         possibilities_phi5[6]= phi5_solution1(odd_inverse,possibilities_phi4[3]);
         possibilities_phi5[7] = phi5_solution2(possibilities_phi5[6]);
         possibilities_phi6[4]= phi6_solution1(odd_inverse,possibilities_phi4[2]);
         possibilities_phi6[5] = phi6_solution2(possibilities_phi6[4]);
         possibilities_phi6[6]= phi6_solution1(odd_inverse,possibilities_phi4[3]);
         possibilities_phi6[7] = phi6_solution2(possibilities_phi6[6]);
         calc_first_Matrix_for_Angles();
         calc_second_Matrix_for_Angles(ph1_inverse0,possibilities_phi1[0]);
         calc_third_Matrix_for_Angles(odd_inverse,possibilities_phi2[1]);
         possibilities_phi3[2] = phi3_solution1(even_inverse);
         possibilities_phi3[3] = phi3_solution2(even_inverse);
         calc_fourth_Matrix_for_Angles(even_inverse,possibilities_phi3[2]);
         possibilities_phi4[4]= phi4_solution1(even_inverse,possibilities_phi3[2]);
         possibilities_phi4[5] = phi4_solution2(possibilities_phi4[4]);
         possibilities_phi5[8]= phi5_solution1(odd_inverse,possibilities_phi4[4]);
         possibilities_phi5[9] = phi5_solution2(possibilities_phi5[8]);
         possibilities_phi5[10]= phi5_solution1(odd_inverse,possibilities_phi4[5]);
         possibilities_phi5[11] = phi5_solution2(possibilities_phi5[10]);
         possibilities_phi6[8]= phi6_solution1(odd_inverse,possibilities_phi4[4]);
         possibilities_phi6[9] = phi6_solution2(possibilities_phi6[8]);
         possibilities_phi6[10]= phi6_solution1(odd_inverse,possibilities_phi4[5]);
         possibilities_phi6[11] = phi6_solution2(possibilities_phi6[10]);
         calc_fourth_Matrix_for_Angles(even_inverse,possibilities_phi3[3]);
         possibilities_phi4[6]= phi4_solution1(even_inverse,possibilities_phi3[3]);
         possibilities_phi4[7] = phi4_solution2(possibilities_phi4[6]);
         possibilities_phi5[12]= phi5_solution1(odd_inverse,possibilities_phi4[6]);
         possibilities_phi5[13] = phi5_solution2(possibilities_phi5[12]);
         possibilities_phi5[14]= phi5_solution1(odd_inverse,possibilities_phi4[7]);
         possibilities_phi5[15] = phi5_solution2(possibilities_phi5[14]);
         possibilities_phi6[12]= phi6_solution1(odd_inverse,possibilities_phi4[6]);
         possibilities_phi6[13] = phi6_solution2(possibilities_phi6[12]);
         possibilities_phi6[14]= phi6_solution1(odd_inverse,possibilities_phi4[7]);
         possibilities_phi6[15] = phi6_solution2(possibilities_phi6[14]);
         printf("nr.9  %f \n", possibilities_phi6[12]);
         printf("nr.10  %f \n", possibilities_phi6[13]);
         //next calc Phi1-2 matrix
        
     
        
       //system("PAUSE");	
        return 0;
}
