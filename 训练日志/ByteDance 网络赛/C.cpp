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

struct node{
    int a, b, p;
    bool operator <(const node &A)const {
        return A.a < a;
    }
};

bool cmp(node a, node b){
    return a.a > b.a;
}

void solve(){
    int n; cin >> n;
    vector<node> arr(n);
    vector<bool> res(n);
    priority_queue<node> q1;
    rep(i, 0, n) cin >> arr[i].a;
    rep(i, 0, n) cin >> arr[i].b, arr[i].p = i;
    sort(all(arr), cmp);
    int ta = arr[0].a, tb = arr[0].b;
    res[arr[0].p] = 1;
    rep(i, 0, 5e3){
        for(int i = 0; i < arr.size(); i ++){
            if(!res[arr[i].p] && (arr[i].a > ta || arr[i].b > tb)){
                ta = min(ta, arr[i].a), tb = min(tb, arr[i].b);
                res[arr[i].p] = 1;
            }
        }
    }
    for(int x : res) cout << (x ? "YES" : "NO") << '\n';
}
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int _; cin >> _;
    while(_ --){
        solve();
    }
    return 0;
}