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
    int n, a, b; cin >> n >> a >> b;
    vector<int> arr(n + 1);
    arr[1] = a; arr[n] = b;
    int cnt = n; bool flag = true;
    for(int i = 1; i <= n / 2; i ++){
        if(cnt == b) continue;
        if(cnt == a){
            cout << -1;
            return;
        }
        arr[i] = cnt --;
    }
    cnt = 1;
    for(int i = n; i > n / 2; i --){
        if(cnt == a) continue;
        if(cnt == b){
            cout << -1;
            return;
        }
        arr[i] = cnt ++;
    }
    for(int i = 1; i <= n; i ++){
        cout << arr[i] << " ";
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