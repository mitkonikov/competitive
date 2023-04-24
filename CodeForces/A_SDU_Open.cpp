#include <bits/stdc++.h>
#define ll long long

using namespace std;

int main() {
    int N;
    cin >> N;
    for (int gold = 1; gold <= N; gold++) {
        for (int silver = 0; silver <= N - gold; silver++) {
            for (int bronze = 0; bronze <= N - gold - silver; bronze++) {
                bool ok1 = (N <= gold * 12);
                bool ok2 = (N <= (gold + silver) * 4);
                bool ok3 = (N <= (gold + silver + bronze) * 2);
                if (ok1 && ok2 && ok3) {
                    cout << gold << " " << silver << " " << bronze << endl;
                    return 0;
                }
            }
        }
    }
    return 0;
}