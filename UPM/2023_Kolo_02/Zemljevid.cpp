#include <bits/stdc++.h>
#define ll long long
 
using namespace std;
 
int main() {
    int N, M;
    cin >> N >> M;
    vector<string> A(N);
    for (int i = 0; i < N; i++) {
        cin >> A[i];
    }
    int water = 0, land = 0;
    const char l[5] = { '#', '$', '%', '&', '@' };
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            if (A[i][j] == '.' || A[i][j] == '-' || A[i][j] == '!' || A[i][j] == '~') {
                water++;
            } else {
                bool ok = 0;
                for (int d = 0; d < 5; d++) {
                    if (A[i][j] == l[d]) {
                        ok = 1;
                    }
                }
                if (ok) land++;
            }
        }
    }
    cout << "VODA: " << water << endl;
    cout << "KOPNO: " << land << endl;
    cout << "DRUGO: " << (N * M) - water - land << endl;
    return 0;
}