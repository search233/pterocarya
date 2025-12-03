//1006

#include <iostream>
#include <cstdio>
#include <string>
using namespace std;

int main()
{
	string fir, las;
	int tmin=86400, tmax=0;
	
	string name;
	int m; cin >> m;
	while(m--){
		cin >> name;
		int t, h, m, s;
		scanf("%2d:%2d:%2d", &h, &m, &s);
		t = h*3600 + m*60 + s;
		if(t<tmin){
			fir = name;
			tmin = t;
		}
		
		scanf("%2d:%2d:%2d", &h, &m, &s);
		t = h*3600 + m*60 + s;
		if(t>tmax){
			las = name;
			tmax = t;
		}		
	}
	
	cout << fir << ' ' << las;
	
	return 0;
}
