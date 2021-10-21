#include <bits/stdc++.h>

using namespace std;

const int N = 1e5 + 10;

int n, m;

struct node{
    int l, r;
    int add;
}tr[N * 4];

void pushdown(int u){
    auto &root = tr[u];
    auto &left = tr[u << 1], &right = tr[u << 1 | 1];
    if(root.add){
        left.add += root.add;
        right.add += root.add;
        root.add = 0;
    }
}
void build(int u, int l, int r){
    tr[u] = {l, r, 0};
    if(l == r) return;
    int mid = l + r >> 1;
    build(u << 1, l, mid), build(u << 1 | 1, mid + 1, r);
}

void modify(int u, int l, int r){
    if(l <= tr[u].l && tr[u].r <= r){
        tr[u].add ++;
        return;
    }
    else{
        pushdown(u);
        int mid = tr[u].l + tr[u].r >> 1;
        if(l <= mid) modify(u << 1, l, r);
        if(r > mid) modify(u << 1 | 1, l, r);
    }
}

int query(int u, int x){
    if(tr[u].l == x && tr[u].r == x){
        if(tr[u].add & 1) return 1;
        else return 0;
    }
    pushdown(u);
    int mid = tr[u].l + tr[u].r >> 1;
    if(x <= mid) return query(u << 1, x);
    if(x > mid) return query(u << 1 | 1, x); 
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> n >> m;
    build(1, 1, n);
    while(m --){
        int t; cin >> t;
        if(t == 1){
            int l, r; cin >> l >> r;
            modify(1, l, r);
        }
        else{
            int x; cin >> x;
            cout << query(1,  x) << endl;
        }
    }
    return 0;
}