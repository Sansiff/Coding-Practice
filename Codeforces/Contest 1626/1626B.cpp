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

const int N = 2e5 + 100;
int a[N];
void solve() {
    string s; cin >> s; 
    int n = s.length();
    rep(i, 0, n + 10) a[i] = 0;
    rep(i, 0, n) a[i + 1] = s[i] - '0';
    bool flag = false;
    for(int i = 1; i < n; i ++ ) {
        if(a[i] + a[i + 1] > a[i] * 10 + a[i + 1]) flag = true; 
    } 
    if(!flag) {
        bool flag = false; int idx;
        for(int j = n; j > 1; j -- ) {
            if(a[j] + a[j - 1] >= 10) {
                idx = j - 1;
                flag = true;
                break;
            }
        }
        if(flag) {
            rep(i, 1, n + 1) {
                if(i == idx) {
                    cout << a[i] + a[i + 1]; 
                    i ++;
                } 
                else cout << a[i];
            }
        } 
        else {
            cout << a[1] + a[2];
            for(int i = 3; i <= n; i ++ ) cout << a[i];
        }
        
    } 
    else {
        bool flag = true;
        rep(i, 1, n) {
            if(a[i] + a[i + 1] >= a[i] * 10 + a[i + 1]) {
                cout << a[i] + a[i + 1];
                i ++;
                flag = false;
            } 
            else cout << a[i];
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