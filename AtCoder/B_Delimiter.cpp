#include <bits/stdc++.h>
#define ll long long
#define endl '\n'

using namespace std;

int main() {
    vector<int> A;
    while (true) {
        int x;
        cin >> x;
        A.push_back(x);
        if (x == 0) break;
    }
    reverse(A.begin(), A.end());
    for (auto el: A) cout << el << endl;
    return 0;
}