#include <bits/stdc++.h>
#define int long long
using namespace std;
#define all(x) x.begin(),x.end()
#define rep(i,l,r) for(int i = l; i <= r; i ++)

const int N = 1e5 + 10;

signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    string s; cin >> s;
    stack<char> st;
    bool flag = true;
    for(int i = 0; i < s.length(); i ++) st.push(s[i]);
    while(st.size() && st.top() != 'o') st.pop();
    if(s.length() - st.size() > 2){
        cout << "No";
        return 0;
    }
    if(st.size()) st.pop();
    while(st.size()){
        int cnt = 0;
        while(st.size() && st.top() != 'o') cnt++, st.pop();
        if(cnt > 2) flag = false;
        if(st.size() && cnt != 2) flag = false;
        if(st.size()) {
            st.pop();
            if(st.size() && st.top() == 'o') flag = false;
        }
    }
    cout << (flag ? "Yes" : "No");
    return 0;
}