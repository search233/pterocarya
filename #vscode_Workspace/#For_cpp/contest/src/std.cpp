#include <bits/stdc++.h>
using namespace std;
using arr2 = array<int, 2>;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, h;
    cin >> n >> h;
    stack<arr2> st;        // 0: t; 1: time
    int time = 0;                   // 有效任务已用时间
    int eaten = 0;
    string s;                       // 构造串
    vector<int> trash;              // 垃圾桶任务编号

    for (int i = 1; i <= n; ++i) {
        int op;  cin >> op;
        if (op == 0) {
            int t; cin >> t;
            if ((int)st.size() == h) {
                s += to_string(i);   // 满罐，忽略
                continue;
            }
            ++time;
            st.emplace(t, time);
        } else {   // op == 1
            if (st.empty()) {
                s += to_string(i);   // 空罐，忽略
                continue;
            }
            ++time;
            auto [t, pt] = st.top(); st.pop();
            if (time > pt + t - 1) {          // 已过期
                s += '!';
                trash.push_back(i);
            } else {
                ++eaten;
            }
        }
    }

    // 输出三行
    cout << s << '\n';
    cout << eaten << '\n';
    for (int i = 0; i < (int)trash.size(); ++i) {
        if (i) cout << ' ';
        cout << trash[i];
    }
    if (!trash.empty()) cout << '\n';
    return 0;
}