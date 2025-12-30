```cpp

#include <bits/stdc++.h>
using namespace std;

using ll = long long;
const ll INF = LLONG_MAX;

struct Dijkstra {
    struct Edge {
        int to;
        ll w;
    };

    int n;                              // 节点数量
    vector<vector<Edge>> graph;         // 邻接表
    vector<ll> dist;                    // 最短距离
    vector<int> parent;                 // 记录路径（可选）

    Dijkstra(int n) : n(n) {
        graph.resize(n + 1);
        dist.resize(n + 1);
        parent.resize(n + 1);
    }

    void add_edge(int u, int v, ll w) {
        graph[u].push_back({v, w});
    }

    // 单源最短路
    void run(int s) {
        priority_queue<pair<ll,int>, vector<pair<ll,int>>, greater<>> pq;

        fill(dist.begin(), dist.end(), INF);
        fill(parent.begin(), parent.end(), -1);

        dist[s] = 0;
        pq.push({0, s});

        while (!pq.empty()) {
            auto [d, u] = pq.top();
            pq.pop();

            if (d > dist[u]) continue;  // 懒删除

            for (auto &e : graph[u]) {
                int v = e.to;
                ll w = e.w;

                if (dist[v] > dist[u] + w) {
                    dist[v] = dist[u] + w;
                    parent[v] = u;
                    pq.push({dist[v], v});
                }
            }
        }
    }

    // 还原路径（s -> t）
    vector<int> get_path(int t) {
        vector<int> path;
        while (t != -1) {
            path.push_back(t);
            t = parent[t];
        }
        reverse(path.begin(), path.end());
        return path;
    }
};

```