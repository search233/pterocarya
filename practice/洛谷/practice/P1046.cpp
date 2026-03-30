//P1046

#include<iostream>
using namespace std;

int main(){
	int apple[10];	
	for(int i=0 ; i<10 ; i++){
		cin >> apple[i];
	}
	
	int cnt=0, hight;	cin >> hight;
	hight += 30;
	
	for(int i=0 ; i<10 ; i++){
		if(hight>=apple[i]){
			cnt++;
		}
	}
	
	cout << cnt << endl;
	
	return 0;
}
