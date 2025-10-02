//1005

#include <iostream>
#include <stack>

using namespace std;

void change(int n);

int main()
{
	int sum=0;
	char ch=' ';
	while(ch!=EOF){
		ch=getchar();
		if(ch<='9' && ch>='0') sum += ch-'0';
	}
	
	stack<int> st;
	if(!sum) st.push(0);
	while(sum){
		st.push(sum%10);
		
		sum/=10;
	}
	
	bool tag=1;
	while(!st.empty()){
		if(tag){
			tag=0;
			change(st.top());
			st.pop();
		}else{
			cout << ' ';
			change(st.top());
			st.pop();
		}
	}
	
	return 0;
}

inline void change(int n){
	switch (n) {
		case 1:
			cout << "one";
			break;
		case 2:
			cout << "two";
			break;
		case 3:
			cout << "three";
			break;
		case 4:
			cout << "four";
			break;
		case 5:
			cout << "five";
			break;
		case 6:
			cout << "six";
			break;
		case 7:
			cout << "seven";
			break;
		case 8:
			cout << "eight";
			break;
		case 9:
			cout << "nine";
			break;
		case 0:
			cout << "zero";
			break;
	}
	return;
} 
