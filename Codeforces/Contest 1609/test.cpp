#include<bits/stdc++.h>
using namespace std;

int main(){
    freopen("1.out", "w", stdout);
    cout << 1 << endl;
    cout << 2000 << endl;
    for(int i = 1; i <= 2000; i ++){
        if(i * 756 % 5 == 3) cout << 1;
        else cout << 0;
    }
    cout << endl;
    for(int i = 1; i <= 2000; i ++){
        if(i * 756 % 7 == 3) cout << 1;
        else cout << 0;
    }
    return 0;
}