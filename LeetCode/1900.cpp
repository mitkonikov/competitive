#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> earliestAndLatest(int n, int firstPlayer, int secondPlayer) {
        constexpr int N = 40;
        bool visited[N][N][N] = {};
        int earliest[N][N][N] = {};
        int latest[N][N][N] = {};

        queue<tuple<int, int, int>> q;
        int p1 = min(firstPlayer, secondPlayer);
        int p2 = max(firstPlayer, secondPlayer);
        q.emplace(n, p1, p2);
        visited[n][p1][p2] = true;
        earliest[n][p1][p2] = 1;
        latest[n][p1][p2] = 1;

        while (!q.empty()) {
            auto [cnt, a, b] = q.front();
            q.pop();

            int round = earliest[cnt][a][b];

            if (a + b == cnt + 1) continue;

            int nextCnt = (cnt + 1) / 2;

            if (a - 1 > cnt - b) {
                int mirroredA = cnt + 1 - b;
                int mirroredB = cnt + 1 - a;
                a = mirroredA;
                b = mirroredB;
            }

            if (b * 2 <= cnt + 1) {
                int leftGap = a - 1;
                int middleGap = b - a - 1;

                for (int o1 = 0; o1 <= leftGap; ++o1) {
                    for (int o2 = 0; o2 <= middleGap; ++o2) {
                        int na = o1 + 1;
                        int nb = o1 + o2 + 2;
                        if (na >= nb || na > nextCnt || nb > nextCnt) continue;

                        if (!visited[nextCnt][na][nb]) {
                            visited[nextCnt][na][nb] = true;
                            q.emplace(nextCnt, na, nb);
                        }
                        earliest[nextCnt][na][nb] = minOrInit(earliest[nextCnt][na][nb], round + 1);
                        latest[nextCnt][na][nb] = max(latest[nextCnt][na][nb], round + 1);
                    }
                }
            } else {
                int mirrored = cnt + 1 - b;
                int outerGap = mirrored - a - 1;
                int innerGap = b - mirrored - 1;
                int leftGap = a - 1;

                for (int o1 = 0; o1 <= leftGap; ++o1) {
                    for (int o2 = 0; o2 <= outerGap; ++o2) {
                        int na = o1 + 1;
                        int nb = o1 + o2 + ((innerGap + 1) / 2) + 2;
                        if (na >= nb || na > nextCnt || nb > nextCnt) continue;

                        if (!visited[nextCnt][na][nb]) {
                            visited[nextCnt][na][nb] = true;
                            q.emplace(nextCnt, na, nb);
                        }
                        earliest[nextCnt][na][nb] = minOrInit(earliest[nextCnt][na][nb], round + 1);
                        latest[nextCnt][na][nb] = max(latest[nextCnt][na][nb], round + 1);
                    }
                }
            }
        }

        int minRound = INT_MAX;
        int maxRound = INT_MIN;

        for (int i = 1; i <= n; ++i) {
            for (int a = 1; a <= i / 2; ++a) {
                int b = i + 1 - a;
                if (visited[i][a][b]) {
                    minRound = min(minRound, earliest[i][a][b]);
                    maxRound = max(maxRound, latest[i][a][b]);
                }
            }
        }

        return { minRound, maxRound };
    }

private:
    int minOrInit(int& dst, int val) {
        return dst == 0 ? (dst = val) : min(dst, val);
    }
};