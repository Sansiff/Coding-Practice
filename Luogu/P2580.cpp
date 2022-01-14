#include <bits/stdc++.h>

using namespace std;

const int N = 1e5 + 10, M = N * 50;
int son[M][50], idx;
bool exis[M], vis[M];

void insert(string s){
    int p = 0;
    for(int i = 0; i < s.length(); i ++){
        int u = s[i] - 'a';
        if(!son[p][u]) son[p][u] = ++ idx;
        p = son[p][u];
    }
    exis[p] = 1;
}

string query(string s){
    int p = 0;
    for(int i = 0; i < s.length(); i ++){
        int u = s[i] - 'a';
        if(!son[p][u]) return "WRONG";
        p = son[p][u];
    }
    if(!exis[p]) return "WRONG";
    else if(!vis[p]) {
        vis[p] = 1;
        return "OK";
    }
    else return "REPEAT";
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int n; cin >> n;
    for(int i = 1; i <= n; i ++){
        string s; cin >> s;
        insert(s);
    }
    int m; cin >> m;
    while(m --){
        string s; cin >> s;
        cout << query(s) << endl;
    }

    return 0;
}