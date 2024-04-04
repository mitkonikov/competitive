#include <bits/stdc++.h>
#define ll long long
#define endl '\n'

using namespace std;

int main() {
    int N;
    cin >> N;
    vector<int> A(N);
    for (int i = 0; i < N; i++) cin >> A[i];
    vector<int> rev(N);
    for (int i = 0; i < N; i++) {
        if (A[i] != -1) {
            rev[A[i]-1] = i;
        }
    }
    vector<int> ans;
    for (int i = 0; i < N; i++) {
        if (A[i] == -1) {
            for (int k = 0, ind = i; k < N; k++, ind = rev[ind]) {
                ans.push_back(ind + 1);
            }
            break;
        }
    }
    for (auto el: ans) cout << el << " ";
    cout << endl;
    return 0;
}