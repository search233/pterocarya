//P1223

#include<iostream>
#include<cstdio>
#include<algorithm>

using namespace std;

struct P{
	int num;
	double t;
}p[1000];

bool cmp(P a, P b){
	return a.t < b.t;
}

int main(){
	int n;	cin >> n;
	
	for(int i=0 ; i<n ; i++){
		p[i].num = i;
		cin >> p[i].t;
	}
	
	sort(p, p+n, cmp);
	
	double sum=0;
	
	for(int i=0 ; i<n ; ++i){
		cout << p[i].num+1;
		
		if(i<n-1){
			cout << " ";
			sum += p[i].t * (n-i-1);
		} 
	}
	
	printf("\n%.2f", sum/n);

	return 0;
}
