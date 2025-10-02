//7_7

#include<stdio.h>
#define ll long long


int main()
{
	ll a, b, c, d, e, f;
	
	scanf("%lld %lld %lld %lld %lld %lld", &a, &b, &c, &d, &e, &f);
	
	ll num_1 = a*c*e;
	ll num_2 = a*c*f + c*e*b + a*e*d;
	ll num_3 = a*d*f + d*c*f + b*d*e;
	ll num_4 = b*d*f;
	
	printf("%lld %lld %lld %lld", num_1, num_2, num_3, num_4);
	
	return 0;
}
