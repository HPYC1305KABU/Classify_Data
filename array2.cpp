#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include<math.h>
#include"median.h"
#include"mean.h" 
#define BSIZE 769
#define B1SIZE 9  


float calculateSD(float data[],int n,float mean)
{
    float standardDeviation = 0.0;
    int i;
    for(i=0; i<n; ++i)
        standardDeviation += pow((data[i] - mean), 2);
    return sqrt(standardDeviation/n);
}

int main()

{

	float median=0,*ch,sum=0.0,mean,mean2,mean3,sd,sd1,sd2;
	char filename[] = "diabetes.csv";
	char buffer[BSIZE];
	FILE *f;

	char *field;
	float Pregnancies[BSIZE],Glucose[BSIZE],BloodPressure[BSIZE],SkinThickness[BSIZE], Insulin[BSIZE],BMI[BSIZE],DiabetesPedigereeFunction[BSIZE],Age[BSIZE],Outcome[BSIZE];
	char gl[BSIZE][B1SIZE];
	int i=0,j=0;
	float glu[BSIZE][B1SIZE];

	f = fopen(filename,"r");
	if( f == NULL)
	{
		printf("Unable to open file '%s'\n",filename);
		exit(1);
	}
	while(fgets(buffer,BSIZE,f))
	{
	
		field=strtok(buffer,",");
		Pregnancies[i]=atof(field);
		

		field=strtok(NULL,",");
		Glucose[i]=atof(field);
		

		field=strtok(NULL,",");
		BloodPressure[i]=atof(field);
		

		field=strtok(NULL,",");
		SkinThickness[i]=atof(field);
		

		field=strtok(NULL,",");
		Insulin[i]=atof(field);
		

		field=strtok(NULL,",");
		BMI[i]=atof(field);
		

		field=strtok(NULL,",");
		DiabetesPedigereeFunction[i]=atof(field);
		

		field=strtok(NULL,",");
		Age[i]=atof(field);
		

		field=strtok(NULL,",");
		Outcome[i]=atof(field);
		
		i++;		 
	}
	printf("pregnencies \t glucose \t bloodpressure \t skinthickness \t insulin \t bmi \t diabetetspedigreefunction \t Age \t outcome\n");    
    
   
	for(i=1;i<BSIZE;i++)
	{
			glu[i][j]=Pregnancies[i];
			glu[i][j+1]=Glucose[i];
			glu[i][j+2]=BloodPressure[i];
			glu[i][j+3]=SkinThickness[i];
			glu[i][j+4]=Insulin[i];
			glu[i][j+5]=BMI[i];
			glu[i][j+6]=DiabetesPedigereeFunction[i];
			glu[i][j+7]=Age[i];
			glu[i][j+8]=Outcome[i];
			j=0;					
    }
    j=0;
   

    for(i=1;i<BSIZE;i++)
	{
		if(glu[i][j]==0.0)
		{
			Age[i]=Find_median(Age , BSIZE);
			glu[i][j]=Age[i];
		}
	}
	j=0;

	mean = mean1(SkinThickness,BSIZE);
	mean2 = mean1(Insulin,BSIZE);
	mean3 = mean1(BMI,BSIZE);
	sd=calculateSD(SkinThickness,BSIZE,mean);
	sd1=calculateSD(Insulin,BSIZE,mean2);
	sd2=calculateSD(BMI,BSIZE,mean3);
	for(i=1;i<BSIZE;i++)
	{
		SkinThickness[i]=((SkinThickness[i]-mean)/sd);//Standardization formula xnew=((x[i] -xmean)/standard deviation)
		Insulin[i]=((Insulin[i]-mean2)/sd1);
		BMI[i]=((BMI[i]-mean3)/sd2);
		glu[i][j+3]=SkinThickness[i];
		glu[i][j+4]=Insulin[i];
		glu[i][j+7]=BMI[i];
	}
	for(i=1;i<BSIZE;i++)
	{
    	for(j=0;j<B1SIZE;j++)
    	{
    		printf("%0.2f\t",glu[i][j]);//printing the data set
		}
		printf("\n");
	}
	fclose(f);
	return(0);
}
