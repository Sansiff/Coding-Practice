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
typedef vector<vector<int>> VII;
typedef vector<PII> VPII;
void read(VI& a){
    for(int& x : a) cin >> x;
}

void merge(vector<PII> &segs){
    vector<PII> res;
    sort(segs.begin(), segs.end());
    int st = -2e9, ed = -2e9;
    for (auto seg : segs)
        if (ed < seg.first){
            if (st != -2e9) res.push_back({st, ed});
            st = seg.first, ed = seg.second;
        }
        else ed = max(ed, seg.second);

    if (st != -2e9) res.push_back({st, ed});

    segs = res;
}

void solve(){
    int n; cin >> n;
    VI k(n), h(n), t(n); read(k), read(h);
    rep(i, 0, n) t[i] = k[i] - h[i] + 1;
    //for(int x : t) cout << x << ' ';
    //cout << '\n';
    vector<PII> segs;
    rep(i, 0, n){
        //cout << t[i] << ' ' << h[i] << '\n';
        segs.push_back({t[i], k[i]});
    }
    merge(segs);
    int res = 0;
    for(auto x : segs){
        int t = x.second - x.first + 1;
        res += t * (t + 1) / 2;
    }
    cout << res;
    
}

signed main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int _; cin >> _;
    while(_--){
        solve();
        cout << '\n';
    }
    return 0;
}