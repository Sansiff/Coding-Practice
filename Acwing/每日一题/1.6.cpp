// 2014. 岛
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
typedef vector<PII> VII;
signed main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n; cin >> n;
    VI h(n);
    for(int& x : h) cin >> x;
    n = unique(all(h)) - h.begin();
    VII g(n);
    rep(i, 0, n) g[i].fi = h[i], g[i].se = i;
    sort(all(g));
    int cnt = 1, res = 1;
    rep(i, 0, n){
        int p = g[i].se;
        if(p == 0) {
            if(h[1] < h[0]) cnt --;
        }
        else if(h[p + 1] > h[p] && h[p - 1] > h[p]) cnt ++;
        else if(h[p + 1] < h[p] && h[p - 1] < h[p]) cnt --;
        if(g[i].fi != g[i + 1].fi)
            res = max(res, cnt);
    }    
    cout << res;
    return 0;
}