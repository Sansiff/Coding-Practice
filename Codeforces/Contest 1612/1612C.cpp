#include <bits/stdc++.h>
#define int long long
#define lowbit(x) (x&-x)
#define PII pair<int,int>
#define fi first
#define se second
using namespace std;
typedef long long LL;

const int N = 1e5 + 10;

int fuc(int n){
    return (n + 1) * n / 2;
}

void solve(){
    int n, m; cin >> n >> m;
    int l = 1, r = 2 * n - 1, ans = 2 * n - 1;
    while(l <= r){
        int mid = l + r >> 1, qwq = 0;
        if(mid <= n) qwq = fuc(mid);
        else{
            int t = 2 * n - 1 - mid;
            qwq = fuc(n) + fuc(n - 1) - fuc(t);
        }
        if(qwq >= m) ans = mid, r = mid - 1;
        else l = mid + 1;
    }
    cout << ans;
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