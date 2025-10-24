#include <bits/stdc++.h>
#define ll long long
#define endl '\n'

using namespace std;

int main() {
    int N;
    cin >> N;
    int sum = 1;
    for (int i = 1; i < N; i++) {
        string s = to_string(sum);
        int cur = 0;
        for (auto el : s) cur += el - '0';
        sum += cur;
    }
    cout << sum << endl;
    return 0;
}