#include <bits/stdc++.h>
#define int long long

using namespace std;

int n, m;
const int N = 2e5 + 10, M = 2 * N;

int h[N], e[M], ne[M], wp[M], w[N], idx;
int nw[N], id[N], cnt;
int fa[N], dep[N], son[N], sz[N], top[N];

struct age{
    int a, b, c;
}age[M];


//wp 边权
//w 点权
//nw dfs序后的点权

void add(int a, int b, int c){
    e[idx] = b, ne[idx] = h[a], wp[idx] = c, h[a] = idx ++;
}

void dfs1(int u, int father, int depth){
    dep[u] = depth, fa[u] = father, sz[u] = 1;
    for(int i = h[u]; ~i; i = ne[i]){
        int j = e[i];
        if(j == father) continue;
        //边权变点权
        w[j] = wp[i];
        dfs1(j, u, depth + 1);
        sz[u] += sz[j];
        if(sz[son[u]] < sz[j]) son[u] = j;
    }
}

void dfs2(int u, int t){
    //点权变dfs序后点权
    id[u] = ++ cnt, nw[cnt] = w[u], top[u] = t;
    if(son[u] == n + 1) return;
    dfs2(son[u], t);
    for(int i = h[u]; ~i; i = ne[i]){
        int j = e[i];
        if(j == fa[u] || j == son[u]) continue;
        dfs2(j, j);
    }
}

struct node{
    int l, r, mul, max, min, sum;
}tr[N * 4];

void pushup(int u){
    tr[u].sum = tr[u << 1].sum + tr[u << 1 | 1].sum;
    tr[u].max = max(tr[u << 1].max, tr[u << 1 | 1].max);
    tr[u].min = min(tr[u << 1].min, tr[u << 1 | 1].min);
}

void pushdown(int u){
    auto &root = tr[u];
    auto &left = tr[u << 1], &right = tr[u << 1 | 1];
    if(root.mul == -1){
        left.sum *= -1, left.mul *= -1;
        left.max = -left.max, left.min = -left.min;
        swap(left.max, left.min);
        right.sum *= -1, right.mul *= -1;
        right.max = -right.max, right.min = -right.min;
        swap(right.max, right.min);
        root.mul = 1;
    }
}

void build(int u, int l, int r){
    tr[u] = {l, r, 1, nw[r], nw[r], nw[r]};
    if(l == r) return;
    int mid = l + r >> 1;
    build(u << 1, l, mid), build(u << 1 | 1, mid + 1, r);
    pushup(u);
}

void modify(int u, int l, int r){
    if(l <= tr[u].l && tr[u].r <= r){
        tr[u].max = -tr[u].max, tr[u].min = -tr[u].min;
        swap(tr[u].max, tr[u].min);
        tr[u].mul *= -1, tr[u].sum *= -1; 
        return;
    }
    else{
        pushdown(u);
        int mid = tr[u].l + tr[u].r >> 1;
        if(l <= mid) modify(u << 1, l, r);
        if(r > mid) modify(u << 1 | 1, l, r);
        pushup(u);
    }
}

void modify_path(int u, int v){
    while(top[u] != top[v]){
        if(dep[top[u]] < dep[top[v]]) swap(u, v);
        modify(1, id[top[u]], id[u]);
        u = fa[top[u]];
    }
    if(dep[u] < dep[v]) swap(u, v);
    modify(1, id[v] + 1, id[u]);
}

void change(int u, int x, int w){
    if(tr[u].l == x && tr[u].r == x){
        tr[u].sum = w, tr[u].max = w , tr[u].min = w;
        return;
    }
    else{
        pushdown(u);
        int mid = tr[u].l + tr[u].r >> 1;
        if(x <= mid) change(u << 1, x, w);
        if(x > mid) change(u << 1 | 1, x, w);
        pushup(u);
    }
}

int querySum(int u, int l, int r){
    if(l <= tr[u].l && tr[u].r <= r) return tr[u].sum;
    pushdown(u);
    int mid = tr[u].l + tr[u].r >> 1;
    int res = 0;
    if(l <= mid) res += querySum(u << 1, l, r);
    if(r > mid) res += querySum(u << 1 | 1, l, r);
    return res;
}

int querySum(int u, int v){
    int res = 0;
    while(top[u] != top[v]){
        if(dep[top[u]] < dep[top[v]]) swap(u, v);
        res += querySum(1, id[top[u]], id[u]);
        u = fa[top[u]];
    }
    if(dep[u] < dep[v]) swap(u, v);
    if(u != v) res += querySum(1, id[v] + 1, id[u]);
    return res;
}

int queryMax(int u, int l, int r){
    if(l <= tr[u].l && tr[u].r <= r) return tr[u].max;
    pushdown(u);
    int mid = tr[u].l + tr[u].r >> 1;
    int res = -0x3f3f3f3f;
    if(l <= mid) res = max(res, queryMax(u << 1, l, r));
    if(r > mid) res = max(res, queryMax(u << 1 | 1, l, r));
    return res;
}

int queryMax(int u, int v){
    int res = -0x3f3f3f3f;
    while(top[u] != top[v]){
        if(dep[top[u]] < dep[top[v]]) swap(u, v);
        res = max(res, queryMax(1, id[top[u]], id[u]));
        u = fa[top[u]];
    }
    if(dep[u] < dep[v]) swap(u, v);
    if(u != v) res = max(res, queryMax(1, id[v] + 1, id[u]));
    return res;
}

int queryMin(int u, int l, int r){
    if(l <= tr[u].l && tr[u].r <= r) return tr[u].min;
    pushdown(u);
    int mid = tr[u].l + tr[u].r >> 1;
    int res = 0x3f3f3f3f;
    if(l <= mid) res = min(res, queryMin(u << 1, l, r));
    if(r > mid) res = min(res, queryMin(u << 1 | 1, l, r));
    return res;
}

int queryMin(int u, int v){
    int res = 0x3f3f3f3f;
    while(top[u] != top[v]){
        if(dep[top[u]] < dep[top[v]]) swap(u, v);
        res = min(res, queryMin(1, id[top[u]], id[u]));
        u = fa[top[u]];
    }
    if(dep[u] < dep[v]) swap(u, v);
    if(u != v) res = min(res, queryMin(1, id[v] + 1, id[u]));
    return res;
}

int32_t main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    cin >> n;
    for(int i = 0; i < n; i ++){
        h[i] = -1, son[i] = n + 1;
    }
    for(int i = 1; i < n; i ++){
        int a, b, c; cin >> a >> b >> c;
        age[i] = {a, b, c};
        add(a, b, c), add(b, a, c);
    }
    dfs1(0, -1, 1), dfs2(0, 0);

    build(1, 1, n);

    cin >> m;
    while(m --){
        string op; int a, b;
        cin >> op >> a >> b;
        if(op == "C"){
            int u = age[a].a, v = age[a].b;
            if(dep[u] < dep[v]) swap(u, v);
            change(1, id[u], b);
        }
        else if(op == "N"){
            modify_path(a, b);
        }
        else if(op == "SUM"){
            cout << querySum(a, b) << endl;
        }
        else if(op == "MAX"){
            cout << queryMax(a, b) << endl;
        }
        else cout << queryMin(a, b) << endl;
    }

    return 0;
}