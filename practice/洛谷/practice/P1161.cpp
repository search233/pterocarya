//P1161

#include<iostream>
using namespace std;

int turn_light(int light);

int main(){
	int n;	cin >> n;
	int light[500000] = {0,};
	double a, t=0;	int Max;
	
	for(int i=0 ; i<n ; i++){
		cin >> a >> t;
		
		for( ; t>0 ; t--){
			
			int tmp = t*a;
			tmp /= 1;
			
			if(i==0){
				Max = tmp;
			}else if(tmp>Max){
				Max = tmp;	}
				
			light[tmp] = turn_light(light[tmp]);
		}
	}
	
	for( ; Max>0 ; Max--){
		if(light[Max]){
			cout << Max;
			break;
		}
	}
	
	return 0;
}

int turn_light(int light){
	
	int ret;
	if(light==1){
		ret = 0;
	}else{
		ret = 1;
	}
	
	return ret;
}
