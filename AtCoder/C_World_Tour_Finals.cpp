#include <bits/stdc++.h>
#define ll long long
#define endl '\n'

using namespace std;

int main() {
    int N, M;
    cin >> N >> M;
    vector<ll> score(M);
    for (int i = 0; i < M; i++) cin >> score[i];
    vector<string> A(N);
    for (int i = 0; i < N; i++) cin >> A[i];
    vector<ll> currentScore(N);
    ll max_score = 0;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            if (A[i][j] == 'o') currentScore[i] += score[j];
        }
        currentScore[i] += i + 1;
        max_score = max(max_score, currentScore[i]);
    }
    vector<ll> miss(N);
    for (int i = 0; i < N; i++) {
        miss[i] = max(0LL, max_score - currentScore[i]);
    }
    for (int i = 0; i < N; i++) {
        vector<int> probs;
        for (int j = 0; j < M; j++) {
            if (A[i][j] == 'x') {
                probs.push_back(score[j]);
            }
        }
        sort(probs.rbegin(), probs.rend());
        int cnt = 0;
        for (int j = 0; j < probs.size(); j++) {
            if (miss[i] <= 0) break;
            miss[i] -= probs[j];
            cnt++;
        }
        cout << cnt << endl;
    }
    return 0;
}