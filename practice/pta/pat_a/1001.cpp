//1001

#include <iostream>
#include <stack>

using namespace std;
typedef long long ll;

int main()
{
	ll a, b; cin >> a >> b;
	ll cnt=0, sum=a+b;
	
	stack<int> st;
	
	if(sum<0){
		cout << '-';
		sum = -sum;
	}
	
	while(sum){
		if(cnt%3==0 && cnt) st.push(-1);
		++cnt;
		st.push(sum%10);
		sum /= 10; 
	}
	
	if(!cnt) cout << '0';
	
	while(!st.empty()){
		if(st.top()!=-1) cout << st.top();
		else cout << ',';
		st.pop();
	}
	
	return 0;
}
