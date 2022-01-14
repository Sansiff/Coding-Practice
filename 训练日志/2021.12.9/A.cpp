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
    int res = 0;
    for(int i = 1; i <= n; i ++){
        int x; cin >> x;
        res += x;
    }
    if(res > n - res){
        if(res & 1) res --;
        cout << res << '\n';
        for(int i = 1; i <= res; i ++){
            cout << 1 << ' ';
        }
    }
    else{
        res = n - res;
        cout << res << '\n';
        for(int i = 1; i <= res; i ++){
            cout << 0 << ' ';
        }
    }
}
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int _; cin >> _;
    while(_ --){
        solve();
        cout << '\n';
    }
    return 0;
}