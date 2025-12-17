#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void solve()
{
    int n;
    cin >> n;
    vector<vector<int> > vis(8,vector<int>(7,0));
    for(int i = 1; i <= n; i++) {
        int a,b;
        cin >> a >> b;
        vis[a][b] = 1;
    }

    auto dfs = [&](auto self, int cur, int pre) -> int {
        if(cur==7)
            return 1;
        int res = 0;
        for (int i = 1; i <= 6;i++){
            if(i!=pre && !vis[cur+1][i]){
                vis[cur + 1][i] = 1;
                res += self(self,cur+1,i);
                vis[cur + 1][i] = 0;
            }
        }
        return res;
    };
    cout << dfs(dfs, 0, 0) << endl;
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int _ = 1;
    // cin >> _;
    while (_--)
    {
        solve();
    }

    return 0;
}