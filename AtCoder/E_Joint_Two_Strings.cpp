#include <bits/stdc++.h>
#define ll long long
#define endl '\n'

using namespace std;

int main() {
    int N;
    string T;
    cin >> N >> T;
    vector<string> A(N);
    for (int i = 0; i < N; i++) cin >> A[i];
    vector<int> front(N), back(N);
    for (int i = 0; i < N; i++) {
        int p = 0;
        for (int j = 0; j < A[i].size(); j++) {
            if (p >= T.size()) break;
            if (A[i][j] == T[p]) {
                p++;
            }
        }
        front[i] = p;
    }
    reverse(T.begin(), T.end());
    for (int i = 0; i < N; i++) {
        int p = 0;
        for (int j = A[i].size() - 1; j >= 0; j--) {
            if (p >= T.size()) break;
            if (A[i][j] == T[p]) {
                p++;
            }
        }
        back[i] = p;
    }
    ll ans = 0;
    vector<int> sorted_back(back);
    sort(sorted_back.begin(), sorted_back.end());
    for (int i = 0; i < N; i++) {
        int max_front_fit = front[i];
        int back_fit = T.size() - max_front_fit;
        int id = lower_bound(sorted_back.begin(), sorted_back.end(), back_fit) -
                 sorted_back.begin();
        if (id < sorted_back.size() && sorted_back[id] >= back_fit) {
            ans += N - id;
        }
    }
    cout << ans << endl;
    return 0;
}