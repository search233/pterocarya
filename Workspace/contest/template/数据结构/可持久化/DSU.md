```cpp

struct PArray {

    struct Node {
        int l = 0, r = 0;
        int val = 0;
    };

    vector<Node> tr;
    int n;

    PArray(int n) : n(n) {
        tr.push_back(Node()); // 0号空节点
    }

    int clone(int x) {
        tr.push_back(tr[x]);
        return tr.size() - 1;
    }

    int build(int l, int r, const vector<int>& a) {
        int node = tr.size();
        tr.push_back(Node());

        if (l == r) {
            tr[node].val = a[l];
            return node;
        }

        int mid = (l + r) >> 1;
        tr[node].l = build(l, mid, a);
        tr[node].r = build(mid+1, r, a);
        return node;
    }

    int update(int pre, int l, int r, int pos, int val) {
        int node = clone(pre);

        if (l == r) {
            tr[node].val = val;
            return node;
        }

        int mid = (l + r) >> 1;

        if (pos <= mid)
            tr[node].l = update(tr[pre].l, l, mid, pos, val);
        else
            tr[node].r = update(tr[pre].r, mid+1, r, pos, val);

        return node;
    }

    int query(int node, int l, int r, int pos) {
        if (l == r) return tr[node].val;

        int mid = (l + r) >> 1;

        if (pos <= mid)
            return query(tr[node].l, l, mid, pos);
        else
            return query(tr[node].r, mid+1, r, pos);
    }
};

struct PDSU {

    int n;

    PArray fa, sz;

    vector<int> root_fa;
    vector<int> root_sz;

    PDSU(int n)
        : n(n), fa(n), sz(n)
    {
        vector<int> init_fa(n+1);
        vector<int> init_sz(n+1, 1);

        for (int i = 1; i <= n; i++)
            init_fa[i] = i;

        root_fa.push_back(fa.build(1,n,init_fa));
        root_sz.push_back(sz.build(1,n,init_sz));
    }

    // ===== 查找祖先（无路径压缩）=====
    int find(int root, int x) {
        int f = fa.query(root,1,n,x);
        if (f == x) return x;
        return find(root, f);
    }

    // ===== 合并 =====
    void unite(int version, int x, int y) {

        int fa_root = root_fa[version];
        int sz_root = root_sz[version];

        x = find(fa_root, x);
        y = find(fa_root, y);

        if (x == y) {
            root_fa.push_back(fa_root);
            root_sz.push_back(sz_root);
            return;
        }

        int sx = sz.query(sz_root,1,n,x);
        int sy = sz.query(sz_root,1,n,y);

        if (sx < sy) swap(x,y);

        // y 挂到 x
        int new_fa =
            fa.update(fa_root,1,n,y,x);

        int new_sz =
            sz.update(sz_root,1,n,x,sx+sy);

        root_fa.push_back(new_fa);
        root_sz.push_back(new_sz);
    }

    // ===== 是否连通 =====
    bool same(int version, int x, int y) {
        int root = root_fa[version];
        return find(root,x) == find(root,y);
    }
};

void solve() {
    int n; cin >> n;
    vector<int> a(n);

    //初始化
    PDSU dsu(n);
    //hebing
    int version,  x,  y;
    dsu.unite(version, x, y);

    //查询 在该版本是否联通
    dsu.same(version, x, y);

} 

```
