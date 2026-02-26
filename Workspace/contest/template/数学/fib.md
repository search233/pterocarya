
```cpp
// 返回 {F(n), F(n+1)}

arr2 fib(ll n) {
    if (n == 0) return {0, 1};

    auto [a, b] = fib(n >> 1); // F(k), F(k+1)

    ll c = mod(mod(mod(2 * b) - a) * a);        // F(2k)
    ll d = mod(mod(a * a) + mod(b * b));          // F(2k+1)

    if (n & 1) 
        return {d, c + d};         // F(2k+1), F(2k+2)
    else
        return {c, d};
}

```
