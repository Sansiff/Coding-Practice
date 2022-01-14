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
int qpow(int a, int b, int p){
    int res = 1;
    while(b){
        if(b & 1) res *= a, b --;
        else a *= a, b /= 2;
    }
    return res;
}

void solve(){
    string s; cin >> s;
    bool flag = true;
    for(int i = 1; i < s.length(); i ++ )
        if(!isupper(s[i])) flag = false;
    if(!flag) cout << s;
    else {
        for(int i = 0; s[i]; i ++ )
            if(isupper(s[i])) cout << char(s[i] - 'A' + 'a');
            else cout << char(s[i] - 'a' + 'A');
    }
}
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
    return 0;
}