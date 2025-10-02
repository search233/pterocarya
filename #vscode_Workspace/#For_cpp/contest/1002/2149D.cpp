//https://codeforces.com/problemset/problem/2149/D

#include <bits/stdc++.h>
#define pb push_back

using namespace std;
using ll = long long;
using arr2 = array<int, 2>;
using arr3 = array<int, 3>;
const int N = (int)2e5 + 9;
const int M = (int)1e5 + 9;
const int mod =  998244353;
const ll INF = LLONG_MAX;
const double PI = acos(-1.0);


void solve() {
    int n; cin >> n;

    string s; cin >> s;

    //0: a
    //1: b
    vector<arr2> l(n + 1);
    vector<arr2> r(n + 1);


    int taga = -1, tagb = -1;
    int cnta = 0, cntb = 0;

    if (s.front() == 'a') {
        taga = 0;
        ++cnta;
    }
    else {
        tagb = 0;
        ++cntb;
    }

    for (int i=1 ; i<n ; ++i) {
        if (s[i] == 'a') {
            
            if (taga != -1) 
                l[i][0] = (i - taga - 1) * cnta;
            
            ++cnta;
            taga = i;
        }
        else {

            if (tagb != -1) 
                l[i][1] = (i - tagb - 1) * cntb;
            
            ++cntb;
            tagb = i;
        }

        l[i][0] += l[i - 1][0];
        l[i][1] += l[i - 1][1];
    }

    taga = tagb = -1;
    cnta = cntb = 0;

    
    if (s.back() == 'a') {
        taga = n - 1;
        ++cnta;
    }
    else {
        tagb = n - 1;
        ++cntb;
    }

    for (int i=n - 2 ; i>=0 ; --i) {
        if (s[i] == 'a') {

            if (taga != -1)               
                r[i][0] = (taga - i - 1) * cnta;
            
            ++cnta;
            taga = i;
        }
        else {

            if (tagb != -1) 
                r[i][1] = (tagb - i - 1) * cntb;
            
            ++cntb;
            tagb = i;
        }

        r[i][0] += r[i + 1][0];
        r[i][1] += r[i + 1][1];
    }

    int ans = INT_MAX;
    for(int i=0 ; i<n ; ++i) {
        if (s[i] == 'a') {
            // cout << l[i][0] << ' ' << r[i][0] << '\n';
            ans = min(ans, l[i][0] + r[i][0]);
        }
        else {
            // cout << l[i][1] << ' ' << r[i][1] << '\n';
            ans = min(ans, l[i][1] + r[i][1]);
        }
        
    }

    cout << ans << '\n';
}
  

int main() {
    
    ios::sync_with_stdio(0);
    cin.tie(0);

    int _ = 1;
    cin >> _;

    while (_--) {
        solve();
        // cout << "-----------" << '\n';
    }

    return 0;
}
/*
┌───┐   ┌───┬───┬───┬───┐ ┌───┬───┬───┬───┐ ┌───┬───┬───┬───┐ ┌───┬───┬───┐
│Esc│   │ F1│ F2│ F3│ F4│ │ F5│ F6│ F7│ F8│ │ F9│F10│F11│F12│ │P/S│S L│P/B│
└───┘   └───┴───┴───┴───┘ └───┴───┴───┴───┘ └───┴───┴───┴───┘ └───┴───┴───┘
┌───┬───┬───┬───┬───┬───┬───┬───┬───┬───┬───┬───┬───┬───────┐ ┌───┬───┬───┐
│~ `│! 1│@ 2│# 3│$ 4│% 5│^ 6│& 7│* 8│( 9│) 0│_ -│+ =│ BacSp │ │Ins│Hom│PUp│
├───┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─────┤ ├───┼───┼───┤
│ Tab │ Q │ W │ E │ R │ T │ Y │ U │ I │ O │ P │{ [│} ]│ | \ │ │Del│End│PDn│
├─────┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴─────┤ └───┴───┴───┘
│ Caps │ A │ S │ D │ F │ G │ H │ J │ K │ L │: ;│" '│ Enter  │              
├──────┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴────────┤     ┌───┐    
│ Shift  │ Z │ X │ C │ V │ B │ N │ M │< ,│> .│? /│  Shift   │     │ ↑ │    
├─────┬──┴─┬─┴──┬┴───┴───┴───┴───┴───┴──┬┴───┼───┴┬────┬────┤ ┌───┼───┼───┐
│Ctrl │Win │Alt │         Space         │Alt │ Fn │Menu│Ctrl│ │ ← │ ↓ │ → │
└─────┴────┴────┴───────────────────────┴────┴────┴────┴────┘ └───┴───┴───┘


  /\_/\
 (= ._.)
 / >  \>

*/