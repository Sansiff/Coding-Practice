#include <bits/stdc++.h>
#define int long long 
using namespace std;

int num[26];

inline void solve() {
    string S; cin >> S;
    map<char, int> mp;
    for(int i = 0; i < S.size(); i ++ ) {
        mp[S[i]] = i;
    }
    string s; cin >> s;
    int len = s.size();
    int x = mp[s[0]];
    int ans = 0;
    for(int i = 1; i < len; i ++ ) {
        int p = mp[s[i]];
        ans += abs(p - x);
        x = p;
    }
    cout << ans;
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