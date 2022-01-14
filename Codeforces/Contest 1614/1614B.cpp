#include <bits/stdc++.h>
#define int long long
#define lowbit(x) (x&-x)
#define PII pair<int,int>
#define all(x) x.begin(),x.end()
#define fi first
#define se second
using namespace std;
typedef long long LL;

const int N = 1e5 + 10;

void solve(){
    int n; cin >> n;
    vector<PII> arr(n);
    for(int i = 0; i < n; i ++) 
        cin >> arr[i].first, arr[i].second = i + 1;
    sort(all(arr));
    reverse(all(arr));
    deque<int> dq;
    vector<int> res(n + 1);
    int sum = 0;
    dq.push_back(0);
    for(int i = 0; i < n; i ++){
        sum += (i + 2) / 2 * arr[i].first;
        if(i & 1) dq.push_back(arr[i].second);
        else dq.push_front(arr[i].second);
    }
    cout << (sum << 1) << endl;
    int cnt = 1;
    for(auto x : dq) res[x] = ++ cnt;
    for(auto x : res) cout << x << ' ';
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