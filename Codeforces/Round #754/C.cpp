#include <bits/stdc++.h>
#define lowbit(x) (x & -x)
#define int long long 
using namespace std;
const int N = 1e6 + 10;
int n;

inline void solve() {
    cin >> n;
    string s; cin >> s;
    s = ' ' + s;
    int cntA = 0, cntB = 0, cntC = 0;
    int ans = 1e9;
    for(int i = 1; i <= n; i ++ ) {
        if(s[i] != 'a') continue;
        int cntA = 0, cntB = 0, cntC = 0;
        cntA ++;
        if(i + 1 <= n && s[i + 1] == 'a') {
            cout << 2;
            return;
        }
        int j = i + 1;
        while(j <= n && s[j] != 'a') {
            if(s[j] == 'b') cntB ++;
            else cntC ++;
            j ++;
        }
        if(j > n) continue;
        cntA ++;
        if(cntA > max(cntB, cntC)) {
            ans = min(ans, j - i + 1);
            continue;
        }
        int k = j + 1;
        while(k <= n && s[k] != 'a') {
            if(s[k] == 'b') cntB ++;
            else cntC ++;
            k ++;
        }
        if(k > n) continue;
        cntA ++;
        if(cntA > max(cntB, cntC)) ans = min(ans, k - i + 1);
        i = j - 1;
    }
    if(ans == 1e9) ans = -1;
    cout << ans;
}

int32_t main()
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