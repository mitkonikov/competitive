#include <bits/stdc++.h>
#define ll long long
#define endl '\n'

using namespace std;

int main() {
    char a, b;
    cin >> a >> b;
    if (a > b) swap(a, b);
    vector<int> d{ 3, 1, 4, 1, 5, 9 };
    int sum = 0;
    for (int i = a - 'A'; i <= b - 'A' - 1; i++) {
        sum += d[i];
    }
    cout << sum << endl;
    return 0;
}