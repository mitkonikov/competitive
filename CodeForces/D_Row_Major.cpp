#include <bits/stdc++.h>
#define ll long long
#define endl '\n'

using namespace std;

void testCase() {
    int N;
    cin >> N;
    vector<int> div;
    for (int i = 1; i * i <= N; i++) {
        if (N % i == 0) {
            if (i * i == N) div.push_back(i);
            else {
                div.push_back(i);
                div.push_back(N/i);
            }
        }
    }
    vector<vector<bool>> cant(N, vector<bool>(26, 0));
    sort(div.begin(), div.end());
    vector<int> colors(N);
    auto get_color = [&](int id) {
        for (int j = 0; j < 26; j++) {
            if (!cant[id][j]) return j;
        }
        return -1;
    };
    for (int i = 0; i < N; i++) {
        colors[i] = get_color(i);
        for (int d = 0; d < div.size(); d++) {
            int di = div[d];
            if (i + di < N) cant[i+di][colors[i]] = true;
        }
    }
    for (int el: colors) {
        cout << (char)('a' + el);
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