#include <bits/stdc++.h>

using namespace std;
const int N = 2e5 + 10, M = 2e5 + 10;

struct Edge{
    int a, b, w;
    bool operator< (const Edge &t) const{
        return w < t.w;
    }
}e[M];

int n, m, q, p[N];

int find(int x){
    if (p[x] != x) p[x] = find(p[x]);
    return p[x];
}


int main(){
    set<Edge> st;
    cin >> n >> m >> q;
    for (int i = 1; i <= n; i ++ ) p[i] = i;
    for (int i = 0; i < m; i ++ ){
        int a, b, w;
        cin >> a >> b >> w;
        e[i] = {a, b, w};
    }
    sort(e, e + m);

    int res = 0;
    for (int i = 0; i < m; i ++ ){
        int a = find(e[i].a), b = find(e[i].b), w = e[i].w;
        if (a != b){
            st.insert({a, b, w}), st.insert({b, a, w});
            p[a] = b;
            res = w;
        }
    }

    cout << "FCKU" << endl;
    for(auto x : st){
        cout << x.a << ' ' << x.b << ' ' << x.w << endl;
    }
    cout << "FUCK" << endl;

    while(q --){
        int a, b, w; cin >> a >> b >> w;
        if(st.count({a, b, w})) cout << "Yes";
        else cout << "No";
        cout << '\n';
    }
    return 0;
}