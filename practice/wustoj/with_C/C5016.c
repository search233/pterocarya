//C5016
#define ll long long
#include<stdio.h>

 

ll myabs(ll x);
ll gcd(ll a, ll b);

int main(){
	int n;	scanf("%d", &n); 
	ll tmp_up, tmp_down;
	ll x=0, up=0, down=1;
	
	for(int i=0 ; i<n ; i++){ 
		scanf("%lld/%lld", &tmp_up, &tmp_down);
		if(tmp_up==0)	continue; 
		
		up = up*tmp_down + down*tmp_up;
		down *= tmp_down;
		
		long long factor = gcd(myabs(up), down);
		up /= factor,	down /= factor;
		
	}
	
	if(myabs(up)>down){ 
		x += up / down,	up %= down; 
	}
	
	if(x==0 && up!=0){
		printf("%lld/%lld", up, down);
	}else if(up==0 && x!=0){
		printf("%lld", x); 
	}else if(x!=0 && up!=0){
		printf("%lld %lld/%lld",x, up, down);
	}
	
	return 0;
} 

ll myabs(ll x){
	if(x<0){
		x=-x;
	}
	return x;
}

ll gcd(ll a, ll b){
	ll tmp;	
	if(a<b)	{
		tmp=a; a=b;	b=tmp;
	} 
	while(b!=0){
		tmp=b; b=a%b; a=tmp;
	}
	
	return a;
} 
