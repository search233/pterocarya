//P3870

#include <iostream>

using namespace std;

struct node{
	int l, r;
	int sum;
	int tag;
}tree[400010];


void build(int p, int l, int r){
	tree[p].l = l;
	tree[p].r = r;
	if(l==r) return;
	int mid = (l+r)>>1;
	build(p<<1, l, mid);
	build(p<<1|1, mid+1, r);
}


void pushDown(int p){
	int lp=p<<1, rp=p<<1|1;
	if(tree[p].tag){
		tree[lp].tag ^= 1;
		tree[rp].tag ^= 1;
		
		tree[lp].sum = tree[lp].r-tree[lp].l+1-tree[lp].sum;
		tree[rp].sum = tree[rp].r-tree[rp].l+1-tree[rp].sum;
		
		tree[p].tag=0;
	}
}


void update(int p, int a, int b){
	int l=tree[p].l, r=tree[p].r;
	if(a>r || b<l) return;
	if(a<=l && b>=r){
		tree[p].sum = r-l+1-tree[p].sum;
		tree[p].tag ^= 1;
		return;
	}
	
	pushDown(p);
	
	update(p<<1,a,b);
	update(p<<1|1,a,b);
	
	tree[p].sum = tree[p<<1].sum+tree[p<<1|1].sum;
}


int request(int p, int a, int b){
	int ans=0;
	int l=tree[p].l, r=tree[p].r;
	if(a>r || b<l)	return 0;
	if(a<=l && b>=r) return tree[p].sum;
	
	pushDown(p);
	
	ans += request(p<<1,a,b);
	ans += request(p<<1|1,a,b);
	
	return ans;
}


int main(){
	int n, m;
	cin >> n >> m;
	
	build(1,1,n);
	
	int c, a, b;
	while(m--){
		cin >> c >> a >> b;
		if(c){
			cout << request(1,a,b) << '\n';
		}else	update(1,a,b);
	}
	
	return 0;
}
