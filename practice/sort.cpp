//sort

#include<iostream>
#include<algorithm>

using namespace std;

bool cmp(int a, int b){
	return a>b;
}


int main(){
	int num[10] = {1,4,6,3,7,8,4,86,34,23};
	
	sort(num, num+10, cmp);
	
	for(int i=0 ; i<10 ; i++)	cout << num[i];
	
	return 0;
}
