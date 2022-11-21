#include <bits/stdc++.h>
#define ll long long
#define endl '\n'

using namespace std;

int main() {
    int n;
    cin >> n;
    int best = INT_MAX;
    int id = 0;
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        if (best > x) {
            best = x;
            id = i + 1;
        }
    }   
    cout << id << " " << best << endl;
    return 0;
}