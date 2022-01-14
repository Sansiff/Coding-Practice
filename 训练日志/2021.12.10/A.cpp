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
    vector<int> a(5);
    int n; cin >> n;
    for(int i = 1; i <= n; i ++){
        int x; cin >> x;
        a[x % 3] ++;
    }
    int res = 0, t = n / 3;
    while(a[0] != t || a[1] != t || a[2] != t){
        res ++;
        if(a[0] > t) a[0] --, a[1] ++;
        else if(a[1] > t) a[1] --, a[2] ++;
        else a[2] --, a[0] ++;
    }
    cout << res;
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