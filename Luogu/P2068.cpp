#include <bits/stdc++.h>
#define int long long
const int N = 1e5 + 10;
using namespace std;

int n, m;
struct node{
    int l, r;
    int sum;
}tr[N * 4];

void pushup(int u){
    tr[u].sum = tr[u << 1].sum + tr[u << 1 | 1].sum;
}

void build(int u, int l, int r){
    tr[u] = {l, r, 0};
    if(l == r) return;
    else{
        int mid = l + r >> 1;
        build(u << 1, l, mid), build(u << 1 | 1, mid + 1, r);
        pushup(u);
    }
}

void modify(int u, int x, int k){
    if(tr[u].l == tr[u].r){
        tr[u].sum += k;
    }
    else{
        int mid = tr[u].l + tr[u].r >> 1;
        if(x <= mid) modify(u << 1, x, k);
        else modify(u << 1 | 1, x, k);
        pushup(u);
    }
}

int query(int u, int l, int r){
    if(l <= tr[u].l && tr[u].r <= r) return tr[u].sum;

    int mid = tr[u].l + tr[u].r >> 1;
    int res = 0;
    if(l <= mid) res += query(u << 1, l, r);
    if(r > mid) res += query(u << 1 | 1, l , r);
    return res;
}

int32_t main()
{
    cin >> n >> m;
    build(1, 1, n);
    while(m --){
        char c; int a, b;
        cin >> c >> a >> b;
        if(c == 'x') modify(1, a, b);
        else cout << query(1, a, b) << endl;
    }
    return 0;
}