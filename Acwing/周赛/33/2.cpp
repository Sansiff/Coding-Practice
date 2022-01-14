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

signed main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    string s; cin >> s;
    stack<char> st;
    int res = 0, tmp = 0;
    for(char c : s){
        if(c == '(') st.push(c);
        else if(st.size() && c == ')'){
            st.pop(); tmp ++;
            res = max(res, 2 * tmp);
        }
    }
    cout << res;

    return 0;
}