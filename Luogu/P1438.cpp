#include <bits/stdc++.h>
#define int long long 
using namespace std;

const int N = 1e6 + 10;

struct node{
    int l, r;
    int sum, add;
}tr[N * 4];

int n, m, w[N];

void pushup(int u){
    tr[u].sum = tr[u << 1].sum + tr[u << 1 | 1].sum;
}

void pushdown(int u){
    node &root = tr[u];
    node &left = tr[u << 1], &right = tr[u << 1 | 1];
    if(root.add){
        left.sum += (left.r - left.l + 1) * root.add;
        right.sum += (right.r - right.l + 1) * root.add;
        left.add += root.add, right.add += root.add;
        root.add = 0;
    }
}

void build(int u, int l, int r){
    if(l == r){
        tr[u] = {l, r, w[l] - w[l - 1], 0};
        return;
    }
    tr[u] = {l, r};
    int mid = l + r >> 1;
    build(u << 1, l, mid), build(u << 1 | 1, mid + 1, r);
    pushup(u);
}

void modify(int u, int l, int r, int k){
    if(l <= tr[u].l && tr[u].r <= r){
        tr[u].add += k;
        tr[u].sum += (tr[u].r - tr[u].l + 1) * k;
        return;
    }
    pushdown(u);
    int mid = tr[u].l + tr[u].r >> 1;
    if(l <= mid) modify(u << 1, l, r, k);
    if(r > mid) modify(u << 1 | 1, l, r, k);
    pushup(u);
}

int query(int u, int l, int r){
    if(l <= tr[u].l && tr[u].r <= r) return tr[u].sum;

    pushdown(u);
    int mid = tr[u].l + tr[u].r >> 1;
    int res = 0;
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
            modify(1, r + 1, r + 1, -k);
            modify(1, l + 1, r, d);    
        }
        if(op == 2){
            int p; cin >> p;
            cout << query(1, 1, p) << endl; 
        }
    }

    return 0;
}

