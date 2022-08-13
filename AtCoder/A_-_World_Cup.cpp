#include <bits/stdc++.h>
#define ll long long
#define endl '\n'

using namespace std;

int main() {
    int n;
    cin >> n;
    while (n % 4 != 2) n++;
    cout << n << endl;
    cout << flush;
    return 0;
}