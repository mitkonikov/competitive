#include <bits/stdc++.h>
#define ll long long
#define endl '\n'
 
using namespace std;
 
int main() {
    cin.tie(0)->sync_with_stdio(0);
    int N;
    cin >> N;
    vector<string> A(N);
    for (int i = 0; i < N; i++) {
        cin >> A[i];
    }
    map<string, vector<int>> mp;
    for (int i = 0; i < N; i++) {
        string str = "";
        for (int j = 0; j < A[i].size(); j++) {
            str += A[i][j];
            mp[str].push_back(i);
        }
    }
    int M;
    cin >> M;
    for (int i = 0; i < M; i++) {
        int k;
        cin >> k;
        vector<int> ptrs(k);
        for (int j = 0; j < k; j++) {
            cin >> ptrs[j];
        }
        string current = "";
        int best_id = -1;
        int best_up = 0;
        for (int j = k - 1, up = 0; j >= 0 && up <= 34; j--, up++) {
            string cs = A[ptrs[j]];
            current = cs + current;
            auto it = mp.find(current);
            if (it != mp.end()) {
                best_up = up + 1;
                best_id = it->second.size();
            }
        }
        if (best_up == 1 && best_id == 1) {
            cout << 0 << endl;
        } else {
            cout << best_up << " " << best_id << endl;
        }
    }
    return 0;
}