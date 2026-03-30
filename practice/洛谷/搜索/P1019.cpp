//P1019

#include <iostream>
#include <string>
#include <climits>

using namespace std;

int n, cnt[30];
int res=INT_MIN;
string s[30], a;

int func(string str, string s){
	
	int res = 0;
	for(int i=str.size()-1 ; i>=0 ; --i){
		if(str[i]==s[0]){
			int l=i;
			for(int j=0 ; j<(int)s.size() ; ++j){
				if(str[l] == s[j]) ++l;
				else break;
			}
			if(l==(int)str.size()){
				res = l-i;
				break;
			}
		}
	}
	
	return res;
}

void dfs(string str, int x){
	res = max(res, (int)str.size()-x);
	for(int i=1 ; i<=n ; ++i){
		int temp;
		if(cnt[i]==2) continue;
		temp = func(str, s[i]);
		if(temp==0) continue;
		++cnt[i];
		dfs(str+s[i],  x+temp);
		--cnt[i];
	}
	return;
}


int main()
{
	cin >> n;
	for(int i=1 ; i<=n ; ++i) cin >> s[i];
	
	cin >> a;
	dfs(a, 0);
	
	cout << res;
	
	return 0;
}
