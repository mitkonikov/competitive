#include <bits/stdc++.h>
#define ll long long
#define endl '\n'

using namespace std;

int main() {
    int N;
    cin >> N;
    vector<vector<bool>> visited(110, vector<bool>(110, 0));
    for (int i = 0; i < N; i++) {
        int a, b, c, d;
        cin >> a >> b >> c >> d;
        for (int k = a; k < b; k++) {
            for (int l = c; l < d; l++) {
                visited[k][l] = true;
            }
        }
    }
    int count = 0;
    for (int i = 0; i < 110; i++) {
        for (int j = 0; j < 110; j++) {
            if (visited[i][j]) count++;
        }
    }
    cout << count << endl;
    return 0;
}