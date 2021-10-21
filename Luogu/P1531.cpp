#include <bits/stdc++.h>
#define int long long 

using namespace std;

const int N = 2e5 + 10;

int n, m, w[N];

struct node{
    int l, r;
    int v;
}tr[N * 4];

void pushup(int u){
    tr[u].v = max(tr[u << 1].v, tr[u << 1 | 1].v);
}

void build(int u, int l, int r){
    if(l == r){
        tr[u] = {l, r, w[l]};
        return;
    }
    else{
        tr[u] = {l, r};
        int mid = l + r >> 1;
        build(u << 1, l, mid), build(u << 1 | 1, mid + 1, r);
        pushup(u);
    }
}

void modify(int u, int x, int k){
    if(tr[u].l == x && tr[u].r == x){
        tr[u].v = k;
        return;
    }
    else{
        int mid = tr[u].l + tr[u].r >> 1;
        if(x <= mid) modify(u << 1, x, k);
        if(x > mid) modify(u << 1 | 1, x, k);
        pushup(u);
    }
}

int query(int u, int l, int r){
    if(l <= tr[u].l && tr[u].r <= r) return tr[u].v;

    int res = -1e9;
    int mid = tr[u].l + tr[u].r >> 1;
    if(l <= mid) res = max(res, query(u << 1, l, r));
    if(r > mid) res = max(res, query(u << 1 | 1, l, r));
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
        char c; int a, b;
        cin >> c >> a >> b;
        if(c == 'Q') cout << query(1, a, b) << endl;
        else if(w[a] < b){
            modify(1, a, b);
            w[a] = b;
        }
    }
    return 0;
}