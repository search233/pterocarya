//P2866

#include <iostream>
#include <stack>

using namespace std;

int main()
{
	long long ans=0;
	stack<int> st;
	
	int n; cin >> n;
	while(n--){
		int num; cin >> num;
		while(!st.empty() && num>=st.top()){
			st.pop();
		}
		ans += st.size();
		st.push(num);
	}
	
	cout << ans;
	
	return 0;
} 
