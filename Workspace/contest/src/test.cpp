#include <iostream>
#include <string>
#include <vector>

using namespace std;

void solve() {
    int n;
    cin >> n;
    string s, t;
    cin >> s >> t;

    int leaves_s = 0, leaves_t = 0;
    for (int i = 0; i < n - 1; ++i) {
        if (s[i] == '(' && s[i + 1] == ')') leaves_s++;
        if (t[i] == '(' && t[i + 1] == ')') leaves_t++;
    }

    if (leaves_s != leaves_t) {
        cout << "NO\n";
        return;
    }

 
    vector<int> match_s(n), match_t(n);
    vector<int> st;
    for (int i = 0; i < n; ++i) {
        if (s[i] == '(') {
            st.push_back(i);
        }
        else {
            int j = st.back();
            st.pop_back();
            match_s[j] = i;
            match_s[i] = j;
        }
    }

    st.clear();
    for (int i = 0; i < n; ++i) {
        if (t[i] == '(') {
            st.push_back(i);
        }
        else {
            int j = st.back();
            st.pop_back();
            match_t[j] = i;
            match_t[i] = j;
        }
    }

  
    int l = 0, r = n - 1;
    while (l < r) {
        bool k1_s = (match_s[l] == r);
        bool k1_t = (match_t[l] == r);

        if (k1_s && k1_t) {
            l++;
            r--;
        }
        else if (k1_s != k1_t) {
            cout << "NO\n";
            return;
        }
        else {
            cout << "YES\n";
            return;
        }
    }

    cout << "YES\n";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    if (cin >> t) {
        while (t--) {
            solve();
        }
    }
    return 0;
}