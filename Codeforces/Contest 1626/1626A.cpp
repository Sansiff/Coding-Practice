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

void solve() {
    string s; cin >> s;
    vector<int> cnt(26, 0);
    for(char c: s) cnt[c - 'a'] ++;
    string res;
    for(int i = 0; i < 26; i ++ )  {
        if(cnt[i] == 2) res += ('a' + i);
    }
    cout << res << res;
    for(int i = 0; i < 26; i ++ ) {
        if(cnt[i] == 1) {
            cout << char('a' + i);
        }
    }
}

signed main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int _; cin >> _;
    while(_--){
        solve();
        cout << '\n';
    }
    return 0;
}