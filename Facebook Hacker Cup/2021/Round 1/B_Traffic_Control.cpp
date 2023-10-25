#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <cmath>
#include <queue>

using namespace std;

void testCase() {
    int n, m;
    cin >> n >> m;

    int time1, time2;
    cin >> time1 >> time2;

    vector<vector<int>> roads(n, vector<int>(m, 1000));

    int sum1 = 0, sum2 = 0;
    for (int i = 0; i < m-1; i++) {
        roads[0][i] = 1;
        sum1 += 1;
    }

    for (int i = 0; i < n; i++) {
        roads[i][m-1] = 1;
        sum1 += 1;
        sum2 += 1;
    }

    for (int i = 0; i < m-1; i++) {
        roads[n-1][i] = 1;
        sum2 += 1;
    }

    bool possible = true;

    if (sum1 < time1) {
        roads[0][0] += time1 - sum1;
    } else if (sum1 > time1) {
        possible = false;
    }

    if (sum2 < time2) {
        roads[n-1][0] += time2 - sum2;
    } else if (sum2 > time2) {
        possible = false;
    }
    
    if (possible) {
        cout << "Possible" << endl;
    } else {
        cout << "Impossible" << endl;
        return;
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cout << roads[i][j] << " ";
        }
        cout << "\n";
    }
}

int main() {
    int t;
    cin >> t;

    for (int tt = 0; tt < t; tt++) {
        cout << "Case #" << tt+1 << ": ";
        testCase();
    }

    return 0;
}