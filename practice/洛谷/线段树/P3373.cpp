//P3373

#include <iostream>

using namespace std;
typedef long long ll;

int n, m, q;

struct node{
	int l, r;
	ll sum, add, mul;
}tree[400020];

ll arr[100001];

void build(int p, int l, int r){
	tree[p].l = l;
	tree[p].r = r;
	tree[p].add=0;
	tree[p].mul=1;
	if(l==r){
		tree[p].sum = arr[l];
		return;
	}
	int mid = (l+r)>>1;
	build(p*2, l, mid);
	build(p*2+1, mid+1, r);
	tree[p].sum = (tree[p*2].sum+tree[p*2+1].sum)%m;
	return;
}


void pushDown(int p){

	tree[p*2].sum = (tree[p*2].sum * tree[p].mul + tree[p].add * (tree[p*2].r-tree[p*2].l+1))%m;
	tree[p*2+1].sum = (tree[p*2+1].sum * tree[p].mul + tree[p].add * (tree[p*2+1].r-tree[p*2+1].l+1))%m;
	
	tree[p*2].mul = (tree[p*2].mul*tree[p].mul)%m;
	tree[p*2+1].mul = (tree[p*2+1].mul*tree[p].mul)%m;
	tree[p*2].add = (tree[p*2].add*tree[p].mul + tree[p].add)%m;
	tree[p*2+1].add = (tree[p*2+1].add*tree[p].mul + tree[p].add)%m;
	
	tree[p].mul=1;
	tree[p].add=0;
	return;
}


void updatePlus(int p, int x, int y, ll k){
	int l=tree[p].l, r=tree[p].r;
	if(y<l || x>r) return;
	if(x<=l && y>=r){
		tree[p].sum = (tree[p].sum + k*(r-l+1))%m;
		tree[p].add = (tree[p].add + k)%m;
		return;
	}
	pushDown(p);

	updatePlus(p*2, x, y, k);
	updatePlus(p*2+1, x, y, k);
	tree[p].sum = (tree[p*2].sum+tree[p*2+1].sum)%m;
	return;
}


void updateTimes(int p, int x, int y, ll k){
	int l=tree[p].l, r=tree[p].r;
	if(y<l || x>r) return;
	if(x<=l && y>=r){
		tree[p].sum = (tree[p].sum * k) %m;
		tree[p].add = (tree[p].add * k) %m;
		tree[p].mul = (tree[p].mul * k) %m;
		return;
	}
	pushDown(p);

	updateTimes(p*2, x, y, k);
	updateTimes(p*2+1, x, y, k);
	tree[p].sum = (tree[p*2].sum+tree[p*2+1].sum)%m;
	return;
}

ll request(int p, int x, int y){
	ll ans=0;
	int l=tree[p].l, r=tree[p].r;
	
	if(y<l || x>r) return 0;
	
	if(x<=l && y>=r){
		return tree[p].sum;
	}
	pushDown(p);

	ans = (ans+request(p*2, x, y))%m;
	ans = (ans+request(p*2+1, x, y))%m;
	return ans;
}

int main()
{
	cin >> n >> q >> m;
	for(int i=1 ; i<=n ; ++i) cin >> arr[i];
	
	build(1,1,n);
	
	int t, x, y, k;
	while(q--){
		cin >> t >> x >> y;
		if(t==3){
			cout << request(1,x,y) << '\n';
			
		}else{
			cin >> k;
			
			if(t==1){
				updateTimes(1,x,y,k);
			}else{
				updatePlus(1,x,y,k);
			}
		}
	}
	
	return 0;
}

