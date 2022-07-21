#include <bits/stdc++.h>
#define ll long long
#define endl '\n'

using namespace std;

int main() {
    string s;
    cin >> s;
    int n = s.size();
    float space = 0, lower = 0, upper = 0, symbol = 0;
    for (int i = 0; i < n; i++) {
        if (s[i] == '_') space++;
        else if (s[i] >= 'a' && s[i] <= 'z') lower++;
        else if (s[i] >= 'A' && s[i] <= 'Z') upper++;
        else symbol++;
    }
    cout << fixed << setprecision(15) << space / n << endl << lower / n << endl << upper / n << endl << symbol / n << endl;
    return 0;
}