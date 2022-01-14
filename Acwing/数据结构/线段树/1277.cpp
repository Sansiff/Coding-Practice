#include <bits/stdc++.h>
#define int long long

using namespace std;

const int N = 1e5 + 10;

int n, m, p, w[N];
struct node{
    int l, r;
    int mul, add, sum;
}tr[N * 4];

void pushup(int u){
    tr[u].sum = (tr[u << 1].sum + tr[u << 1 | 1].sum) % p;
}

void pushdown(int u){
    auto &root = tr[u];
    auto &left = tr[u << 1], &right = tr[u << 1 | 1];
    if(root.mul != 1){
        left.mul = left.mul * root.mul % p;
        left.add = left.add * root.mul % p;
        left.sum = left.sum * root.mul % p;
        right.mul = right.mul * root.mul % p;
        right.add = right.add * root.mul % p;
        right.sum = right.sum * root.mul % p;
        root.mul = 1;
    }
    if(root.add){
        left.add = (left.add + root.add) % p;
        left.sum = (left.sum + (left.r - left.l + 1) * root.add) % p;
        right.add = (right.add + root.add) % p;
        right.sum = (right.sum + (right.r - right.l + 1) * root.add) % p;
        root.add = 0;
    }
}

void build(int u, int l, int r){
    if(l == r){
        tr[u] = {l, r, 1, 0, w[l]};
        return;
    }    
    else{
        tr[u] = {l, r, 1, 0};
        int mid = l + r >> 1;
        build(u << 1, l, mid), build(u << 1 | 1, mid + 1, r);
        pushup(u);
    }
}

void modify1(int u, int l, int r, int k){
    if(l <= tr[u].l && tr[u].r <= r){
        tr[u].mul = tr[u].mul * k % p;
        tr[u].add = tr[u].add * k % p;
        tr[u].sum = tr[u].sum * k % p;
        return;
    }
    else{
        pushdown(u);
        int mid = tr[u].l + tr[u].r >> 1;
        if(l <= mid) modify1(u << 1, l, r, k);
        if(r > mid) modify1(u << 1 | 1, l, r, k);
        pushup(u);
    }
}

void modify2(int u, int l, int r, int k){
    if(l <= tr[u].l && tr[u].r <= r){
        tr[u].add = (tr[u].add + k) % p;
        tr[u].sum = (tr[u].sum + (tr[u].r - tr[u].l + 1) * k);
        return;
    }  
    else{
        pushdown(u);
        int mid = tr[u].l + tr[u].r >> 1;
        if(l <= mid) modify2(u << 1, l, r, k);
        if(r > mid) modify2(u << 1 | 1, l, r, k);
        pushup(u);
    }
}

int query(int u, int l, int r){
    if(l <= tr[u].l && tr[u].r <= r) return tr[u].sum;
    
    pushdown(u);
    int mid = tr[u].l + tr[u].r >> 1;
    int res = 0;
    if(l <= mid) res += query(u << 1, l, r);
    if(r > mid) res += query(u << 1 | 1, l, r);
    return res % p;
}

int32_t main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    cin >> n >> p;
    for(int i = 1; i <= n; i ++) cin >> w[i];
    build(1, 1 ,n);
    cin >> m;
    while(m --){
        int op, l, r;
        cin >> op >> l >> r;
        if(op == 1){
            int k; cin >> k;
            modify1(1, l, r, k);
        }
        if(op == 2){
            int k; cin >> k;
            modify2(1, l, r, k);
        }
        if(op == 3){
            cout << query(1, l, r) << endl;
        }
    }
    
    
    return 0;
}

