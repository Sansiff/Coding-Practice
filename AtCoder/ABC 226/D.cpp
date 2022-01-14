#include <bits/stdc++.h>
#define int long long 
#define PII pair<int, int>
#define fi first
#define se second
using namespace std;
const int N = 5e5 + 10;

set<PII> s;
vector<PII> a;

int gcd(int a, int b){
    return b ? gcd(b, a % b) : a;
}

int32_t main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n; cin >> n;
    for(int i = 0; i < n; i ++ ) {
        int u, v; cin >> u >> v;
        a.push_back({u, v});
    } 
    for(int i = 0; i < n; i ++ ) {
        for(int j = 0; j < n; j ++ ) {
            if(i == j) continue;
            int l = a[i].fi - a[j].fi, r = a[i].se - a[j].se;
            if(l && r) {
                int res = gcd(abs(l), abs(r));
                l /= res, r /= res;
            } else if(!l) {
                if(r > 0) r = 1;
                else r = -1;
            } else if(!r) {
                if(l > 0) l = 1;
                else l = -1;
            }
            s.insert({l, r});
        }
    }
    cout << s.size();

    return 0;
}