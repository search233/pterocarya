//P2196

#include <iostream>
#include <vector>

using namespace std;

vector<int> edge[25];

int main()
{
	int arr[30];
	int n; cin >> n;
	
	for(int i=1 ; i<=n ; ++i) cin >> arr[i];
	
	for(int i=1 ; i<n ; ++i){
		for(int j=i+1 ; j<=n ; ++j){
			int t; cin >> t;
			if(t){
				edge[i].push_back(j);
				edge[j].push_back(i); 
			}
		}
	}
	
	
	
	return 0;
}
