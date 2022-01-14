#include <bits/stdc++.h>
#define int long long
#define lowbit(x) (x&-x)
#define PII pair<int,int>
#define fi first
#define se second
using namespace std;
typedef long long LL;

const int mod = 1e9 + 7;
const int N = 2e5 + 10;
int tr[100], s[100];

int qpow(int x, int n){
    int res = 1;
    while(n > 0){
        if(n & 1){
            res = res * x % mod;
            n --;
        }
        else{
            x = x * x % mod;
            n /= 2;
        }
    }
    return res % mod;
}

void solve(){
    int n; cin >> n;
    for(int i = 1; i <= n; i ++){
        int x; cin >> x;
        tr[(int)log2(lowbit(x))] ++;
    }
    int res = 0;
    for(int i = 1; i <= 50; i ++){
        s[i] = s[i - 1] + tr[i];
    }
    for(int i = 1; i <= 50; i ++){
        int t1 = tr[i], t2 = s[50] - s[i];
        if(t1 >= 2){
            res = (res + (qpow(2, t1 - 1) - 1) * qpow(2, t2)) % mod;
        }
    }
    res = (res + (qpow(2, tr[0]) - 1) * qpow(2, s[50] - s[0])) % mod ;
    cout << res;
}

signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
    return 0;
}