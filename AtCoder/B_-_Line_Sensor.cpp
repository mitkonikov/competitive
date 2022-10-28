#include <bits/stdc++.h>
#define ll long long
#define endl '\n'

using namespace std;

int main() {
    int n, m;
    cin >> n >> m;
    vector<string> mat(n);
    for (int i = 0; i < n; i++) cin >> mat[i];
    for (int i = 0; i < m; i++) {
        int count = 0;
        for (int j = 0; j < n; j++) {
            if (mat[j][i] == '#') {
                count++;
            }
        }
        cout << count << " ";
    }
    cout << endl;
    cout << flush;
    return 0;
}