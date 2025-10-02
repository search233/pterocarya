//P3372

#include <iostream>
#include <cstdio>

using namespace std;
typedef long long ll;

struct Tree{
	ll sum;
	ll add;
	int l, r;
}tree[500000];

ll a[100005];

void build(int p, int l, int r){
	tree[p].l = l;
	tree[p].r = r;
	tree[p].add=0;
	if(l==r){
		tree[p].sum=a[l]; 
		return; 
	}
	
	int mid=(l+r)>>1;
	build(p*2, l, mid);
	build(p*2+1, mid+1, r);
	tree[p].sum = tree[p*2].sum + tree[p*2+1].sum;
}


void pushDown(int p){
	if(tree[p].add){
		tree[p*2].add += tree[p].add;
		tree[p*2].sum += tree[p].add*(tree[p*2].r-tree[p*2].l+1);
		tree[p*2+1].add += tree[p].add;
		tree[p*2+1].sum += tree[p].add*(tree[p*2+1].r-tree[p*2+1].l+1);
		tree[p].add = 0;
	}
}


void update(int p, int x, int y, ll k){
    int l=tree[p].l, r=tree[p].r;
    if(y<l || x>r) return; //检查越界
	if(x<=l && y>=r){
        //当前节点被包含在目标区域内
        //同时也是这一条递推线上的lazytag推到头了，做出与pushdown类似的操作
		tree[p].sum += k * (r-l+1);
		tree[p].add += k;
        //更新完结果和标记后返回
		return;
	}
    //对于大于目标区域的节点：1.下推标记；2.向下递归；
	pushDown(p); 

	update(p*2, x, y, k);
	update(p*2+1, x, y, k) ;
    //返回后向上更新结果
	tree[p].sum = tree[p*2].sum + tree[p*2+1].sum;
}


ll request(int p, int x, int y){
	ll ans=0;
    int l=tree[p].l, r=tree[p].r;
    if(y<l || x>r) return 0;
	if(x<=l && y>=r){
		return tree[p].sum;
	}
	pushDown(p);

	ans += request(p*2, x, y);
	ans += request(p*2+1, x, y);
	return ans;
}


int main()
{
	int n, m; cin >> n >> m;
	for(int i=1 ; i<=n ; ++i)
		scanf("%lld", &a[i]);
	
	build(1, 1, n);
	
	for(int i=0 ; i<m ; ++i){
		ll t, x, y, k;
		scanf("%lld", &t);
		if(t==1){
			scanf("%lld%lld%lld", &x, &y, &k);
			update(1,x,y,k);
		}else{
			scanf("%lld%lld", &x, &y);
			printf("%lld\n", request(1,x,y));
		}
	}
	
	return 0;
}
