#include <bits/stdc++.h>
#define int long long 
using namespace std;

const int N = 5e5 + 10;

int n, m, w[N];

struct node{
    int l, r;
    int sum, gcd;
}tr[N * 4];

int gcd(int a, int b){
    return b ? gcd(b, a % b) : a;
}

void pushup(node &u, node &l, node &r){
    u.sum = l.sum + r.sum;
    u.gcd = gcd(l.gcd, r.gcd);
}

void pushup(int u){
    pushup(tr[u], tr[u << 1], tr[u << 1 | 1]);
}

void build(int u, int l, int r){
    if(l == r){
        tr[u] = {l, r, w[r] - w[r - 1], w[r] - w[r - 1]};
    }
    else{
        tr[u] = {l, r};
        int mid = l + r >> 1;
        build(u << 1, l, mid), build(u << 1 | 1, mid + 1, r);
        pushup(u);
    }
}

void modify(int u, int x, int k){
    if(tr[u].l == tr[u].r){
        int b = tr[u].sum + k;
        tr[u] = {x, x, b, b};
    }
    else{
        int mid = tr[u].l + tr[u].r >> 1;
        if(x <= mid) modify(u << 1, x, k);
        if(x > mid) modify(u << 1 | 1, x, k);
        pushup(u);
    }
}

node query(int u, int l, int r){
    if(l <= tr[u].l && tr[u].r <= r) return tr[u];

    int mid = tr[u].l + tr[u].r >> 1;
    if(r <= mid) return query(u << 1, l, r);
    if(l > mid) return query(u << 1 | 1, l, r);
  
    node res;
    node left = query(u << 1, l, r);
    node right = query(u << 1 | 1, l, r);
    pushup(res, left, right);
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
        char op; int l, r; cin >> op >> l >> r;
        if(op == 'Q'){
            node left = query(1, 1, l);
            node right = query(1, l + 1, r);
            cout << abs(gcd(left.sum, right.gcd)) << endl;
        }
        else{
            int d; cin >> d;
            modify(1, l, d);
            if(r + 1 <= n) modify(1, r + 1, -d);
        }
    }

    return 0;
}