//C6072

#include<iostream>
#include<vector>
#include<cstdio>

using namespace std;

struct node{
	double prise;
	int num;
	double s;
};

int main(){
	int n; cin >> n;
	vector<node> list(n);
	
	for(int i=0 ; i<n ; ++i) cin >> list[i].prise;
	for(int i=0 ; i<n ; ++i) {
		cin >> list[i].num;
		list[i].s = list[i].prise * list[i].num;
	}
	
	double sum=0;
	for(int i=0 ; i<n ; ++i) sum += list[i].s;
	
	printf("%.2f", sum);
	
	return 0;
}
