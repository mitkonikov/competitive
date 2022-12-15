#include <bits/stdc++.h>
#define ll long long

using namespace std;

int main() {
    vector<vector<char>> mat(1000, vector<char>(1000, '.'));
    int L;
    cin >> L;
    int mx_first = 0;
    for (int i = 0; i < L; i++) {
        vector<pair<int, int>> line;
        while (true) {
            int x, y;
            cin >> x >> y;
            line.push_back({ x, y });

            string d;
            cin >> d;
            if (d == "$") {
                break;
            }
        }
        for (int i = 1; i < line.size(); i++) {
            if (line[i].first == line[i-1].first) {
                int a = line[i-1].second;
                int b = line[i].second;
                if (a > b) swap(a, b);
                for (int k = a; k <= b; k++) {
                    mat[k][line[i].first] = '#';
                    mx_first = max(mx_first, k);
                }
            } else {
                mx_first = max(mx_first, line[i].second);
                int a = line[i-1].first;
                int b = line[i].first;
                if (a > b) swap(a, b);
                for (int k = a; k <= b; k++) {
                    mat[line[i].second][k] = '#';
                }
            }
        }
    }
    int ans = 0;
    while (true) {
        bool put = false;
        pair<int, int> cur = { 0, 500 };
        if (mat[0][500] != '.') break;
        while (cur.first <= mx_first) {
            if (mat[cur.first+1][cur.second] != '.') {
                char& left = mat[cur.first+1][cur.second-1];
                char& right = mat[cur.first+1][cur.second+1];
                if (left != '.' && right != '.') {
                    mat[cur.first][cur.second] = '+';
                    ans++;
                    put = true;
                    break;
                } else if (left == '.') {
                    cur.first++;
                    cur.second--;
                    continue;
                } else if (right == '.') {
                    cur.first++;
                    cur.second++;
                    continue;;
                }
                mat[cur.first][cur.second] = '+';
                put = true;
                ans++;
                break;
            } else {
                cur.first++;
            }
        }
        if (!put) {
            break;
        }
    }
    cout << ans << endl;
    return 0;
}