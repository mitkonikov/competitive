#include <bits/stdc++.h>
#define ll long long

using namespace std;

int main() {
    int X;
    cin >> X;
    cout << (10 - (X % 10)) % 10 << endl;
    return 0;
}