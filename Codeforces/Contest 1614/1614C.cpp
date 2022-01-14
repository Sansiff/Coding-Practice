#include <bits/stdc++.h>
#define int long long 
using namespace std;

const int MOD = 1e9 + 7;

int qpow(int a, int b){
    int res = 1;
    while(b){
        if(b & 1) (res *= a) %= MOD, b --;
        else (a *= a) %= MOD, b >>= 1;
    }
    return res % MOD;
}

void solve(){
    int n, m; cin >> n >> m;
    int tot = 0;
    while(m --){
        int l, r, v; cin >> l >> r >> v;
        tot |= v;
    }
    cout << (tot * qpow(2, n - 1)) % MOD;
}

signed main()
{
    int _; cin >> _;
    while(_ --){
        solve();
        cout << '\n';
    }
    return 0;
}