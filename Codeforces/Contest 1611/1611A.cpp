#include <bits/stdc++.h>
#define int long long
#define lowbit(x) (x&-x)
#define PII pair<int,int>
#define fi first
#define se second
using namespace std;
typedef long long LL;

const int N = 1e5 + 10;

void solve(){
    int n; cin >> n;
    if(n & 1){
        string s = to_string(n);
        bool flag = true;
        int cnt = 0;
        for(int i = 0; flag && i < s.length(); i ++){
            if((s[i] - '0') % 2 == 0){
                flag = false;
                cnt = i;
            }
        }
        if(flag) cout << -1;
        else{
            if(cnt) cout << 2;
            else cout << 1;
        }
    }
    else cout << 0;
}

signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int _; cin >> _;
    while(_ --){
        solve();
        cout << '\n';
    }
    return 0;
}