#include <bits/stdc++.h>
using namespace std;

struct Country {
    int gid;          // 原始输入序号
    int gold, medal;  // 金牌、奖牌
    double pop;       // 人口（百万）
    int rk[5];        // rk[1] 金牌榜, rk[2] 奖牌榜, rk[3] 人均金牌, rk[4] 人均奖牌
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N, M;
    if (!(cin >> N >> M)) return 0;
    vector<Country> a(N);
    for (int i = 0; i < N; i++) {
        cin >> a[i].gold >> a[i].medal >> a[i].pop;
        a[i].gid = i;
    }

    // 先定义 equal_keys，供 buildRank 内部使用
    auto equal_keys = [&](int mode, int x, int y) -> bool {
        switch (mode) {
        case 1: return a[x].gold == a[y].gold;
        case 2: return a[x].medal == a[y].medal;
        case 3: {
            double vx = (a[x].pop == 0 ? -1 : 1.0 * a[x].gold / a[x].pop);
            double vy = (a[y].pop == 0 ? -1 : 1.0 * a[y].gold / a[y].pop);
            return vx == vy;
        }
        case 4: {
            double vx = (a[x].pop == 0 ? -1 : 1.0 * a[x].medal / a[x].pop);
            double vy = (a[y].pop == 0 ? -1 : 1.0 * a[y].medal / a[y].pop);
            return vx == vy;
        }
        }
        return false;
    };

    auto buildRank = [&](int mode) {
        vector<int> ord(N);
        iota(ord.begin(), ord.end(), 0);
        switch (mode) {
        case 1: // 金牌榜
            sort(ord.begin(), ord.end(), [&](int x, int y) {
                return a[x].gold > a[y].gold;
            });
            break;
        case 2: // 奖牌榜
            sort(ord.begin(), ord.end(), [&](int x, int y) {
                return a[x].medal > a[y].medal;
            });
            break;
        case 3: // 人均金牌
            sort(ord.begin(), ord.end(), [&](int x, int y) {
                double vx = (a[x].pop == 0 ? -1 : 1.0 * a[x].gold / a[x].pop);
                double vy = (a[y].pop == 0 ? -1 : 1.0 * a[y].gold / a[y].pop);
                return vx > vy;
            });
            break;
        case 4: // 人均奖牌
            sort(ord.begin(), ord.end(), [&](int x, int y) {
                double vx = (a[x].pop == 0 ? -1 : 1.0 * a[x].medal / a[x].pop);
                double vy = (a[y].pop == 0 ? -1 : 1.0 * a[y].medal / a[y].pop);
                return vx > vy;
            });
            break;
        }
        // 填名次（并列同分同名次）
        for (int i = 0, r = 1; i < N; ) {
            int j = i;
            while (j < N && equal_keys(mode, ord[i], ord[j])) ++j;
            for (int k = i; k < j; k++) a[ord[k]].rk[mode] = r;
            r += (j - i);
            i = j;
        }
    };

    for (int m = 1; m <= 4; ++m) buildRank(m);

    // 处理咨询
    vector<int> q(M);
    for (int i = 0; i < M; i++) cin >> q[i];

    for (int i = 0; i < M; i++) {
        int id = q[i];
        int bestMode = 1, bestRk = a[id].rk[1];
        for (int m = 2; m <= 4; m++) {
            if (a[id].rk[m] < bestRk) {
                bestRk = a[id].rk[m];
                bestMode = m;
            } else if (a[id].rk[m] == bestRk && m < bestMode) {
                bestMode = m;
            }
        }
        if (i) cout << ' ';
        cout << bestRk << ':' << bestMode;
    }
    cout << '\n';
    return 0;
}