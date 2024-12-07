#include <bits/stdc++.h>
#define ll long long
#define endl '\n'

using namespace std;

vector<vector<int>> seq;
vector<int> current_seq;

bool dfs(int N, int M, int index, int prev) {
    if (index == N) {
        seq.push_back(current_seq);
        return true;
    }
    for (int i = prev; i <= 10 && index * 10 + i <= M; i++) {
        current_seq.push_back(index * 10 + i);
        dfs(N, M, index + 1, i);
        current_seq.pop_back();
    }
    return true;
}

int main() {
    int N, M;
    cin >> N >> M;
    current_seq.reserve(2 * N);
    dfs(N, M, 0, 1);
    cout << seq.size() << endl;
    for (auto& s : seq) {
        for (auto el : s) {
            cout << el << " ";
        }
        cout << endl;
    }
    return 0;
}