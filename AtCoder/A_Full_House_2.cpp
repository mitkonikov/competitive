#include <bits/stdc++.h>
#define ll long long
#define endl '\n'

using namespace std;

int main() {
    int A, B, C, D;
    cin >> A >> B >> C >> D;
    vector<int> frq(20);
    frq[A]++;
    frq[B]++;
    frq[C]++;
    frq[D]++;
    int twos = 0;
    int threes = 0;
    for (int i = 0; i < 20; i++) {
        if (frq[i] == 2) twos++;
        if (frq[i] == 3) threes++;
    }
    cout << ((twos == 2 || threes == 1) ? "Yes" : "No") << endl;
    return 0;
}