#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#include "matrixes.h"
#include "angles.h"
#include "userspace.h"
#include "solution.h"
#include "dhmatrix.h"




int main(int argc, char *argv[])
{
   
	double possibilities_phi1[2];//all possible angles are stored in arrays, could be changed to tree implementation
	double possibilities_phi2[4];
	double possibilities_phi3[8];
	double possibilities_phi4[16];
	double possibilities_phi5[32];
	double possibilities_phi6[32];
	double rotationUserMatrix[4][4];
   
    double angledeviation;
    double smallest_angledeviation;
    double compair_angledeviation;
	double smallest_deviation;
	double compair_deviation;
    double deviation;
    double solution;
    int y,x, inversepossilbe=0;
    int a,b,c,d,e,f,g,h,i,j,k,loopcnt=0; //varibales for loopcnt
	double phi1_angle=0;
	double phi2_angle=0;
	double phi3_angle=0;
	double phi4_angle=0;
	double phi5_angle=0;
	double phi6_angle=0;
	double phi1_deviation=0;
	double phi2_deviation=0;
	double phi3_deviation=0;
	double phi4_deviation=0;
	double phi5_deviation=0;
	double phi6_deviation=0;
	double robo_accuracy =1;
	double rotationA;
	double rotationB;
	double rotationC;
	double positionVectorX;
	double positionVectorY;
	double positionVectorZ;
	while(1)
	{
	
	angledeviation=0;
    smallest_angledeviation=100;
    compair_angledeviation=0;
	smallest_deviation=180;
	compair_deviation=0;
    deviation=0;
    x=0;
    i=0;
    j=0;
    k=0;
    h=0;
	b=0;
	c=0;
	d=0;
	printf("%f\n",toRad(90));
      printf("if you want to exit the programm enter 2000\n");
      printf("Please enter x position of postion vector:");
      scanf("%lf", &positionVectorX);
      if(positionVectorX==2000)
      {
      	break;
	  }
      printf("Please enter y position of postion vector:");
      scanf("%lf", &positionVectorY);
      printf("Please enter z position of postion vector:");
      scanf("%lf", &positionVectorZ);
   	  printf("Please enter a (z) position of the euler angle:");
   	  scanf("%lf", &rotationA);
   	  rotationA=toRad(rotationA);
	  printf("Please enter b (y) position of the euler angle:");
   	  scanf("%lf", &rotationB);
   	  rotationB=toRad(rotationB);
   	  printf("Please enter c (x) position of the euler angle:");
   	  scanf("%lf", &rotationC);
   	  rotationC=toRad(rotationC);
	  initRotationMatrix(rotationA, rotationB, rotationC,  positionVectorX,  positionVectorY, positionVectorZ, rotationUserMatrix);
     
	  /* needed if other coordinate system is used
      initRotationMatrix(rotationWorkpiece_x,rotationWorkpiece_y,rotationWorkpiece_z, shiftWorkpiece_x,shiftWorkpiece_y,shiftWorkpiece_z,rotationWorkpieceMatrix);
      setOrientationTCP();
      matrixmultiplication( rotationWorkpieceMatrix,rotationUserMatrix, workpiece_to_base);
      matrixmultiplication(orientationTCP, rotationUserMatrix, entered_orientation);
    	*/
     
		calc_first_Matrix_for_Angles(rotationUserMatrix);
     
         possibilities_phi1[0] = phi1_solution1(ph1_inverse0);
         possibilities_phi1[1]= phi1_solution2(ph1_inverse0);
         printf("%f\n",possibilities_phi1[0]);
         for(e=0;e<4;e++)
         {
		 
		 
			 if(e==2)
			 {
			 	i=1;
			 	k=2;
			 }
			 
	        calc_second_Matrix_for_Angles(ph1_inverse0,possibilities_phi1[i]);
	        if(e==0 || e==2)
	         {
			 	possibilities_phi2[k] = phi2_solution1(odd_inverse);
	         	possibilities_phi2[k+1] = phi2_solution2(odd_inverse);
     	 	 }
         	calc_third_Matrix_for_Angles(odd_inverse,possibilities_phi2[e]);
        	possibilities_phi3[j] = phi3_solution1(even_inverse);
        	possibilities_phi3[j+1] = phi3_solution2(even_inverse);
         
			for(a=0;a<2;a++)
	        {
			 
		         calc_fourth_Matrix_for_Angles(even_inverse,possibilities_phi3[b]);
		         possibilities_phi4[c]= phi4_solution1(even_inverse,possibilities_phi3[b]);
		         possibilities_phi4[c+1] = phi4_solution2(possibilities_phi4[c]);
		         possibilities_phi5[d]= phi5_solution1(odd_inverse,possibilities_phi4[c]);
		         possibilities_phi5[d+1] = phi5_solution2(possibilities_phi5[d]);
		         possibilities_phi5[d+2]= phi5_solution1(odd_inverse,possibilities_phi4[c+1]);
		         possibilities_phi5[d+3] = phi5_solution2(possibilities_phi5[d+2]);
		         possibilities_phi6[d]= phi6_solution1(odd_inverse,possibilities_phi4[c]);
		         possibilities_phi6[d+1] = phi6_solution2(possibilities_phi6[d]);
		         possibilities_phi6[d+2]= phi6_solution1(odd_inverse,possibilities_phi4[c+1]);
		         possibilities_phi6[d+3] = phi6_solution2(possibilities_phi6[d+2]);
		         b++;
		         c+=2;
		         d+=4;
	     	}
		j+=2;
		}
		j=0;
		k=0;
		x=0;
	    for (a=0;a<2;a++)
	    {
	        for (b=0;b<2;b++)
	        {
	            for (c=0;c<2;c++)
	            {
	                for (d=0;d<2;d++)
	                {
	                    for (e=0;e<4;e++)
	                    {
	                        if(e==0)
	                        {
	                            f=loopcnt;
	                            g=loopcnt;
	                        }
	                        
	                        if(e==1)
	                        {
	                            f=loopcnt;
	                            g=loopcnt+1;
	                        }
	                        
	                        if(e==2)
	                        {
	                            f=loopcnt+1;
	                            g=loopcnt;
	                        }
	                        if(e==3)
	                        {
	                            f=loopcnt+1;
	                            g=loopcnt+1;
	                            loopcnt+=2;
	                        }
	                        if(possibilities_phi1[a]==0 || possibilities_phi2[k]==0 || possibilities_phi3[j]==0 || possibilities_phi4[h]==0 || possibilities_phi5[f]==0 || possibilities_phi6[g] ==0)
	                        {
	                        	printf("Angle calcualtion nr. %d had an angle containing zero\n", x);
							}
							else
							{
							
			                    angledeviation = calcDeviation(phi1,possibilities_phi1[a]); 
			                    angledeviation += calcDeviation(phi2,possibilities_phi2[k]); 
			                    angledeviation += calcDeviation(phi3,possibilities_phi3[j]); 
			                    angledeviation += calcDeviation(phi4,possibilities_phi4[h]); 
			                    angledeviation += calcDeviation(phi5,possibilities_phi5[f]); 
			                    angledeviation += calcDeviation(phi6,possibilities_phi6[g]); 
			                   
			                    deviation = calc_base_to_end_deviation(possibilities_phi1[a],possibilities_phi2[k],possibilities_phi3[j],possibilities_phi4[h],possibilities_phi5[f],possibilities_phi6[g], rotationUserMatrix);
			                    x++;
			                    printf("nr. %d : %f\n", x, deviation);
							    
								if(angledeviation < smallest_angledeviation)
			                    {
			                    	smallest_angledeviation= angledeviation;
			                    	phi1_angle=possibilities_phi1[a];
			                    	phi2_angle=possibilities_phi2[k];
			                    	phi3_angle=possibilities_phi3[j];
			                    	phi4_angle=possibilities_phi4[h];
			                    	phi5_angle=possibilities_phi5[f];
			                    	phi6_angle=possibilities_phi6[g];
			                    	compair_deviation=deviation;
			                    
								}
			                    if(deviation < smallest_deviation)
			                    {
			                    	smallest_deviation=deviation;
			                    	printf("the smalles deviation: %f\n",smallest_deviation);
			                    	phi1_deviation=possibilities_phi1[a];
			                    	phi2_deviation=possibilities_phi2[k];
			                    	phi3_deviation=possibilities_phi3[j];
			                    	phi4_deviation=possibilities_phi4[h];
			                    	phi5_deviation=possibilities_phi5[f];
			                    	phi6_deviation=possibilities_phi6[g];
			                    	compair_angledeviation=angledeviation;
			                    	
			                    }
							}
		                    }
	                    h++;
	                }
	                j++;
	            }
	            k++;
	        }
	    }
		printf("the smalles angle: %f\n",smallest_angledeviation);
		printf("the comp dev: %f\n",compair_deviation);
		printf("the smalles deviation: %f\n",smallest_deviation);
       	printf("the comp angle: %f\n",compair_angledeviation);
       	
       	if(smallest_deviation< robo_accuracy && compair_deviation< robo_accuracy )
       	{
			if(compair_angledeviation <= smallest_angledeviation)
			{
				solution= smallest_deviation;
				phi1=phi1_angle;
            	phi2=phi2_angle;
            	phi3=phi3_angle;
            	phi4=phi4_angle;
            	phi5=phi5_angle;
            	phi6=phi6_angle;
			}
			else
			{
				solution= smallest_angledeviation;
				phi1=phi1_deviation;
            	phi2=phi2_deviation;
            	phi3=phi3_deviation;
            	phi4=phi4_deviation;
            	phi5=phi5_deviation;
            	phi6=phi6_deviation;
			}
		}
		else
		{
			if(compair_deviation <robo_accuracy)
			{
				solution= smallest_angledeviation;
				phi1=phi1_angle;
            	phi2=phi2_angle;
            	phi3=phi3_angle;
            	phi4=phi4_angle;
            	phi5=phi5_angle;
            	phi6=phi6_angle;
			}
			else
			{
				if(smallest_deviation< robo_accuracy)
				{
					solution= smallest_deviation;
					phi1=phi1_deviation;
	            	phi2=phi2_deviation;
	            	phi3=phi3_deviation;
	            	phi4=phi4_deviation;
	            	phi5=phi5_deviation;
	            	phi6=phi6_deviation;
				}
				else
				{
					printf("no solution\n");
				}
			}
		}
       	
       	printf("solution %f\n",solution);
       	printf("phi1=%f\n",phi1);
       	printf("phi2=%f\n",phi2);
       	printf("phi3=%f\n",phi3);
       	printf("phi4=%f\n",phi4);
       	printf("phi5=%f\n",phi5);
       	printf("phi6=%f\n",phi6);
		}
		system("PAUSE");	
        return 0;
}
