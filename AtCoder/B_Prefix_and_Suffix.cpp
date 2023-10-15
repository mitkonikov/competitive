#include <bits/stdc++.h>
#define ll long long
#define endl '\n'

using namespace std;

int main() {
    int N, M;
    cin >> N >> M;
    string S, T;
    cin >> S >> T;
    bool pref = T.substr(0, N) == S;
    bool suff = T.substr(M - N, N) == S;
    if (pref && suff) cout << 0 << endl;
    else if (pref) cout << 1 << endl;
    else if (suff) cout << 2 << endl;
    else cout << 3 << endl; 
    return 0;
}