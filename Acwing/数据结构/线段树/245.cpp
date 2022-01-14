
//245 你能回答这些问题吗
// Segment Tree

#include <bits/stdc++.h>
#define int long long 

using namespace std;

const int N = 5e5 + 10;

int n, m, w[N];

struct node{
    int l, r;
    int tmax, lmax, rmax, sum;
}tr[N * 4];

void pushup(node &u, node &l, node &r){
    u.sum = l.sum + r.sum;
    u.lmax = max(l.lmax, l.sum + r.lmax);
    u.rmax = max(r.rmax, r.sum + l.rmax);
    u.tmax = max(max(l.tmax, r.tmax), l.rmax + r.lmax);
}

void pushup(int u){
    pushup(tr[u], tr[u << 1], tr[u << 1 | 1]);
}

void build(int u, int l, int r){
    if(l == r){
        tr[u] = {l, l, w[l], w[l], w[l], w[l]};
        return;
    }
    tr[u] = {l, r};
    int mid = l + r >> 1;
    build(u << 1, l, mid), build(u << 1 | 1, mid + 1, r);
    pushup(u);
}

void modify(int u, int x, int k){
    if(tr[u].l == x && tr[u].r == x){
        tr[u] = {x, x, k, k, k, k};
        return;
    }
    int mid = tr[u].l + tr[u].r >> 1;
    if(x <= mid) modify(u << 1, x, k);
    if(x > mid) modify(u << 1 | 1, x, k);
    pushup(u);
}

node query(int u, int l, int r){
    if(l <= tr[u].l && tr[u].r <= r) return tr[u];
    
    int mid = tr[u].l + tr[u].r >> 1;
    if(l > mid) return query(u << 1 | 1, l, r);
    if(r <= mid) return query(u << 1, l, r);
    else{
        node left = query(u << 1, l, r);
        node right = query(u << 1 | 1, l, r);
        node res;
        pushup(res, left, right);
        return res;
    }
}

int32_t main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n >> m;
    for(int i = 1; i <= n; i ++){
        cin >> w[i];
    }
    build(1, 1, n);

    while(m --){
        int k, x, y; cin >> k >> x >> y;
        if(k == 1){
            if(x > y) swap(x, y);
            cout << query(1, x, y).tmax << endl;
        }
        else modify(1, x, y);
        
    }
    return 0;
}