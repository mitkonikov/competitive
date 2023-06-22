#include <bits/stdc++.h>
#define ll long long
#define endl '\n'

using namespace std;

void testCase() {
    int N;
    cin >> N;
    bool flip = 0;
    string S = "";
    vector<int> A;
    for (int i = 0; i < N; i++) {
        int x;
        cin >> x;
        if (A.empty() || 
            (flip == 0 && (A.back() <= x || A.front() >= x)) || 
            (flip == 1 && A.back() <= x && A.front() >= x)) {
            if (flip == 0 && !A.empty() && x < A.back()) flip = 1;
            A.push_back(x);
            S += "1";
        } else {
            S += "0";
        }
    }
    cout << S << endl;
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