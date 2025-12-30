```cpp

// 返回 gcd(a, b)，并找到 x, y 使得 a*x + b*y = gcd(a, b)
ll exgcd(ll a, ll b, ll &x, ll &y) {
    if (b == 0) {
        x = 1;
        y = 0;
        return a; // gcd(a, 0) = a
    }
    ll x1, y1;
    ll g = exgcd(b, a % b, x1, y1);
    // 回溯更新系数
    x = y1;
    y = x1 - (a / b) * y1;
    return g;
}

ll x, y;
ll g = exgcd(a, m, x, y);
// 若 g == 1，则 x 就是 a 在模 m 下的逆元
ll inv = (x % m + m) % m; // 调整到 [0, m) 范围

```

对于 $a \times x + b \times y = x$   
$x \mod g == 0$ 则有解  

设 $k = x / g$, 那么 $x_0 = x \times k$ 和 $y_0 = y \times k$ 是一组特解  
方程通解为 $x_0 + t \times \frac{b}{g} , y_0 - t \times \frac{a}{g} (t \in Z)$
