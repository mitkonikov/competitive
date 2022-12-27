#include <bits/stdc++.h>
#define ll long long

using namespace std;

const int dx[4] = { -1, 0, 1, 0 };
const int dy[4] = { 0, 1, 0, -1 };
const char d[4] = { 'U', 'R', 'D', 'L' };
const int nr[4] = { 1, 2, 3, 0 };
const int nl[4] = { 3, 0, 1, 2 };

// When I was solving this problem
// I thought you should solve it for every possible starting position.
// That's why there are a lot of comments.
// I won't be deleting them.

int main() {
    int N;
    cin >> N;
    vector<string> mat(N);
    for (int i = 0; i < N; i++) {
        cin >> mat[i];
    }
    mat.push_back("");
    mat.insert(mat.begin(), "");
    int M = 0;
    for (int i = 0; i < N; i++) {
        M = max(M, (int)mat[i].size());
    }
    N += 2;
    for (int i = 0; i < N; i++) {
        while (mat[i].size() < M) mat[i] += " ";
    }
    for (int i = 0; i < N; i++) {
        mat[i] = " " + mat[i] + " ";
    }
    M += 2;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            if (mat[i][j] == 'Y') mat[i][j] = ' ';
        }
    }
    string S;
    cin >> S;
    string last_string = "";
    vector<string> parsed;
    int is_number = true;
    for (int i = 0; i < S.size(); i++) {
        if (S[i] >= '0' && S[i] <= '9') {
            if (is_number) {
                last_string += S[i];
            } else {
                if (!last_string.empty()) parsed.push_back(last_string);
                last_string = "";
                is_number = true;
                last_string += S[i];
            }
        } else {
            if (!is_number) {
                last_string += S[i];
            } else {
                if (!last_string.empty()) parsed.push_back(last_string);
                last_string = "";
                is_number = false;
                last_string += S[i];
            }
        }
    }
    if (!last_string.empty()) parsed.push_back(last_string);
    int op = parsed.size();
    int moved = 0;
    string moves = "";
    for (int i = 0; i < op; i++) {
        if (parsed[i][0] >= '0' && parsed[i][0] <= '9') {
            int count = stoi(parsed[i]);
            for (int j = 0; j < count; j++) {
                moves += "M";
            }
        } else {
            moves += parsed[i][0];
        }
    }
    // cout << moves << endl;
    // Precompute the jmp table
    vector<vector<vector<pair<int, int>>>> jmp(N, vector<vector<pair<int, int>>>(M, vector<pair<int, int>>(4, { -1, -1 })));
    for (int i = 0; i < N; i++) {
        {
            int fx = -1, fy = -1;
            for (int j = 0; j < M; j++) {
                if ((mat[i][j] == '.' || mat[i][j] == '#') && fx == -1) {
                    fx = i; fy = j;
                } else if ((mat[i][j] == ' ') && fx != -1) {
                    jmp[i][j][1] = { fx, fy };
                    break;
                }
            }
        }
        {
            int fx = -1, fy = -1;
            for (int j = M-1; j >= 0; j--) {
                if ((mat[i][j] == '.' || mat[i][j] == '#') && fx == -1) {
                    fx = i; fy = j;
                } else if ((mat[i][j] == ' ') && fx != -1) {
                    jmp[i][j][3] = { fx, fy };
                    break;
                }
            }
        }
    }
    for (int i = 0; i < M; i++) {
        {
            int fx = -1, fy = -1;
            for (int j = 0; j < N; j++) {
                if ((mat[j][i] == '.' || mat[j][i] == '#')  && fx == -1) {
                    fx = j; fy = i;
                } else if ((mat[j][i] == ' ') && fx != -1) {
                    jmp[j][i][2] = { fx, fy };
                    break;
                }
            }
        }
        {
            int fx = -1, fy = -1;
            for (int j = N-1; j >= 0; j--) {
                if ((mat[j][i] == '.' || mat[j][i] == '#') && fx == -1) {
                    fx = j; fy = i;
                } else if ((mat[j][i] == ' ') && fx != -1) {
                    jmp[j][i][0] = { fx, fy };
                    break;
                }
            }
        }
    }
    vector<vector<vector<vector<bool>>>> dp(N, vector<vector<vector<bool>>>(M, vector<vector<bool>>(4, vector<bool>(moves.size() + 1, false))));
    for (int j = 0; j < M; j++) {
        if (mat[1][j] == '.') {
            dp[1][j][1][0] = true;
            break;
        }
    }
    // for (int i = 0; i < N; i++) {
    //     for (int j = 0; j < M; j++) {
    //         bool ok = false;
    //         for (int k = 0; k < 4; k++) {
    //             if (jmp[i][j][2].first != -1) {
    //                 ok = true;
    //             }
    //         }
    //         if (ok) {
    //             cout << 'Y';
    //         } else {
    //             cout << mat[i][j];
    //         }
    //     } cout << endl;
    // }
    cout << moves.size() << endl;
    for (int k = 0; k < moves.size(); k++) {
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < M; j++) {
                if (mat[i][j] != '.') continue;
                for (int dir = 0; dir < 4; dir++) {
                    if (!dp[i][j][dir][k]) continue;
                    // cout << k << " ";
                    // I am at dp[k][i][j][dir]
                    // cout << i << " " << j << " " << dir << endl;
                    if (moves[k] == 'M') {
                        int nx = i + dx[dir];
                        int ny = j + dy[dir];
                        // cout << nx << " " << ny << " " << dir << endl;
                        if (mat[nx][ny] == '#') {
                            dp[i][j][dir][k+1] = true;
                            continue;
                        }
                        if (mat[nx][ny] == ' ') {
                            // assert(jmp[nx][ny][dir].first != -1);
                            // cout << "here " << jmp[nx][ny][2].second << endl;
                            // cout << "!" << nx << " " << ny << endl;
                            int lx = nx, ly = ny;
                            nx = jmp[lx][ly][dir].first;
                            ny = jmp[lx][ly][dir].second;
                            // cout << "!" << nx << " " << ny << endl;
                        }
                        // cout << "here " << nx << " " << ny << endl;
                        if (mat[nx][ny] == '#') {
                            dp[i][j][dir][k+1] = true;
                            continue;
                        }
                        dp[nx][ny][dir][k+1] = true;
                    } else {
                        int nd = 0;
                        if (moves[k] == 'L') {
                            nd = nl[dir];
                        } else {
                            nd = nr[dir];
                        }
                        // cout << dir << " " << moves[k] << endl; 
                        dp[i][j][nd][k+1] = true;
                    }
                }
            }
        }
    }
    // cout << "here" << endl;
    // const char d[4] = { 'U', 'R', 'D', 'L' };
    const int da[4] = { 3, 0, 1, 2 };
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            for (int dir = 0; dir < 4; dir++) {
                if (dp[i][j][dir][(int)moves.size()]) {
                    int hash = 1000 * i + 4 * j + da[dir];
                    cout << "End up at " << i << " " << j << " " << d[dir] << " => hash: " << hash << endl;
                }
            }
        }
    }
    return 0;
}