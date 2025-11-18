#include <bits/stdc++.h>
#define endl '\n'
#define yes cout << "Yes" << endl
#define no cout << "No" << endl
#define int long long
#define pii pair<int,int>
#define vii vector<vector<int>>
using namespace std;
const int INF = 1e18;
const int maxn = 1e9;

void solve(){
    int n,m;cin >> n >> m;
    vector<int> a(n),b(m),c(m);
    for(int &x : a) cin >> x;
    for(int &x : b) cin >> x;
    for(int &x : c) cin >> x;
    vector<pii> B;

    priority_queue<int,vector<int>,greater<>> pq,less;
    vector<int> b2;
    for(int x : a) pq.push(x);
    for(int i = 0; i < m; i++){
        if(c[i] == 0) b2.push_back(b[i]);
        else B.push_back({b[i],c[i]});
    }
    sort(B.begin(),B.end(),[](pii a, pii b){
        if(a.first == b.first) return a.second > b.second;
        return a.first < b.first;
    });

    int p = 0;
    while(!pq.empty() && p < B.size()){
        int cur = pq.top();
        pq.pop();
        if(cur >= B[p].first){
            int add = max(cur,B[p].second);
            pq.push(add);
            p++;
        }
        else less.push(cur);
    }
    int ans = p;
    while(!pq.empty()){
        less.push(pq.top());
        pq.pop();
    }

    p = 0;
    sort(b2.begin() ,b2.end());
    while(!less.empty() && p < b2.size()){
        int cur = less.top();
        less.pop();
        if(cur >= b2[p]){
            ans++;
            p++;
        }
    }
    cout << ans << endl;
}
signed main(){
    ios::sync_with_stdio(0);cin.tie(0);
    int t;
    cin >> t;
    while(t--){
        solve();
    }
    return 0;
}