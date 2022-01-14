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
const int N = 1e5 + 10;
int n, h, a[N];

bool check(int x){
    int res = 0;
    for(int i = 1; i <= n; i ++){
        if(a[i + 1] - a[i] >= x) res += x;
        else res += a[i + 1] - a[i];
    }
    return res >= h;
}

void solve(){
    int u, l, r; cin >> u >> l >> r;

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