// 2058 笨拙的手指
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

int fuc(string s, int p){
    int n = s.length();
    int res = 0, cnt = n;
    for(auto c : s){
        res += (c - '0') * pow(p, --cnt);
    }
    return res;
}

signed main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    string s1, s2, ts; cin >> s1 >> s2;
    set<int> st;
    for(int i = 0; i < s2.length(); i ++){
        ts = s2;
        for(int j = 0; j < 3; j ++) {
            ts[i] = j + '0';
            st.insert(fuc(ts, 3));
        }
    }
    for(int i = 0; i < s1.length(); i ++){
        ts = s1;
        for(int j = 0; j < 2; j ++) {
            ts[i] = j + '0';
            if(st.count(fuc(ts, 2)))
                cout << fuc(ts, 2);
        }
    }

    return 0;
}