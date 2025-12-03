//P1241

#include <iostream>
#include <string>

using namespace std;

int main(){
	string s;
	cin >> s;
	
	int a[101]={0};
	int len = (int)s.length();
	
	for(int i=0 ; i<len ; ++i){
		
		if(s[i]==')'){
			for(int j=i-1 ; j>=0 ; --j){
				if(s[j]=='(' && a[j]==0){
					a[j]=1;
					a[i]=1;
					break;
				}
				
				if(s[j]=='[' && a[j]==0) break;
			}
		}
		
		if(s[i]==']'){
			for(int j=i-1 ; j>=0 ; --j){
				if(s[j]=='[' && a[j]==0){
					a[j]=1;
					a[i]=1;
					break;
				}
				
				if(s[j]=='(' && a[j]==0) break;
			}
		}		
	}
	
	for(int i=0 ; i<len  ; ++i){
		if(a[i]) cout << s[i];
		else{
			if(s[i]=='(' || s[i]==')') cout << "()";
			else 	cout << "[]";
		}
	}
	
	return 0;
}
