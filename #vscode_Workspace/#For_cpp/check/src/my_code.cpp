#include <bits/stdc++.h>
using namespace std;
 
int n, m;
 
int main() {
    cin >> n >> m;
    basic_string<int> a(n, 0);
    for (int& x : a) cin >> x;
    for (int op, l1, l2, l, r; m--;) {
        cin >> op;
        if (op == 1) {
            cin >> l1;
            basic_string<int> s1(l1, 0);
            for (int& x : s1) cin >> x;
            cin >> l2;
            basic_string<int> s2(l2, 0);
            for (int& x : s2) cin >> x;
            int p = a.find(s1);
            if (p != a.npos) a.replace(p, l1, s2);
        }
        if (op == 2)
            for (int i = a.size() - 2; i >= 0; i--)
                if ((a[i] + a[i + 1]) % 2 == 0)
                    a.insert(i + 1, {(a[i] + a[i + 1]) / 2});
        if (op == 3) {
            cin >> l >> r;
            for (int i = l - 1, j = r - 1; i < j; i++, j--)
                swap(a[i], a[j]);
        }
    }
    for (int i = 0; int x : a)
        cout << x << " \n"[++i == a.size()];
    return 0;
}