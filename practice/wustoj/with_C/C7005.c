//C7005

#include<stdio.h>

double funpi(double e);

int main()
{
    double e,pi;
    scanf("%lf",&e);
    pi=4*funpi(e);
    printf("%lf\n",pi);
    return 0;
}

double funpi(double e) {
	
	
	double PI=0, temp, tag=1;
  	for(int i=1 ; ; i++ ){
  		
  		temp = tag / (i*2-1);
  		
  		if(temp<0 && -temp<e) break;
		if(temp>0 && temp<e)  break;

		
		PI += temp;
		tag = -tag;
  	}
  	
  	return PI;
}
