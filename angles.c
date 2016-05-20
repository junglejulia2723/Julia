#include "angles.h"
#include "matrixes.h"
#include <math.h>

double check_Phi_range(double phi)
{
       if(phi>PI)
       {
            return phi-2*PI;          
       }
       if(phi<-PI)
       {
            return phi+2*PI;           
       }
       else
           return phi;
}

double phi1_solution2(double matrix[3][4])
{
       double a,b,phi,c=50;
        a=-(matrix[1][3])+ 32*matrix[1][2];
        b= matrix[0][3] - 32 * matrix[0][2];
        phi = check_Phi_range(atan2(c,(-1* sqrt(a*a + b*b - c*c))) - atan2(a,b));
        return phi;
}



double phi1_solution1(double matrix[3][4])
{
       double a,b,phi,c=50;
        a=-(matrix[1][3])+ 32*matrix[1][2];
        b= matrix[0][3] - 32 * matrix[0][2];
        phi = check_Phi_range(atan2(c, sqrt(a*a + b*b - c*c)) - atan2(a,b));
        return phi;
}

double phi2_solution2(double matrix[3][4])
{
       double a,b,phi,c;
        a=-matrix[1][2]*32+matrix[1][3];
        b=  32 * matrix[0][2]-matrix[0][3] ;
        c=(A3*A3+D4*D4-a*a-b*b-A2*A2)/(-2*A2);
        phi = check_Phi_range(atan2(c,(-1* sqrt(a*a + b*b - c*c))) - atan2(a,b));
        return phi;
}



double phi2_solution1(double matrix[3][4])
{
       double a,b,phi,c;
        a=-matrix[1][2]*32+matrix[1][3];
        b=  32 * matrix[0][2]-matrix[0][3] ;
        c=(A3*A3+D4*D4-a*a-b*b-A2*A2)/(-2*A2);
        printf("a=%f\n",a);
         printf("b=%f\n",b);
          printf("c=%f\n",c);
        phi = check_Phi_range(atan2(c, sqrt(a*a + b*b - c*c)) - atan2(a,b));
        return phi;
}


double phi3_solution2(double matrix[3][4])
{
       double a,b,phi,c;
        a= matrix[0][3]-32 * matrix[0][2];
        b=  matrix[1][3]-matrix[1][2]*32 ;
        c=(A3*A3+D4*D4-a*a-b*b-A2*A2)/(-2*A2);
        phi = check_Phi_range(atan2(c,(-1* sqrt(a*a + b*b - c*c))) - atan2(a,b));
        return phi;
}



double phi3_solution1(double matrix[3][4])
{
       double a,b,phi,c;
        a= matrix[0][3]-32 * matrix[0][2];
        b= matrix[1][3]-32*matrix[1][2] ;
        c=(A3*A3+D4*D4-a*a-b*b-A2*A2)/(-2*A2);
        printf("a=%f\n",a);
         printf("b=%f\n",b);
          printf("c=%f\n",c);
        phi = check_Phi_range(atan2(c, sqrt(a*a + b*b - c*c)) - atan2(a,b));
        return phi;
}
