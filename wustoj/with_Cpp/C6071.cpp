//C6071

#include<iostream>
#include<cstdio>

using namespace std;

int main(){
	int n, x;	cin >> n >> x;
	int num[1010];
	
	cin >> num[0];
	for(int i=1 ; i<n ; i++){
		cin >> num[i];
		if(num[i]<=num[i-1]){
			printf("Invalid Value");
			return 0;
		}
	}
	
	
	int left=0, right=n-1;
	int mid = (left+right) / 2;
	bool flag = false;
	
	for(int i=0 ; ; i++){
		printf("[%d,%d][%d]\n", left, right, mid);
		if(num[mid]==x){
			flag = true;
			break;
		}else if(num[mid]<x){
			left = mid + 1;
		}else if(num[mid]>x){
			right = mid - 1;
		}
		mid = (left+right) / 2;
		if(left==right && num[mid]!=x){
			printf("[%d,%d][%d]\n", left, right, mid);
			break;
		}
		if(left > right) break;
	
	}
	
	if(flag==true)	cout << mid;
	else	cout << "Not Found";
	
	return 0;
}
