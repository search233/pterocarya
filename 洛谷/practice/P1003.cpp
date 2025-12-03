//P1003

#include<iostream>

using namespace std;

struct carpet{
	int a;
	int b;
	int g;
	int k;
};

int main(){
	
	int n;	cin >> n;
	carpet cp[n];
	
	for(int i=0 ; i<n ; i++){
		cin >> cp[i].a >> cp[i].b >> cp[i].g >> cp[i].k;
		cp[i].g--;	cp[i].k--;
	}
	
	int x, y;	cin >> x >> y;
	int ret=-1;
	
	for(int i=0 ; i<n ; i++){
		if(x>=cp[i].a && x<=cp[i].a+cp[i].g)
			if(y>=cp[i].b && y<=cp[i].b+cp[i].k)	
				ret = i+1;
	}
	
	cout << ret << endl;
	
	return 0;
} 
