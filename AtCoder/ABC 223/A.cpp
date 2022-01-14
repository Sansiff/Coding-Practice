#include <bits/stdc++.h>

using namespace std;

int main()
{
    int x; cin >> x;
    if(x == 0) cout << "No";
    else if(x % 100 == 0) cout << "Yes";
    else cout << "No";

    return 0;
}