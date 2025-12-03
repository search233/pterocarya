//P1478

#include<iostream>
#include<algorithm>

using namespace std;

struct l{
	int x;
	int y;
}list[5000];

bool comp(l a, l b) {return a.y < b.y;}

int main(){
	
	int n, s; cin >> n >> s;
	int a, b; cin >> a >> b;
	int h=a+b, cnt=0;
	
	for(int i=0 ; i<n ; ++i) cin >> list[i].x >> list[i].y;
	
	sort(list, list+n, comp);
	
	for(int i=0 ; s>0 ; ++i){
		if(list[i].x<=h){
			s -= list[i].y;
			if(s>0)	++cnt;
		}	
		
	}
	
	cout << cnt;
	
	return 0;
}
