//P4387

#include <iostream>
#include <vector>
#include <stack>

using namespace std;

int main(){
    int q, n;
    cin >> q;

    for (int i = 0; i < q; ++i){
		cin >> n;
		
    	vector<int> a(n);
    	vector<int> b(n);
    
        for (int j=0 ; j<n ; ++j)  cin >> a[j];
        for (int j=0 ; j<n ; ++j)  cin >> b[j];
        
        int tag=0;
        stack<int> s;
 		for(int j=0 ; j<n ; ++j){
			s.push(a[j]);
			
			while(s.top()==b[tag]){
				s.pop();
				++tag;
				if(s.empty()) break;
			}
		}
		
		if(s.empty()) cout << "Yes" << '\n';
		else cout << "No" << '\n';
		
		while(!s.empty()){
			s.pop();
		}
    }

    return 0;
}
