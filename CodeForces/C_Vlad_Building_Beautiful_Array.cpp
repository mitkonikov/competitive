#include <bits/stdc++.h>
#define ll long long
#define endl '\n'

using namespace std;

void testCase() {
    int N;
    cin >> N;
    set<int> A;
    for (int i = 0; i < N; i++) {
        int x;
        cin >> x;
        A.insert(x);
    }
    bool odd = 1, even = 1;
    bool is_smaller_odd = 0, is_smaller_even = 0;
    for (auto el: A) {
        if (el % 2 == 0) {
            odd &= (is_smaller_odd);
            is_smaller_even = true;
        } else {
            even &= (is_smaller_odd);
            is_smaller_odd = true;
        }
    }

    cout << (odd || even ? "YES" : "NO") << endl;
}

int main() {
    int t;
    cin >> t;

    while (t--) {
        testCase();
    }

    cout << flush;
    return 0;
}