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

const int N = 1e5 + 10;
int a[N][10], d[N];
void solve(){
    int n, k; cin >> n >> k;
    set<int> st;
    for(int i = 0; i < n; i ++){
        for(int j = 0; j < k; j ++){
            cin >> a[i][j];
        }
        for(int j = 0; j < k; j ++){
            d[i] += (a[i][j] << j);
        }
        st.insert(d[i]);
    }
    for(int a : st){
        for(int b : st){
            if((a & b) == 0){
                cout << "Yes"; return;
            }
        }
    }
    cout << "No";
}

signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
    return 0;
}