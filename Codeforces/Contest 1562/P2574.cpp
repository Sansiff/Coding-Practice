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

const int N = 2e5 + 10;
string s;
struct SegmentTree{
    int ls[N << 2], rs[N << 2], val[N << 2], f[N << 2];
    void pushup(int u){
        val[u] = val[u << 1] + val[u << 1 | 1];
    }
    void build(int u, int l, int r){
        ls[u] = l, rs[u] = r, val[u] = s[r] - '0', f[u] = 0;
        if(l == r) return;
        int mid = l + r >> 1;
        build(u << 1, l, mid), build(u << 1 | 1, mid + 1, r);
        pushup(u);
    }
    void pushdown(int u){
        if(f[u]){
            f[u << 1] ^= 1, f[u << 1 | 1] ^= 1;
            val[u << 1] = rs[u << 1] - ls[u << 1] + 1 - val[u << 1];
            val[u << 1 | 1] = rs[u << 1 | 1] - ls[u << 1 | 1]  + 1 - val[u << 1 | 1]; 
            f[u] = 0;
        }
    }
    void modify(int u, int l, int r){
        if(l <= ls[u] && rs[u] <= r){
            f[u] ^= 1; val[u] = rs[u] - ls[u] + 1 - val[u];
            return;
        }
        pushdown(u);
        int mid = ls[u] + rs[u] >> 1;
        if(l <= mid) modify(u << 1, l, r);
        if(r > mid) modify(u << 1 | 1, l, r);
        pushup(u);
    }
    int query(int u, int l, int r){
        if(l <= ls[u] && rs[u] <= r) return val[u];
        int mid = ls[u] + rs[u] >> 1;
        pushdown(u);
        int res = 0;
        if(l <= mid) res += query(u << 1, l, r);
        if(r > mid) res += query(u << 1 | 1, l, r);
        return res;
    }
}sgt;
signed main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, m; cin >> n >> m;
    cin >> s; s = ' ' + s;
    sgt.build(1, 1, n);
    while(m --){
        int op, l, r; cin >> op >> l >> r;
        if(op) cout << sgt.query(1, l, r) << '\n';
        else sgt.modify(1, l, r);
    }
    return 0;
}