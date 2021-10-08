
// 1275 最大数
// Segment Tree

#include <bits/stdc++.h>

using namespace std;

const int N = 2e5 + 10;

int m, p;

struct node{
	int l, r;
	int v;
}tr[N * 4];

void build(int u, int l, int r){
	tr[u] = {l, r};
	if(l == r) return;
	int mid = l + r >> 1;
	build(u << 1, l, mid), build(u << 1 | 1, mid + 1, r);
}

void pushup(int u){
	tr[u].v = max(tr[u << 1].v, tr[u << 1 | 1].v);
}

int query(int u, int l, int r){
	if(l <= tr[u].l && r >= tr[u].r) return tr[u].v;

	int v = 0;
	int mid = tr[u].r + tr[u].l >> 1;
	if(l <= mid) v = query(u << 1, l, r);
	if(r > mid) v = max(v, query(u << 1 | 1, l, r));

	return v;
}

void modify(int u, int x, int v){
	if(tr[u].l == x && tr[u].r == x) tr[u].v = v;
	else{
		int mid = tr[u].l + tr[u].r >> 1;
		if(x <= mid) modify(u << 1, x, v);
		else modify(u << 1 | 1, x, v);
		pushup(u);
	}
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    cin >> m >> p;
    build(1, 1, m);
    
    int last = 0, n = 0;
    while(m --){
        char c; int x;
        cin >> c >> x;
        if(c == 'Q'){
            last = query(1, n - x + 1, n);
            cout << last << endl;
        }
        else{
            modify(1, n + 1, ((long long)last + x) % p);
            n ++;
        }
    }
    

    return 0;
}