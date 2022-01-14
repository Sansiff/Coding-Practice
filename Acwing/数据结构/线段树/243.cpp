
// 243 一个简单的整数问题2
// Segment Tree

#include <bits/stdc++.h>
#define int long long 
using namespace std;

const int N = 5e5 + 10;

int n, m, w[N];

struct node{
    int l, r;
    int sum, add;
}tr[N * 4];

void pushup(int u){
    tr[u].sum = tr[u << 1].sum + tr[u << 1 | 1].sum;
}

void pushdown(int u){
    auto &root = tr[u];
    auto &left = tr[u << 1], &right = tr[u << 1 | 1];
    if(root.add){
        left.add += root.add, right.add += root.add;
        left.sum += (left.r - left.l + 1) * root.add;
        right.sum += (right.r - right.l + 1) * root.add;
        root.add = 0;
    }
}

void build(int u, int l, int r){
    if(l == r){
        tr[u] = {l, r, w[l], 0};
        return;
    }
    tr[u] = {l, r};
    int mid = l + r >> 1;
    build(u << 1, l, mid), build(u << 1 | 1, mid + 1, r);
    pushup(u);
}

int query(int u, int l, int r){
    if(tr[u].l >= l && tr[u].r <= r) return tr[u].sum;

    pushdown(u);
    int mid = tr[u].l + tr[u].r >> 1;
    int sum = 0;
    if(l <= mid) sum += query(u << 1, l, r);
    if(r > mid) sum += query(u << 1 | 1, l, r);
    return sum;
}

void modify(int u, int l, int r, int k){
    if(tr[u].l >= l && tr[u].r <= r){
        tr[u].add += k;
        tr[u].sum += (tr[u].r - tr[u].l + 1) * k;
    }
    pushdown(u);
    int mid = tr[u].l + tr[u].r >> 1;
    if(l <= mid) modify(u << 1, l, r, k);
    if(r > mid) modify(u << 1 | 1, l, r, k);
    pushup(u);
}


int32_t main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n >> m;
    for(int i = 1; i <= n; i ++) cin >> w[i];
    build(1, 1, n);

    while(m --){
        char op; cin >> op;
        if(op == 'C'){
            int l, r, d; cin >> l >> r >> d;
            modify(1, l, r, d);
        }
        else{
            int l, r; cin >> l >> r;
            cout << query(1, l, r) << endl;
        }
    }

    return 0;
}