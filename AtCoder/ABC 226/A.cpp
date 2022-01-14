#include <bits/stdc++.h>
#define int long long 
using namespace std;
const int N = 5e5 + 10;

int h[N], e[N], ne[N], idx;
int w[N];
bool st[N];

void add(int a, int b){
    e[idx] = b, ne[idx] = h[a], h[a] = idx ++;
}

int32_t main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n; cin >> n;
    memset(h, -1, sizeof h);
    for(int i = 1; i <= n; i ++){
        cin >> w[i];
        int k; cin >> k;
        for(int j = 0; j < k; j ++){
            int x; cin >> x;
            if(x) add(i, x);
        } 
    }

    queue<int> q;
    q.push(n);
    while(q.size()){
        int t = q.front(); q.pop();
        if(st[t]) continue;
        st[t] = true;
        for(int i = h[t]; ~i; i = ne[i]){
            int j = e[i];
            q.push(j);
        }
    }
    int ans = 0;
    for(int i = 1; i <= n; i ++){
        if(st[i]) ans += w[i];
    }

    cout << ans;


    return 0;
}