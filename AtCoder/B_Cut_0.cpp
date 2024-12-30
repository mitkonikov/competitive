#include <bits/stdc++.h>
#define ll long long
#define endl '\n'

using namespace std;

int main() {
    string S;
    cin >> S;
    while (S.back() == '0') S.pop_back();
    if (S.back() == '.') S.pop_back();
    cout << S << endl;
    return 0;
}