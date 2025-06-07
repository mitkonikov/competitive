#include <bits/stdc++.h>
#define ll long long
#define endl '\n'

using namespace std;

int main() {
    int N;
    cin >> N;
    set<int> A;
    for (int i = 0; i < N; i++) {
        int X;
        cin >> X;
        A.insert(X);
    }
    cout << A.size() << endl;
    for (auto el : A) cout << el << " ";
    cout << endl;
    return 0;
}