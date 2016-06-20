#include "matrixes.h"





 double ph1_inverse0[3][4];
 double even_inverse[3][4];
 double odd_inverse[3][4];
 double inverse0[4][4];

 




void calc_first_Matrix_for_Angles(double rotationUserMatrix[4][4])
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

