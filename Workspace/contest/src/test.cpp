#include <bits/stdc++.h>
#include <cassert>
#define __BUFF__ ios::sync_with_stdio(false);cin.tie(0);

using namespace std;
using ll = long long;
using uint = uint32_t;
using ull = uint64_t;
using arr2 = array<int, 2>;
using arr3 = array<int, 3>;
const double PI = acos(-1.0);

void solve() {
    int n;
    cin >> n;
    vector<array<ll, 2>> a(n + 2); // 存储每个区间的两个端点
    vector<ll> val(n + 2);         // val[i] = min(a[i][0], a[i][1])

    for (int i = 1; i <= n; i++) {
        cin >> a[i][0];
    }
    for (int i = 1; i <= n; i++) {
        cin >> a[i][1];
    }
    for (int i = 1; i <= n; i++) {
        val[i] = min(a[i][0], a[i][1]);
    }

    // --------------------------
    // O(n) 单调栈构建大根笛卡尔树
    // --------------------------
    vector<int> l(n + 2, 0), r(n + 2, 0); // 左右孩子指针（0表示空节点）
    stack<int> stk;
    int root = 0;

    for (int i = 1; i <= n; i++) {
        int last = 0;
        // 弹出所有比当前节点小的栈顶元素，作为当前节点的左子树
        while (!stk.empty() && val[stk.top()] < val[i]) {
            last = stk.top();
            stk.pop();
        }
        if (!stk.empty()) {
            r[stk.top()] = i; // 当前节点作为栈顶的右孩子
        } else {
            root = i; // 栈空，当前节点为整棵树的根
        }
        l[i] = last;
        stk.push(i);
    }

    // 核心合并函数（与原代码100%等价）
    auto cal = [&](const array<ll, 2>& x, const array<ll, 2>& y) -> array<ll, 2> {
        ll mnx = min(x[0], x[1]);
        ll mxx = max(x[0], x[1]);
        ll mny = min(y[0], y[1]);
        ll mxy = max(y[0], y[1]);
        return {min(mxx, mxy), max(mnx, mny)};
    };

    // --------------------------
    // 递归后序遍历合并（代码更简洁）
    // --------------------------
    function<array<ll, 2>(int)> dfs = [&](int u) -> array<ll, 2> {
        // 递归终止条件：空节点（不会被实际调用，仅作防御）
        if (u == 0) return {0, 0};

        // 叶子节点：直接返回自身
        if (!l[u] && !r[u]) {
            return a[u];
        }

        // 先递归处理左右子树（后序遍历：左→右→根）
        array<ll, 2> ls = {0, 0}, rs = {0, 0};
        if (l[u]) ls = dfs(l[u]);
        if (r[u]) rs = dfs(r[u]);

        // 合并逻辑与原代码完全一致
        if (!l[u]) {
            // 只有右子树：合并右子树结果与当前节点
            return cal(rs, a[u]);
        } else if (!r[u]) {
            // 只有左子树：合并左子树结果与当前节点
            return cal(ls, a[u]);
        } else {
            // 左右子树都有：先合并左端点较小的子树
            ll l_min = min(ls[0], ls[1]);
            ll r_min = min(rs[0], rs[1]);
            if (l_min <= r_min) {
                return cal(cal(ls, a[u]), rs);
            } else {
                return cal(cal(rs, a[u]), ls);
            }
        }
    };

    array<ll, 2> ans = dfs(root);
    cout << min(ans[0], ans[1]) << '\n';
}

int main() {
    
    __BUFF__

    int _ = 1;
    cin >> _;

    while (_--) {
        solve();
        // cout << "-----------\n";
    }

    return 0;
}
/*
 ███████████  ███████████ ██████████ ███████████      ███████      █████████    █████████   ███████████   █████ █████ ███████████
░░███░░░░░███░█░░░███░░░█░░███░░░░░█░░███░░░░░███   ███░░░░░███   ███░░░░░███  ███░░░░░███ ░░███░░░░░███ ░░███ ░░███ ░█░░░░░░███ 
 ░███    ░███░   ░███  ░  ░███  █ ░  ░███    ░███  ███     ░░███ ███     ░░░  ░███    ░███  ░███    ░███  ░░███ ███  ░     ███░  
 ░██████████     ░███     ░██████    ░██████████  ░███      ░███░███          ░███████████  ░██████████    ░░█████        ███    
 ░███░░░░░░      ░███     ░███░░█    ░███░░░░░███ ░███      ░███░███          ░███░░░░░███  ░███░░░░░███    ░░███        ███     
 ░███            ░███     ░███ ░   █ ░███    ░███ ░░███     ███ ░░███     ███ ░███    ░███  ░███    ░███     ░███      ████     █
 █████           █████    ██████████ █████   █████ ░░░███████░   ░░█████████  █████   █████ █████   █████    █████    ███████████
░░░░░           ░░░░░    ░░░░░░░░░░ ░░░░░   ░░░░░    ░░░░░░░      ░░░░░░░░░  ░░░░░   ░░░░░ ░░░░░   ░░░░░    ░░░░░    ░░░░░░░░░░░
*/