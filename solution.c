#include <math.h>
#include <stdio.h>
#include "solution.h"
#include "matrixes.h"

double check_range(double angle)
{
	double x=99;
	if(angle>-PI &&angle<PI)
	{
		return angle;
	}
	else
	{
		return x;
	}
}

double calcDeviation(double old_angle, double new_angle)
{
	double deviation=0;
	
	if(old_angle!=0 && new_angle!=0)
	{
		if(new_angle/fabs(new_angle)==old_angle/fabs(old_angle))
		{
			deviation=fabs( fabs(new_angle)-fabs(old_angle));
		}
		else
		{
			deviation= fabs(new_angle)+fabs(old_angle);
		}
	}
	else
	{
		deviation = fabs(fabs (old_angle) + fabs(new_angle));
	}	
	//printf("%f\n",deviation);
	return deviation;
}

double calc_base_to_end_deviation(double phi1, double phi2,double phi3,double phi4,double phi5,double phi6, double rotationUserMatrix[4][4])
{
	double a,b,c,d,e,f,g,h,i,j,k,m,o,p,q,r,s,u,v,px,py,pz,nx,ny,nz,ox,oy,oz,az,ay,ax,deviation; //all variablenames according to Excel Simulation-6-Achs-Roboter
	//sheet Überprüfe Position_1
	
	o=(D6+LW+AW*cos(PHIW))*cos(phi5)-AW*sin(OMEGA)*sin(phi5)*sin(phi6+PHIW)+D4;
	i=cos(phi4)*AW*sin(OMEGA)*cos(phi6+PHIW)-sin(phi4)*(cos(phi5)*AW*sin(OMEGA)*sin(phi6+PHIW)+sin(phi5)*(AW*cos(OMEGA)+D6+LW))-D3;
	
	q= cos(phi5)*AW*sin(OMEGA)*sin(phi6+PHIW)+sin(phi5)*(D6+LW+AW*cos(OMEGA));
	p= cos(phi4)*q+sin(phi4)*AW*sin(OMEGA)*cos(phi6+PHIW)+A3;
	j= cos(phi3)*o-sin(phi3)*p;
	k= cos(phi3)*p+sin(phi3)*o+A2;
	px=-sin(phi1)*i+cos(phi1)*(cos(phi2)*j-sin(phi2)*k+A1);
	py= cos(phi1)*i+sin(phi1)*(cos(phi2)*j-sin(phi2)*k+A1);
	pz= sin(phi2)*(cos(phi3)*o-sin(phi3)*p)+cos(phi2)*(sin(phi3)*o+cos(phi3)*p+A2)+D1;
	deviation=calcDeviation(rotationUserMatrix[0][3],px)+calcDeviation(rotationUserMatrix[1][3],py)+calcDeviation(rotationUserMatrix[2][3],pz);

	a= cos(phi4)*sin(phi6+PHIW)+sin(phi4)*cos(phi5)*cos(phi6+PHIW);
	b= sin(phi3)*(cos(phi4)*cos(phi5)*cos(phi6+PHIW)-sin(phi4)*sin(phi6+PHIW))+cos(phi3)*sin(phi5)*cos(phi6+PHIW);
	c= cos(phi3)*(cos(phi4)*cos(phi5)*cos(phi6+PHIW)-sin(phi4)*sin(phi6+PHIW))-sin(phi3)*sin(phi5)*cos(phi6+PHIW);
	nx= sin(phi1)*a-cos(phi1)*(cos(phi2)*b+sin(phi2)*c);
	ny= -cos(phi1)*a-sin(phi1)*(cos(phi2)*b+sin(phi2)*c);
	nz= -sin(phi2)*b+cos(phi2)*c;
	deviation+=calcDeviation(rotationUserMatrix[0][0],nx)+calcDeviation(rotationUserMatrix[1][0],ny)+calcDeviation(rotationUserMatrix[2][0],nz);
	
	r= cos(phi4)*(cos(phi5)*cos(OMEGA)*sin(phi6+PHIW)-sin(phi5)*sin(OMEGA))+sin(phi4)*cos(OMEGA)*cos(phi6+PHIW);
	s=sin(phi5)*cos(OMEGA)*sin(phi6+PHIW)+cos(phi5)*sin(OMEGA);
	d= cos(phi4)*cos(phi6+PHIW)*cos(OMEGA)+sin(phi4)*(sin(phi5)*sin(OMEGA)-cos(phi5)*cos(OMEGA)*sin(phi6+PHIW));
	e= sin(phi3)*r+cos(phi3)*s;
	f= cos(phi3)*r-sin(phi3)*s;
	ox= sin(phi1)*d+cos(phi1)*(cos(phi2)*e+sin(phi2)*f);
	oy= -cos(phi1)*d+sin(phi1)*(cos(phi2)*e+sin(phi2)*f);
	oz= sin(phi2)*e-cos(phi2)*f;
	deviation+=calcDeviation(rotationUserMatrix[0][1],ox)+calcDeviation(rotationUserMatrix[1][1],oy)+calcDeviation(rotationUserMatrix[2][1],oz);
	
	u= cos(phi5)*cos(OMEGA)-sin(phi5)*sin(OMEGA)*sin(phi6+PHIW);
	v= cos(phi4)*(cos(phi5)*sin(OMEGA)*sin(phi6+PHIW))+sin(phi4)*sin(OMEGA)*cos(phi6+PHIW);
	m= sin(phi4)*(cos(phi5)*sin(OMEGA)*sin(phi6+PHIW)+sin(phi5)*cos(OMEGA))-cos(phi4)*sin(OMEGA)*cos(phi6+PHIW);
	g= cos(phi3)*u-sin(phi3)*v;
	h= sin(phi3)*u+cos(phi3)*v;
	ax= sin(phi1)*m+cos(phi1)*(cos(phi2)*g-sin(phi2)*h);
	ay= -cos(phi1)*m+sin(phi1)*(cos(phi2)*g-sin(phi2)*h);
	az= sin(phi2)*g+cos(phi2)*h;
	deviation+=calcDeviation(rotationUserMatrix[0][2],ax)+calcDeviation(rotationUserMatrix[1][2],ay)+calcDeviation(rotationUserMatrix[2][2],az);
	
	return deviation;
}

