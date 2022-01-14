#include <bits/stdc++.h>
#define int long long 
using namespace std;

inline void solve() {
    int a, b;
    cin >> a >> b;
    int p = b / 4 * 4 + 1;
    b %= 4;
    while(b -- ) {
        if(a & 1) a += p; 
        else a -= p;
        p ++;
    }
    cout << a;

}

signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t; cin >> t;
    while(t --){
        solve();
        cout << '\n';
    }
    return 0;
}