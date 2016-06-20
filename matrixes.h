#ifndef _MATRIXES_H 
#define _MATRIXES_H
#include "userspace.h"
#include <stdio.h>
#include <math.h>

#define PI 3.141592653589793
#define toDeg(x) x*180/PI
#define toRad(x) x*PI/180



#define PHIW toRad(90) //Drehwinkel um die Achse 6
#define OMEGA toRad(-90) // Drehwinkel um die x-Achse des Endeffktors

#define A1 40 //Normalabstand zwischen Achse 1 und Achse 2 entlang der x-Achse des Basiskoordinatensystems gemessen
#define A2 80 //Normalabstand zwischen Achse 2 und Achse 3 entlang der z-Achse des Basiskoordinatensystems gemessen
#define A3 -7.5 //Normalabstand zwischen Achse 3 und Achse 4 entlang der z-Achse des Basiskoordinatensystems gemessen

#define D1 38 //Normalabstand zwischen Achse 1 und Achse 2 entlang der z-Achse des Basiskoordinatensystems gemessen

#define D3 50 //Normalabstand zwischen der xz-Ebene des Basiskoordinatensystems und der Achse 4 gemessen entlang der y-Aches des Basiskoordinatensystems
#define D4 55 //Normalabstand zwischen Achse 4 und Achse 5 gemessen entlang der x Achse des Basiskoordinatensystems

#define D6 32 // Normalabstand zwischen Achse 5 und dem TCP entlang der x-Achse des Basiskoordinatensystems
#define LW 70 // Normalabstand zwischen TCP und Endeffektor
#define AW 30 //Normalabstand zwischen Achse 6 und Spitze des Endeffektors





extern double ph1_inverse0[3][4];
extern double odd_inverse[3][4];
extern double even_inverse[3][4];
extern double inverse0[4][4];


void calc_Matrix_T_0_End();
void calc_Matrix_A_End_TCP();
void calc_first_Matrix_for_Angles(double matrix[4][4]);
void calc_second_Matrix_for_Angles(double previous_inverse[3][4], double angle);
void calc_third_Matrix_for_Angles(double previous_inverse[3][4], double angle);
void calc_fourth_Matrix_for_Angles(double previous_inverse[3][4], double angle);
#endif
