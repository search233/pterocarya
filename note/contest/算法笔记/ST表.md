# ST表

> ST 表（Sparse Table，稀疏表）是用于解决 **可重复贡献问题** 的数据结构。 
>
> ST表基于倍增思想，预处理时间复杂度O(nlogn)，O(1)处理每个询问。但是不支持修改操作。																	——oi wiki



## 实现思路：



### 预处理

- 令$f(i,j)$表示区间$[i,i+2^j-1]$的最大值（那么就有$f(i,0)=a_i$)
- 根据定义式，第二维就相当于倍增的时候「跳了 $2^j-1$步」
- 状态转移方程：$f(i,j)=max(f(i,j-1), f(i+2^{j-1}, j-1))$

不难发现，ST表类似于区间DP，是由两个小区间合并上来的。

**所以应该先枚举区间长度 j，再枚举 i。**



那么对于每个区间长度 j，需要确定一个 i 的区间。即$[1,n-2^j+1]$，那么就有：

```cpp
	for (int j=1;j<=lg[n];j++)
		for (int i=1;i<=n-(1<<j)+1;i++)
```



### 查询

- 对于每个询问$[l,r]$，将其分为$[l,l+2^s-1]$和$[r-2^s+1,r]$两部分（$s=log(r-l+1)$)



## 代码模板：

```cpp
#include <algorithm>
#include <iostream>
using namespace std;
int n, m;
const int MAXN = 2000001;
const int logN = 21;
int f[MAXN][logN + 1], Logn[MAXN + 1];

void pre() {  // 准备工作，初始化
	for(int i=2 ; i<=n ; ++i) 
        Logn[i] = Logn[i>>1] +1;
}

int main() {
  cin >> n >> m;
  for (int i = 1; i <= n; ++i) cin >> f[i][0];
    
  pre();
    
  for (int j=1 ; j<=Logn[n] ; ++j)
    for (int i=1 ; i<=n-(1<<j)+1 ; ++i)
      f[i][j] = max( f[i][j-1], f[ i+(1<<(j-1)) ][j-1] );  // ST表具体实现
    
  for (int i=1; i<=m; ++i) {
    int x, y;
    cin >> x >> y;
    int s = Logn[y - x + 1];
    cout << max(f[x][s], f[y-(1<<s)+1][s]) << '\n';
  }
  return 0;
}
```