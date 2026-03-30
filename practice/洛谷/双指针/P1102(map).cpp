//P1102(map)

#include <iostream>
#include <map>
#define ll long long

using namespace std;

int main(){
    int n, c; cin >> n >> c;
    int b[n];

    map<ll, ll> a;
    for(int i=0 ; i<n ; ++i){
        cin >> b[i];
        ++a[b[i]];
        b[i] += c;
    }

    ll sum=0;
    for(int i=0 ; i<n ; ++i){
        sum += a[b[i]];
    }

    cout << sum;

    return 0;
}