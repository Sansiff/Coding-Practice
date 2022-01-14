#include <bits/stdc++.h>
#define int long long 
using namespace std;

const int N = 2e5 + 10;

inline void solve() {
    int n; cin >> n;
    vector<int> a(n);
    string op;
    for(int &x: a) cin >> x;
    cin >> op;
    vector<int> l, r;
    for(int i = 0; i < n; i ++ ) {
        if(op[i] == 'B') l.push_back(a[i]);
        else r.push_back(a[i]); 
    }
    sort(l.begin(), l.end());
    sort(r.begin(), r.end());
    int L = 0, R = 0;
    int len1 = l.size(), len2 = r.size();
    for(int i = 1; i <= n; i ++ ) {
        if(L < len1 && l[L] >= i) L ++;
        else if(R < len2 && r[R] <= i) R ++;
        else {
            cout << "NO";
            return;
        }
    }
    cout << "YES";
}
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    int t; cin >> t;
    while(t --){
        solve();
        cout << "\n";
    }

    return 0;
}