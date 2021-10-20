#include <bits/stdc++.h>

using namespace std;

const int N = 2e5 + 10;

int a[N], w[N];

struct node{
    int l, r;
    int add, min;
}tr[N * 4];

void pushup(int u){
    tr[u].min = min(tr[u << 1].min, tr[u << 1 | 1].min);
}

void pushdown(int u){
    auto &root = tr[u];
    auto &left = tr[u << 1], &right = tr[u << 1 | 1];
    if(root.add){
        left.add += root.add, right.add += root.add;
        left.min += root.add, right.min += root.add;
        root.add = 0;
    }
}

void build(int u, int l, int r){
    if(l == r){
        tr[u] = {l, r, 0, w[l]};
    }
    else{
        tr[u] = {l, r, 0};
        int mid = l + r >> 1;
        build(u << 1, l, mid), build(u << 1 | 1, mid + 1, r);
        pushup(u);
    }
}

void modify(int u, int l, int r, int k){
    if(l <= tr[u].l && tr[u].r <= r){
        tr[u].add += k, tr[u].min += k;
    }
    else{
        pushdown(u);
        int mid = tr[u].l + tr[u].r >> 1;
        if(l <= mid) modify(u << 1, l, r, k);
        if(r > mid) modify(u << 1 | 1, l, r, k);
        pushup(u);
    }
}

int query(int u, int l, int r){
    if(l > tr[u].r || r < tr[u].l) return 0;
    if(l <= tr[u].l && tr[u].r <= r) return tr[u].min;

    pushdown(u);
    int mid = tr[u].l + tr[u].r >> 1;
    int res = 1e9;
    if(l <= mid) res = min(res, query(u << 1, l, r));
    if(r > mid) res = min(res, query(u << 1 | 1, l, r));
    return res;
}

int main()
{
    int n, m; cin >> n >> m;
    for(int i = 1; i <= n; i ++){
        char c; cin >> c;
        if(c == '(') a[i] = 1, w[i] = w[i - 1] + 1;
        else a[i] = -1, w[i] = w[i - 1] - 1;
    }
    build(1, 1, n);
    while(m --){
        int op, l, r; cin >> op >> l >> r;
        if(op == 1){
            if(a[l] > a[r]) modify(1, l, r - 1, -2);
            if(a[l] < a[r]) modify(1, l, r - 1, 2);
            swap(a[l], a[r]);
        }
        else{
            int a = query(1, l - 1, l - 1);
            int b = query(1, r, r);
            int c = query(1, l, r);
            if(a == b && a <= c) cout << "Yes" << endl;
            else cout << "No" << endl;
        }
    }
    return 0;
}