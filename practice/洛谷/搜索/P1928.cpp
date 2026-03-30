#include <iostream>
#include <string>

using namespace std;

string dfs(){
	int k;
	char ch='0';
	string ans="", s="";
	while(cin >> ch){
		if(ch=='['){
			cin >> k;
			s = dfs();
			while(k--) ans+=s; 
		}else if(ch==']'){
			return ans;
		}else ans+=ch;
	}
	return ans;
}

int main()
{
	cout << dfs();
	return 0;
}
