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
    int n; cin >> n;
    vector<int> a(n), b(n);
    for(int& x : a) cin >> x;
    b = a;
    reverse(b.begin(), b.end());
    int l = -1, r = -1;
    bool flag = false;
    int id1 = 0, id2 = 0, id = -1;
    for(int i = 0; i < n; i ++){
        if(a[i] != b[i]){
            id = i;
            break;
        }
    }
    if(id == -1) cout << "YES";
    else{
        bool flag = true;
        while(id1 < n && id2 < n){
            if(a[id1] != b[id2]){
                if(a[id1] == a[id]) id1 ++;
                else if(b[id2] == a[id]) id2 ++;
                else{
                    flag = false;
                    break;
                }
            }
            else{
                id1 ++, id2 ++;
            }
        }
        if(flag) {
            cout << "YES";
            return;
        }
        flag = true;
        id1 = 0, id2 = 0;
        while(id1 < n && id2 < n){
            if(a[id1] != b[id2]){
                if(a[id1] == b[id]) id1 ++;
                else if(b[id2] == b[id]) id2 ++;
                else{
                    flag = false;
                    break;
                }
            }
            else id1 ++, id2 ++;
        }
        if(flag) cout << "YES";
        else cout << "NO";
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