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

void solve(){
    VI num(10); read(num);
    string res = "";
    int cnt = 0, mxx = 0, mxn = 0, last;
    for(int x : num) cnt += x;
    if(num[0] > cnt / 2){
        cout << -1; return;
    }
    else{
        //! 第一位
        rep(i, 1, 10){
            if(num[i] > mxn) mxn = num[i], mxx = i;
        }
        if(mxn > (cnt + 1) / 2){
            cout << -1; return;
        }
        if(mxn == (cnt + 1) / 2){
            res += char(mxx + '0'), cnt --, num[mxx] --, last = mxx;
        }
        else{
            rep(i, 1, 10){
                if(num[i]) {
                    res += char(i + '0'), cnt --, num[i] --, last = i;
                    break;
                }
            }
        }
        //! 
        while(cnt){
            mxn = 0;
            rep(i, 0, 10){
                if(num[i] > mxn) mxn = num[i], mxx = i;
            }
            if(cnt & 1 && mxn == (cnt + 1) / 2){
                if(mxx == last) {
                    cout << -1; return;
                }
                res += char(mxx + '0'), cnt --, num[mxx] --, last = mxx;
            }
            else{
                rep(i, 0, 10){
                    if(num[i] && last != i){
                        res += char(i + '0'), cnt --, num[i] --, last = i;
                        break;
                    }
                }
            }
        }
    }
    cout << res;
}

signed main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int _; cin >> _;
    while(_--){
        solve();
        cout << endl;
    }
    return 0;
}