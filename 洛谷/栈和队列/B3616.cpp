//B3616

#include <iostream>
#include <queue>

using namespace std;

int main(){
	queue<int> qu;
	int n; cin >> n;
	
	for(int i=0 ; i<n ; ++i){
		int t; cin >> t;
		if(t==1){
			int num; cin >> num;
			qu.push(num);
			
		}else if(t==2){
			if(qu.empty()) 
				cout << "ERR_CANNOT_POP" << '\n';
			else qu.pop();
			
		}else if(t==3){
			if(qu.empty()) 
				cout << "ERR_CANNOT_QUERY" << '\n';
			else cout << qu.front() << '\n';
						
		}else{
			cout << qu.size() << '\n';
		}			 
	}
	
	return 0;
}
