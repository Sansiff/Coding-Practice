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

void read(VI & arr){
    for(int &x : arr) cin >> x;
}
int gcd(int a, int b){
    return b ? gcd(b, a % b) : a;
}

const int N = 1e6 + 10; int mxx;
bool st[N];

bool check(int x){
    for(int i = 2; i * x <= mxx; i ++){
        if(!st[i * x]) continue;
        for(int j = i + 1; j * x <= mxx; j ++){
            if(!st[j * x]) continue;
            if(gcd(i * x, j * x) == x){ 
                st[x] = 1; return true;
            }
        }
    }
    return false;
}

void solve(){
    int n; cin >> n;
    vector<int> arr(n);
    for(int& x : arr) cin >> x, st[x] = 1;
    mxx = *max_element(all(arr));
    for(int i = mxx; i; i --){
        if(!st[i]) check(i); 
    }
    int cnt = 0; 
    rep(i, 1, mxx + 1){
        if(st[i]) cnt ++;
    }
    cout << cnt - n;
}

signed main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
    return 0;
}
