#include <bits/stdc++.h>
#define ll long long
#define endl '\n'

using namespace std;

const int MX = 2e5;
vector<int> sol;

void testCase() {
    int N;
    cin >> N;
    cout << sol[N-1] << endl;
}

int main() {
    sol.resize(MX);
    sol[0] = 1;
    sol[1] = 2;
    sol[2] = 2;
    sol[3] = 2;
    for (int i = 4; i < MX; i++) {
        sol[i] = sol[i/2-1] + 1;
    }
    
    int t;
    cin >> t;

    while (t--) {
        testCase();
    }

    cout << flush;
    return 0;
}