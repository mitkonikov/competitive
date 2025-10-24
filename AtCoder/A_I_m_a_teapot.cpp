#include <bits/stdc++.h>
#define ll long long
#define endl '\n'

using namespace std;

int main() {
    int N;
    string S;
    cin >> N >> S;
    reverse(S.begin(), S.end());
    cout << (S.substr(0, 3) == "aet" ? "Yes" : "No") << endl;
    return 0;
}