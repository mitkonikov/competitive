#include <iostream>
#include <algorithm>
#include <string>
#include <cmath>
#include <cstring>
#include <math.h>

using namespace std;

const int MAX_ANS = 9999999;

void testCase() {
    string s;
    cin >> s;

    int n = s.size();

    int k;
    cin >> k;

    int floyd[26][26];
    for (int i = 0; i < 26; i++)
        for (int j = 0; j < 26; j++)
            floyd[i][j] = MAX_ANS;

    for (int i = 0; i < 26; i++) floyd[i][i] = 0;

    for (int i = 0; i < k; i++) {
        string mapping;
        cin >> mapping;

        int a = mapping[0] - 'A';
        int b = mapping[1] - 'A';

        floyd[a][b] = 1;
    }

    int count[26];
    memset(count, 0, sizeof(int) * 26);
    for (int i = 0; i < n; i++) {
        count[s[i] - 'A']++;
    }

    // floyd warshall
    for (int k = 0; k < 26; k++) {
        for (int i = 0; i < 26; i++) {
            for (int j = 0; j < 26; j++) {
                if (floyd[i][k] + floyd[k][j] < floyd[i][j]) {
                    floyd[i][j] = floyd[i][k] + floyd[k][j];
                }
            }
        }
    }

    int best = MAX_ANS;
    for (int target = 0; target < 26; target++) {
        int currentAns = 0;

        for (int i = 0; i < 26; i++) {
            if (i == target) continue;

            currentAns += floyd[i][target] * count[i];
        }

        best = min(best, currentAns);
    }

    if (best == MAX_ANS) {
        cout << -1 << endl;
    } else {
        cout << best << endl;
    }
}

int main() {
    int t;
    cin >> t;

    for (int i = 0; i < t; i++) {
        cout << "Case #" << i + 1 << ": ";
        testCase();
    }

    return 0;
}