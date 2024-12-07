#include <bits/stdc++.h>
#define ll long long
#define endl '\n'

using namespace std;

int main() {
    string S;
    cin >> S;
    sort(S.begin(), S.end());
    cout << (S == "122333" ? "Yes" : "No") << endl;
    return 0;
}