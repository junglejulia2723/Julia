#include "angles.h"
#include "matrixes.h"
#include <math.h>
#include <stdio.h>

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

double check_min_max(double angle)
{
	if(angle>=toRad(-180) && angle<=toRad(180))
	{
		return angle;
	}
	
	else
	{
		return 0;
	}
}


double phi1_solution2(double matrix[3][4])
{
       double a,b,phi,c=50;
        a=-(matrix[1][3])+ 32*matrix[1][2];
        b= matrix[0][3] - 32 * matrix[0][2];
        phi = check_Phi_range(atan2(c,(-1* sqrt(a*a + b*b - c*c))) - atan2(a,b));
        phi=check_min_max(phi);
        return phi;
}



double phi1_solution1(double matrix[3][4])
{
       double a,b,phi,c=50;
        a=-(matrix[1][3])+ 32*matrix[1][2];
        b= matrix[0][3] - 32 * matrix[0][2];
        phi = check_Phi_range(atan2(c, sqrt(a*a + b*b - c*c)) - atan2(a,b));
       	 phi=check_min_max(phi);
	    return phi;
}

double phi2_solution2(double matrix[3][4])
{
       double a,b,phi,c;
        a=-matrix[1][2]*32+matrix[1][3];
        b=  32 * matrix[0][2]-matrix[0][3] ;
        c=(A3*A3+D4*D4-a*a-b*b-A2*A2)/(-2*A2);
        phi = check_Phi_range(atan2(c,(-1* sqrt(a*a + b*b - c*c))) - atan2(a,b));
        phi=check_min_max(phi);
		return phi;
}



double phi2_solution1(double matrix[3][4])
{
       double a,b,phi,c;
        a=-matrix[1][2]*32+matrix[1][3];
        b=  32 * matrix[0][2]-matrix[0][3] ;
        c=(A3*A3+D4*D4-a*a-b*b-A2*A2)/(-2*A2);
        phi = check_Phi_range(atan2(c, sqrt(a*a + b*b - c*c)) - atan2(a,b));
        phi=check_min_max(phi);
		return phi;
}


double phi3_solution2(double matrix[3][4])
{
       double a,b,phi,c;
        a=matrix[0][3]-32 * matrix[0][2];
        b=  matrix[1][3]-matrix[1][2]*32 ;
        c=A3;
        phi = check_Phi_range(atan2(c,(-1* sqrt(a*a + b*b - c*c))) - atan2(a,b));
        phi=check_min_max(phi);
		return phi;
}



double phi3_solution1(double matrix[3][4])
{
       double a,b,phi,c;
        a= matrix[0][3]-32 * matrix[0][2];
        b= matrix[1][3]-32*matrix[1][2] ;
        c=A3;
        phi = check_Phi_range(atan2(c, sqrt(a*a + b*b - c*c)) - atan2(a,b));
        phi=check_min_max(phi);
        return phi;
}

double phi4_solution2(double angle)
{
       double a,b,phi,c;
       if(angle<0)
   		{
   			phi=angle+PI;
   		}
   		else
		{
			phi= angle - PI;
		}
		phi=check_min_max(phi);
        return phi;
}



double phi4_solution1(double matrix[3][4], double angle)
{
       double a,b,phi,c;
        
        b= matrix[0][2]*cos(angle)+matrix[1][2]*sin(angle);
        
        if(b==0)
		{
			printf("Angle not possible");
			return 0;
    	}
		else
        {
			a=matrix[2][2];
        	phi =atan(a/b);
        	phi=check_min_max(phi);
        	return phi;
   		}
}

double phi5_solution2(double angle)
{
       double a,b,phi,c;
       if(angle<0)
   		{
   			phi=angle+PI;
   		}
   		else
		{
			phi= angle - PI;
		}
		phi=check_min_max(phi);
        return phi;
}



double phi5_solution1(double matrix[3][4], double angle)
{
       double a,b,phi,c;
        
        b= matrix[0][2]*cos(angle)+matrix[1][2]*sin(angle);
        a=matrix[2][2];
        
        if(a==0)
		{
			printf("Angle not possible");
			return 0;
    	}
		else
        {
			
        	phi =atan(b/a);
        	phi=check_min_max(phi);
        	return phi;
   		}
}

double phi6_solution2(double angle)
{
       double a,b,phi,c;
       if(angle<0)
   		{
   			phi=angle+PI;
   		}
   		else
		{
			phi= angle - PI;
		}
		phi=check_min_max(phi);
        return phi;
}



double phi6_solution1(double matrix[3][4], double angle)
{
       double a,b,phi,c;
        
        a= matrix[0][0]*sin(angle)-matrix[1][0]*cos(angle);
        b= -matrix[0][1]*sin(angle)+matrix[1][1]*cos(angle);
       
        if(b==0)
		{
			printf("Angle not possible");
			return 0;
    	}
		else
        {
			
        	phi =atan(-(a/b));
        	phi=check_min_max(phi);
        	return phi;
   		}
}


