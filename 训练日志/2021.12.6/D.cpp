#include <bits/stdc++.h>
#define int long long
#define lowbit(x) (x&-x)
#define rep(i, l, r) for(int i = l; i < r; i ++)
#define all(x) (x).begin(),(x).end()
#define fi first
#define se second
using namespace std;
typedef long long LL;
typedef pair<int,int> PII;
typedef vector<int> VI;
int qpow(int a, int b, int p){
    int res = 1;
    while(b){
        if(b & 1) res *= a, b --;
        else a *= a, b /= 2;
    }
    return res;
}

void solve(){
    int n; cin >> n;
    if(n % 4) cout << "NO" << '\n';
    else{
        cout << "YES" << '\n';
        for(int i = 1; i <= n / 2; i ++)
            cout << i * 2 << ' ';
        for(int i = 1; i <= n / 2 - 1; i ++)
            cout << 2 * i - 1 << ' ';
        cout << (n / 2 + 1) * (n / 2) - ((n / 2 - 1) * (n / 2) - n / 2 + 1) <<'\n';
    }
}
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int _; cin >> _;
    while(_ --){
        solve();
    }
    return 0;
}