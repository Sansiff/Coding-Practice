#include <bits/stdc++.h>
#define int long long 

const int N = 1e6 + 10;

using namespace std;

int n, m, w[N];

struct node{
    int l, r;
    int add, sum;
}tr[N * 4];

void pushup(int u){
    tr[u].sum = tr[u << 1].sum + tr[u << 1 | 1].sum;
}

void pushdown(int u){
    tr[u << 1].add += tr[u].add;
    tr[u << 1].sum += (tr[u << 1].r - tr[u << 1].l + 1) * tr[u].add;
    tr[u << 1 | 1].add += tr[u].add;
    tr[u << 1 | 1].sum += (tr[u << 1 | 1].r - tr[u << 1 | 1].l + 1) * tr[u].add;
    tr[u].add = 0;
}

void build(int u, int l, int r){
    tr[u] = {l, r, 0};
    if(l == r){
        tr[u].sum = w[r] - w[r - 1];
        return;
    }
    int mid = l + r >> 1;
    build(u << 1, l, mid), build(u << 1 | 1, mid + 1, r);
    pushup(u);
}

void modify(int u, int l, int r, int d){
    if(l <= tr[u].l && tr[u].r <= r){
        tr[u].add += d;
        tr[u].sum += (tr[u].r - tr[u].l + 1) * d;
        return;
    }

    pushdown(u);
    int mid = tr[u].l + tr[u].r >> 1;
    if(l <= mid) modify(u << 1, l, r, d);
    if(r > mid) modify(u << 1 | 1, l, r, d);
    pushup(u);
}

int query(int u, int l, int r){
    if(l <= tr[u].l && tr[u].r <= r) return tr[u].sum;
    
    pushdown(u);
    int res = 0;
    int mid = tr[u].r + tr[u].l >> 1;
    if(l <= mid) res += query(u << 1, l, r);
    if(r > mid) res += query(u << 1 | 1, l, r);
    return res;
}

int32_t main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    cin >> n >> m;
    for(int i = 1; i <= n; i ++) cin >> w[i];
    build(1, 1, n);

    while(m --){
        int op; cin >> op;
        if(op == 1){
            int l, r, k, d; cin >> l >> r >> k >> d;
            modify(1, l, l, k);
            if(l < r) modify(1, l + 1, r, d);
            if(r < n) modify(1, r + 1, r + 1, -(k + (r - l) * d));
        }
        else{
            int p; cin >> p;
            cout << query(1, 1, p) << endl;
        }
    }

    return 0;
}