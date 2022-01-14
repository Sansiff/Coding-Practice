// RE了好多发 原因是idx没有清空
#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 10;

int son[N][15], idx;
bool exis[N], flag;

void insert(string s){
    int p = 0;
    for(int i = 0; i < s.length(); i ++){
        int u = s[i];
        if(!son[p][u]) son[p][u] = ++ idx;
        if(exis[p]) flag = true;
        p = son[p][u];
    }
    exis[p] = 1;
}

bool cmp(string s1, string s2){
    return s1.length() < s2.length();
}

void solve(){
    memset(son, 0, sizeof son);
    memset(exis, 0, sizeof exis);
    flag = false, idx = 0;
    int n; cin >> n;
    vector<string> arr(n);
    for(auto& x : arr) cin >> x;
    sort(arr.begin(), arr.end(), cmp);
    for(auto x : arr) insert(x);
    if(!flag) cout << "YES";
    else cout << "NO";
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int t; cin >> t;
    while(t --){
        solve();
        cout << endl;
    }
    return 0;
}