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
void solve() {   
    int x1, p1, x2, p2; cin >> x1 >> p1 >> x2 >> p2;
    int len1 = to_string(x1).size() + p1;
    int len2 = to_string(x2).size() + p2;
    if(len1 > len2) cout << '>';
    else if(len1 < len2) cout << '<';
    else {
        string s1 = to_string(x1);
        string s2 = to_string(x2);
        for(int i = 0; i < len1; i ++ ) {
            char c1, c2;
            if(i < s1.size() ) c1 = s1[i]; 
            else c1 = '0';
            if(i < s2.size()) c2 = s2[i];
            else c2 = '0';
            if(i > s1.size() && i > s2.size()) break;
            if(c1 > c2) {
                cout << '>';
                return;
            } else if(c1 < c2) {
                cout << '<'; 
                return;
            } 
            
        } 
        cout << '=';
    }
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