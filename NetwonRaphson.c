#include<stdio.h>
#include<math.h>

float f(float x)
{
	return x*log10(x)-1.2;
}

float df(float x)
{
	return log10(x)+0.43429;
}

void main(void)
{
	int itr,maxitr;
	float h,x0,x1,allerr;
	printf("Enter x0,allowed error and maximun iterations.\n");
	scanf("%f%f%d",&x0,&allerr,&maxitr);
	
	for(itr=1;itr<=maxitr;itr++)
	{
		h=f(x0)/df(x0);
		x1=x0-h;
		printf("Itr= %d --- X= %f\n",itr,x1);
		
		if(fabs(h)<allerr)
		{
			printf("Root= %f --- Itr= %d\n",x1,itr);
			return 0;
		}
		x0=x1;
	}
	return 1;
}
