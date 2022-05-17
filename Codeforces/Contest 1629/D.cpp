#include <bits/stdc++.h>
#define int long long
#define lowbit(x) (x&-x)
#define rep(i, l, r) for(int i = l; i < r; i ++)
#define all(x) (x).begin(),(x).end()
#define fi first
#define se second
using namespace std;
typedef long long LL;
typedef pair<int,int> PII;
typedef vector<int> VI;
typedef vector<vector<int>> VII;
typedef vector<PII> VPII;
void read(VI& a){
    for(int& x : a) cin >> x;
}

inline void solve() {
    int n; cin >> n;
    vector<string> s(n);
    map<string, int> mp, mp1, mp2; 
    bool flag = false;
    for(string &X: s) {
        cin >> X; string res = X;
        reverse(all(res));
        if(res == X || mp[X]) { flag = true; }
        if(flag) continue;
        mp[res] ++;
        if((int)X.size() == 2) {
            if(mp2[res]) {flag = true; }
            mp1[X] ++; 
        } else if((int)X.size() == 3) {
            string R = X.substr(1, 2);
            reverse(all(R));
            if(mp1[R]) {flag = true;}
            mp2[X.substr(0, 2)] ++;
        }
    }
    if(flag) cout << "YES";
    else cout << "NO";
}

signed main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int _; cin >> _;
    while(_--){
        solve();
        cout << endl;
    }
    return 0;
}