#include <bits/stdc++.h>
#define ll long long
#define endl '\n'

using namespace std;

void testCase() {
    int N, M;
    cin >> N >> M;
    string S;
    cin >> S;
    vector<int> black(M);
    set<int> marked;
    for (int i = 0; i < M; i++) {
        cin >> black[i];
        marked.insert(black[i]);
    }
    auto next_white = [&](int i) {
        auto it = lower_bound(black.begin(), black.end(), i);
        if (it == black.end()) {
            return i;
        }
        if (*it != i) {
            return i;
        }
        for (int i = it - black.begin(); i < black.size() - 1; i++) {
            if (black[i] + 1 != black[i+1]) {
                return black[i] + 1;
            }
        }
        return black.back() + 1;
    };
    int last_cell = 1;
    char last_command = 'A';
    for (int i = 0; i < N; i++) {
        if (S[i] == 'A') {
            if (last_command == 'A') {
                marked.insert(last_cell + 1);
                last_cell = last_cell + 1;
            } else {
                int w = next_white(last_cell + 1);
                marked.insert(w + 1);
                last_cell = w + 1;
            }
        } else {
            if (last_command == 'A') {
                int w = next_white(last_cell + 1);
                marked.insert(w);
                last_cell = w;
            } else {
                int w = next_white(last_cell + 1);
                w = next_white(w + 1);
                marked.insert(w);
                last_cell = w;
            }
        }
        last_command = S[i];
    }
    cout << marked.size() << endl;
    for (auto& el : marked) {
        cout << el << " ";
    }
    cout << endl;
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