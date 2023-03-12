#include <bits/stdc++.h>
#define ll long long
#define endl '\n'

using namespace std;

int main() {
    int N;
    cin >> N;
    vector<bool> called(N);
    for (int i = 0; i < N; i++) {
        int x;
        cin >> x;
        x--;
        if (!called[i]) called[x] = true;
    }
    int count = 0;
    for (int i = 0; i < N; i++) {
        if (!called[i]) count++;
    }
    cout << count << endl;
    for (int i = 0; i < N; i++) {
        if (!called[i]) cout << i + 1 << " ";
    }
    cout << endl;
    cout << flush;
    return 0;
}