//P8708

#include <iostream>
#include <algorithm>
#include <cmath>
typedef long long ll;

using namespace std;

ll a[100000];

ll digit(ll a){
    return (ll)log10(a) + 1;
}

ll pow(ll n){
    ll res=1;
    for(int i=0 ; i<n ; ++i)    res *= 10;
    return res;
}

ll splice(ll a, ll b){
    return a*pow(digit(b)) + b;
}

int main(){
    ll n, k; cin >> n >> k;

    for(int i=0 ; i<n ; ++i)  cin >> a[i];
    sort(a, a+n);

    ll cnt=0;

    if(n>1){
        int l, r;
        l=0; r=n-1;
        
        while(r>l){
            ll t=splice(a[l],a[r]);

            if(t <= k){
                cnt += r-l;
                ++l;
            }else --r;
        }

        l=0; r=n-1;

        while(r>l){
            ll t=splice(a[r],a[l]);

            if(t <= k){
                cnt += r-l;
                ++l;
            }else --r;
        }

    }
  
    cout << cnt;

    return 0;
}