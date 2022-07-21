#include <bits/stdc++.h>
#define ll long long
#define endl '\n'

using namespace std;

int main() {
    int k;
    cin >> k;
    int h = 21;
    int m = 0;
    if (k >= 60) {
        h++;
    }
    m += k % 60;
    cout << h << ":" << (m < 10 ? "0" : "") << m << endl;
    cout << flush;
    return 0;
}