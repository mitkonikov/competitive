#include <bits/stdc++.h>
#define ll long long
#define endl '\n'

using namespace std;

int main() {
    int N;
    cin >> N;
    if (N % 5 <= 2) {
        cout << N / 5 * 5 << endl;
    } else {
        cout << N / 5 * 5 + 5 << endl;
    }
    return 0;
}