//P7714

#include <iostream>
#include <algorithm>

using namespace std;


int main(){
    int t; cin >> t;

    for(int i=0 ; i<t ; ++i){
        int n; cin >> n;
        int p[n+1];


        int cnt = 0;
        int tag1, tag2;
        tag1 = tag2 = 1;
        
        for(int j=1 ; j<=n ; ++j) cin >> p[j];

        while(tag1<n){
            // int maxn = 0;

            if(p[tag1]==tag1) ++tag1;
            else{
                tag2 = p[tag1];
                for(int j=tag1 ; j<=tag2 ; ++j){
                    tag2 = max(tag2, p[j]);
                }
                sort(p+tag1, p+tag2+1);
                cnt += tag2 - tag1 + 1; 
                tag1 = tag2;
            }
        }

        cout << cnt << '\n';
    }

    return 0;
}
