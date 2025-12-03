//P1253

#include <iostream>
#include <cstdio>
#include <climits>
using namespace std;

typedef long long ll;

int n, q;
ll arr[1000005];

struct node{
	int l, r;
	ll ans, add, cov;
	bool check;
}tree[4000000];


void build(int p, int l, int r){
	tree[p].l = l;
	tree[p].r = r;
	if(l==r){
		tree[p].ans=arr[l];
		return;
	}
	int mid=(l+r)>>1;
	build(p*2, l, mid);
	build(p*2+1, mid+1, r);
	tree[p].ans = max(tree[p*2].ans, tree[p*2+1].ans);
	return;
}


inline void pushDown(int p){
	int lp = p*2;;
	int rp = p*2+1;
	if(tree[p].check){
		tree[lp].add = 0;
		tree[lp].check = 1;
		tree[lp].ans = tree[p].cov;
		tree[lp].cov = tree[p].cov;
		
		tree[rp].add = 0;
		tree[rp].check = 1;
		tree[rp].ans = tree[p].cov;
		tree[rp].cov = tree[p].cov;
		
		tree[p].check = 0;
	}
	
	if(tree[p].add){
		tree[lp].add += tree[p].add;
		tree[rp].add += tree[p].add;
		
		tree[lp].ans += tree[p].add;
		tree[rp].ans += tree[p].add;
		
		tree[p].add=0;
	}
	return;
}


void updatePlus(int p, int x, int y, ll k){
	int l=tree[p].l, r=tree[p].r;
	if(y<l || x>r) return;
	if(x<=l && y>=r){
		tree[p].ans += k;
		tree[p].add += k;
		return;
	}
	pushDown(p);
	updatePlus(p*2,x,y,k);
	updatePlus(p*2+1,x,y,k);
	tree[p].ans = max(tree[p*2].ans, tree[p*2+1].ans);
}


void updateCover(int p, int x, int y, ll k){
	int l=tree[p].l, r=tree[p].r;
	if(y<l || x>r) return;
	if(x<=l && y>=r){
		tree[p].ans = k;
		tree[p].cov = k;
		tree[p].add = 0;
		tree[p].check = 1;
		return;
	}
	pushDown(p);
	updateCover(p*2,x,y,k);
	updateCover(p*2+1,x,y,k);
	tree[p].ans = max(tree[p*2].ans, tree[p*2+1].ans);
}

ll request(int p, int x, int y){
	ll ans=LONG_LONG_MIN;
    int l=tree[p].l, r=tree[p].r;
    
    if(y<l || x>r) return LONG_LONG_MIN;
    
	if(x<=l && y>=r){
		return tree[p].ans;
	}
	pushDown(p);
	
	ans = max(ans, request(p*2, x, y));
	ans = max(ans, request(p*2+1, x, y));
	return ans;
}


int main()
{
	cin >> n >> q;
	for(int i=1 ; i<=n ; ++i)
		scanf("%lld", &arr[i]);
	
	build(1,1,n);
	
	int t, x, y, k;
	while(q--){
		scanf("%d %d %d", &t, &x, &y);
		if(t==3){
			printf("%lld\n", request(1,x,y));
		}else{
			scanf("%d", &k);;
			if(t==1){
				updateCover(1,x,y,k);
			}else{
				updatePlus(1,x,y,k);
			}
		}
	}
	return 0;
}
