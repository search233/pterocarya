//P1007

#include <iostream>
#include <algorithm>
using namespace std;

int main(){
    int l; cin >> l;
    int n; cin >> n;

    int tmax=-1, tmin=-1;

    if(n){
        int arr[l+2];
        fill(arr, arr+l+2, 0);
        
        int pos;
        for(int i=0 ; i<n ; ++i){
            cin >> pos;
            ++arr[pos]; 
        }

        for(int i=1 ; i<=l ; ++i){
            if(arr[i]){
                tmin = max(tmin, min(i,l-i+1));
                tmax = max(tmax, max(i,l-i+1));
            }
        }
    }else   tmax = tmin = 0;

    cout << tmin << ' ' << tmax;

    return 0;
}