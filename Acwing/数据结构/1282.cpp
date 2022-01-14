// todo Aho-Corasick automaton
#include <bits/stdc++.h>
using namespace std;
const int N = 10010, S = 55, M = 1000010;
int n, tr[N * S][26], cnt[N * S], idx, fail[N * S];
void insert(string s){
    int p = 0;
    for (int i = 0; i < s.size(); i ++ ){
        int t = s[i] - 'a';
        if (!tr[p][t]) tr[p][t] = ++ idx;
        p = tr[p][t];
    }
    cnt[p] ++ ;
}
void getFail(){
    queue<int> q;
    for(int i = 0; i < 26; i ++){
        if(tr[0][i]) q.push(tr[0][i]);
    }
    while(q.size()){
        int t = q.front(); q.pop();
        for(int i = 0; i < 26; i ++){
            int p = tr[t][i];
            if(!p) tr[t][i] = tr[fail[t]][i];
            else{
                fail[p] = tr[fail[t]][i];
                q.push(p);
            }
        }
    }
}
int query(string s){
    int res = 0;
    for (int i = 0, j = 0; i < s.size(); i ++ ){
        int t = s[i] - 'a';
        j = tr[j][t];
        int p = j;
        while (p){
            res += cnt[p];
            cnt[p] = 0;
            p = fail[p];
        }
    }
    return res;
}
int main(){
    int T; cin >> T;
    while (T -- ){
        memset(tr, 0, sizeof tr);
        memset(cnt, 0, sizeof cnt);
        memset(fail, 0, sizeof fail);
        idx = 0;
        scanf("%d", &n);
        for (int i = 0; i < n; i ++ ){
            string x; cin >> x;
            insert(x);
        }
        getFail();
        string s; cin >> s;
        cout << query(s) << endl;
    }
    return 0;
}