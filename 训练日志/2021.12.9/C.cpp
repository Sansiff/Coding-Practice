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
    int n; cin >> n;
    queue<int> q1, q2;
    int cnt = 0;
    for(int i = 1; i <= 2 * n; i ++){
        int x; cin >> x; cnt ++;
        if(x & 1) q1.push(cnt);
        else q2.push(cnt);
    }
    cnt = 1;
    while(cnt < n && q1.size() >= 2){
        cnt ++;
        cout << q1.front() << ' ';
        q1.pop();
        cout << q1.front() << endl;
        q1.pop();
    }
    while(cnt < n && q2.size() >= 2){
        cnt ++;
        cout << q2.front() << ' ';
        q2.pop();
        cout << q2.front() << endl;
        q2.pop();
    }
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