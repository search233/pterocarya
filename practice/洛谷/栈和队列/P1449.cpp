//P1449

#include <iostream>
#include <stack>

using namespace std;

int func(int a, int b, char ch);

int main(){
	stack<int> s;
	
	char ch;
	int t=0;
	
	cin >> ch;
	do{
		
		if(ch>='0' && ch<='9'){
			t = t*10 + ch-'0';
		}else if(ch=='.'){
			s.push(t);
			t=0;
		}else{
			int b=s.top(); s.pop();
			int a=s.top(); s.pop();
			s.push(func(a,b,ch));
		}
		cin >> ch;
	}while(ch!='@');
	
	cout << s.top();
	return 0;
}

int func(int a, int b, char ch){
	int res;
	if(ch=='+') res = a+b;
	else if(ch=='-') res = a-b;
	else if(ch=='*') res = a*b;
	else if(ch=='/') res = a/b;
	
	return res;
}
