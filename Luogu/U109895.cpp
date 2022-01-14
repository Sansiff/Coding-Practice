#include <bits/stdc++.h>
#define int long long 
const int N = 5e5 + 10;

using namespace std;

int son[N * 35][15], idx;

void insert(int x){
    int p = 0;
    for(int i = 31; ~i; i --){
        int u = x >> i & 1;
        if(!son[p][u]) son[p][u] = ++ idx;
        p = son[p][u];
    }
}

int query(int x){
    int p = 0, res = 0;
    for(int i = 31; ~i; i --){
        int u = x >> i & 1;
        if(son[p][!u]) res += 1 << i, p = son[p][!u];
        else p = son[p][u];
    }
    return res;
}

signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int n, m; cin >> n >> m;
    for(int i = 1; i <= n; i ++){
        int x; cin >> x;
        insert(x);
    }
    while(m --){
        int x; cin >> x;
        cout << query(x) << endl;
    }

    return 0;
}