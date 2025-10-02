//P1901

#include <iostream>
#include <stack>

using namespace std;

struct row{
	int h;
	int v;
	int sum;
};

 int main(){
	int res=0;
	int n; cin >> n;
	stack<int> st;
	row arr[n];
	
	for(int i=0 ; i<n ; ++i){
		cin >> arr[i].h >> arr[i].v;
		arr[i].sum=0;
	}
	
	for(int i=0 ; i<n ; ++i){
		while(!st.empty() && arr[i].h > arr[st.top()].h){
			arr[i].sum += arr[st.top()].v;
			st.pop();
		}
		if(!st.empty() && arr[i].h < arr[st.top()].h){
			arr[st.top()].sum += arr[i].v;
		}  
		
		st.push(i);
	}
	
	for(int i=0 ; i<n ; ++i){
		res = max(res, arr[i].sum);
	}
	
	cout << res;
	
	return 0;
 }
 
