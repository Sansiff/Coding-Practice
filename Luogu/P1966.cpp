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

const int N = 1e5 + 10, mod = 99999997;
struct SegmentTree{
    int val[N << 2];
    void pushup(int u){
        val[u] = val[u << 1] + val[u << 1 | 1];
    }
    void build(int u, int l, int r){
        val[u] = 0;
        if(l == r) return;
        int mid = l + r >> 1;
        build(u << 1, l, mid), build(u << 1 | 1, mid + 1, r);
        pushup(u);
    }
    void modify(int u, int l, int r, int x, int k){
        if(l == r){
            val[u] = k; return;
        }
        int mid = l + r >> 1;
        if(x <= mid) modify(u << 1, l, mid, x, k);
        if(x > mid) modify(u << 1 | 1, mid + 1, r, x, k);
        pushup(u);
    }
    int query(int u, int l, int r, int L, int R){
        if(L <= l && r <= R) return val[u];
        int mid = l + r >> 1;
        int res = 0;
        if(L <= mid) res += query(u << 1, l, mid, L, R);
        if(R > mid) res += query(u << 1 | 1, mid + 1, r, L, R);
        return res;
    }
}t;

int find(VI& v, int& x){
    return lower_bound(all(v), x) - v.begin();
}

signed main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    //freopen("1.in", "r", stdin);
    // 97187296
    int n; cin >> n;
    t.build(1, 1, n);
    VPII a(n + 1), b(n + 1); VI c(n + 1);
    for(int i = 1; i <= n; i ++) cin >> a[i].fi, a[i].se = i;
    for(int i = 1; i <= n; i ++) cin >> b[i].fi, b[i].se = i;
    sort(all(a)), sort(all(b));
    for(int i = 1; i <= n; i ++){
        c[a[i].se] = b[i].se;
    }
    int ans = 0;
    for(int i = 1; i <= n; i ++){
        (ans += i - t.query(1, 1, n, 1, c[i]) - 1) %= mod;
        t.modify(1, 1, n, c[i], 1);
    }
    cout << ans;

    return 0;
}