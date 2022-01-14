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

signed main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    string s; cin >> s;
    int s1 = 0, s2 = 0;
    for(auto x : s){
        if(x == '4') s1 ++;
        if(x == '7') s2 ++;
    }
    if(s1 + s2 == 4 || s1 + s2 == 7){
        cout << "YES";
    }
    else cout << "NO";
    return 0;
}