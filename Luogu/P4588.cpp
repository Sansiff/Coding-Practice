
// Segment Tree

#include <bits/stdc++.h>
#define int long long 

using namespace std;

const int N = 1e5 + 10;

int q, p;

struct node{
    int l, r;
    int mul;
}tr[N * 4];

void pushup(int u){
    tr[u].mul = tr[u << 1].mul * tr[u << 1 | 1].mul % p;
}

void build(int u, int l, int r){
    if(l == r){
        tr[u] = {l, r, 1};
        return;
    }
    tr[u] = {l, r};
    int mid = l + r >> 1;
    build(u << 1, l, mid), build(u << 1 | 1, mid + 1, r);
    pushup(u);
}

void modify(int u, int x, int k){
    if(tr[u].l == x && tr[u].r == x){
        tr[u].mul = k;
        return;
    }
    int mid = tr[u].l + tr[u].r >> 1;
    if(x <= mid) modify(u << 1, x, k);
    if(x > mid) modify(u << 1 | 1, x, k);
    pushup(u);
}

int32_t main()
{
    int t; cin >> t;
    while(t --){
        cin >> q >> p;
        build(1, 1, q + 10);
        int cnt = 1;
        while(q --){
            int op, x; cin >> op >> x;
            if(op == 1){
                modify(1, cnt, x);
                cout << tr[1].mul << endl;
            }
            if(op == 2){
                modify(1, x, 1);
                cout << tr[1].mul << endl;
            }
            cnt ++;
        }
    }

    return 0;
}