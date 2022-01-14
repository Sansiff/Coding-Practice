#include <bits/stdc++.h>
#define int long long 
using namespace std;
const int N = 1e5 + 10, M = 2 * N;
int n, m;
int w[N], e[M], ne[M], h[N], idx;
int id[N], nw[N], cnt;
int top[N], fa[N], sz[N], son[N], dep[N];

void add(int a, int b){
    e[idx] = b, ne[idx] = h[a], h[a] = idx ++;
}

void dfs1(int u, int father, int depth){
    dep[u] = depth, fa[u] = father, sz[u] = 1;
    for(int i = h[u]; ~i; i = ne[i]){
        int j = e[i];
        if(j == father) continue;
        dfs1(j, u, depth + 1);
        sz[u] += sz[j];
        if(sz[son[u]] < sz[j]) son[u] = j;
    }
}

void dfs2(int u, int t){
    id[u] = ++ cnt, nw[cnt] = w[u], top[u] = t;
    if(!son[u]) return;
    dfs2(son[u], t);
    for(int i = h[u]; ~i; i = ne[i]){
        int j = e[i];
        if(j == fa[u] || j == son[u]) continue;
        dfs2(j, j);
    } 
}

struct node{
    int l, r; 
    int add, sum;
}tr[N * 4];

void pushup(int u){
    tr[u].sum = tr[u << 1].sum + tr[u << 1 | 1].sum;
}

void pushdown(int u){
    auto &root = tr[u];
    auto &left = tr[u << 1], &right = tr[u << 1 | 1];
    if(root.add){
        left.add += root.add;
        left.sum += (left.r - left.l + 1) * root.add;
        right.add += root.add;
        right.sum += (right.r - right.l + 1) * root.add;
        root.add = 0;
    }
}

void build(int u, int l, int r){
    tr[u] = {l, r, 0, nw[r]};
    if(l == r) return;
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
    else{
        pushdown(u);
        int mid = tr[u].l + tr[u].r >> 1;
        if(l <= mid) modify(u << 1, l, r, k);
        if(r > mid) modify(u << 1 | 1, l, r, k);
        pushup(u);
    }
}

void modify_path(int u, int v, int k){
    while(top[u] != top[v]){
        if(dep[top[u] < dep[top[v]]]) swap(u, v);
        modify(1, id[top[u]], id[u], k);
        u = fa[top[u]];
    }
    if(dep[u] < dep[v]) swap(u, v);
    modify(1, id[v], id[u], k);
}

void modify_tree(int u, int k){
    modify(1, id[u], id[u] + sz[u] - 1, k);
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

int query_path(int u, int v){
    int res = 0;
    while(top[u] != top[v]){
        if(dep[top[u]] < dep[top[v]]) swap(u, v);
        res += query(1, id[top[u]], id[u]);
        u = fa[top[u]];
    }
    if(dep[u] < dep[v]) swap(u, v);
    res += query(1, id[v], id[u]);
    return res;
}

int query_tree(int u){
    return query(1, id[u], id[u] + sz[u] - 1);
}

signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    cin >> n;
    for(int i = 1; i <= n; i ++) cin >> w[i];
    memset(h, -1, sizeof h);
    for(int i = 1; i < n; i ++){
        int a, b; cin >> a >> b;
        add(a, b), add(b, a);
    }
    dfs1(1, -1, 1), dfs2(1, 1);
    build(1, 1, n);
    cin >> m;
    while(m --){
        int op, u, v, k;
        cin >> op >> u;
        if(op == 1){
            cin >> v >> k;
            modify_path(u, v, k);
        }
        else if(op == 2){
            cin >> k;
            modify_tree(u, k);
        }
        else if(op == 3){
            cin >> v;
            cout << query_path(u, v) << endl;
        }
        else cout << query_tree(u) << endl;
    }

    return 0;
}