#include <bits/stdc++.h>

using i64 = long long;

void solve() {
	int n;
    std::cin >> n;
    std::vector<int> a1(n + 1), a2(n + 1);
    for (int i = 1; i <= n; ++ i) {
        std::cin >> a1[i];
    }

    for (int i = 1; i <= n; ++ i) {
        std::cin >> a2[i];
    }

    constexpr int inf = 1e9;
    std::vector<int> pre_min(n + 1), pre_max(n + 1);
    pre_min[0] = inf;
    pre_max[0] = -inf;
    for (int i = 1; i <= n; ++ i) {
        pre_min[i] = std::min(pre_min[i - 1], a1[i]);
        pre_max[i] = std::max(pre_max[i - 1], a1[i]);
    }

    std::vector<int> suf_min(n + 2), suf_max(n + 2);
    suf_min[n + 1] = inf;
    suf_max[n + 1] = -inf;
    for (int i = n; i >= 1; -- i) {
        suf_min[i] = std::min(suf_min[i + 1], a2[i]);
        suf_max[i] = std::max(suf_max[i + 1], a2[i]);
    }

    std::vector<int> R(2 * n + 1);
    for (int i = 1; i <= n; ++ i) {
        int l = std::min(pre_min[i], suf_min[i]);
        int r = std::max(pre_max[i], suf_max[i]);
        R[r] = std::max(R[r], l);
    }

    i64 ans = 0;
    for (int i = 1; i <= 2 * n; ++ i) {
        R[i] = std::max(R[i], R[i - 1]);
        ans += R[i];
    }
    std::cout << ans << "\n";
}

int main() {
	std::ios::sync_with_stdio(false), std::cin.tie(0), std::cout.tie(0);
	int t = 1;
	std::cin >> t;
	while (t -- ) {
		solve();
	}
	return 0;
}
