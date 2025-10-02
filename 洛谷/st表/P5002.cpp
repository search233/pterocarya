//P5002

#include <iostream>
#include <vector>
#define mod 1000000007

using namespace std;

struct node{
	int cnt;  //��¼������� 
	int size; //��¼������С 
	vector<int> to; //�ڽӱ��˫��� 
}arr[10010];



void dfs(int u, int fa){
	for(int i : arr[u].to){
		if(i != fa){
			dfs(i, u);
			//��¼ 
			arr[u].cnt = (arr[u].cnt + (long long)arr[u].size*arr[i].size) %mod;
			arr[u].size += arr[i].size;
		}
	}
	arr[u].cnt = (arr[u].cnt+arr[u].size) %mod;
	arr[u].cnt = arr[u].cnt*2%mod;
	++arr[u].size;
	++arr[u].cnt;
}

int main()
{
	int n, r, m;
	cin >> n >> r >> m;
	
	for(int i=1 ; i<n ; ++i){
		int a, b;
		cin >> a >> b;
		arr[a].to.push_back(b);
		arr[b].to.push_back(a);
	}
	
	dfs(r, 0);
	
	for(int i=0 ; i<m ; ++i){
		int p; cin >> p;
		cout << arr[p].cnt << '\n';
	}
	
	return 0;
}
