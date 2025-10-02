//P1085

#include<iostream>
using namespace std;

int main(){
	int Max=0, tmp, date=0;
	int a, b;
	
	for(int i=0 ; i<7 ;i++){
		cin >> a >> b;
		tmp = a + b;
		
		if(tmp>8 && tmp>Max){
			date = i + 1;
			Max = a + b;
		}
	}
	
	cout << date << endl;
	
	return 0;
}
