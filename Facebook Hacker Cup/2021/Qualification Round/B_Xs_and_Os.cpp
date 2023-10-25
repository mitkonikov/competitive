#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <cmath>

using namespace std;

void testCase() {
    int n;
    cin >> n;

    vector<vector<char>> grid(n, vector<char>(n));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> grid[i][j];
        }
    }

    int maxRow = INT_MIN, maxCol = INT_MIN;
    vector<int> row_prefix(n, 0);
    vector<int> col_prefix(n, 0);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (grid[i][j] == 'O') {
                row_prefix[i] = INT_MIN;
                break;
            }

            if (grid[i][j] == 'X') {
                row_prefix[i]++;;
            }
        }

        maxRow = max(maxRow, row_prefix[i]);
    }

    for (int j = 0; j < n; j++) {
        for (int i = 0; i < n; i++) {
            if (grid[i][j] == 'O') {
                col_prefix[j] = INT_MIN;
                break;
            }

            if (grid[i][j] == 'X') {
                col_prefix[j]++;
            }
        }

        maxCol = max(maxCol, col_prefix[j]);
    }

    if (maxRow == INT_MIN && maxCol == INT_MIN) {
        cout << "Impossible" << endl;
        return;
    }

    int MAX = max(maxRow, maxCol);
    int ans = n - MAX;
    int countAns = 0;

    if (MAX == maxRow && MAX == maxCol) {
        for (int i = 0; i < n; i++) {
            if (row_prefix[i] == MAX && col_prefix[i] == MAX) {
                countAns += 2;
            } else if (row_prefix[i] == MAX) {
                countAns++;
            } else if (col_prefix[i] == MAX) {
                countAns++;
            }
            
            if (row_prefix[i] == MAX && col_prefix[i] == MAX && MAX == n - 1 && grid[i][i] == '.') {
                countAns--;
            }
        }
    } else if (MAX == maxRow) {
        countAns = 0;
        for (int i = 0; i < n; i++) {
            if (row_prefix[i] == MAX) {
                countAns++;
            }
        }
    } else {
        countAns = 0;
        for (int j = 0; j < n; j++) {
            if (col_prefix[j] == MAX) {
                countAns++;
            }
        }
    }

    cout << ans << " " << countAns << endl;
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