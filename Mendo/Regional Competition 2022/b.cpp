#include <bits/stdc++.h>
#define ll long long
#define endl '\n'

using namespace std;

int main() {
    int n = 4;
    int min_cost = 0, max_cost = 0;

    for (int i = 0; i < n; i++) {
        char c;
        cin >> c;
        if (c == '1' || c == '2' || c == '5') {
            min_cost += (c - '0');
            max_cost += (c - '0');
        } else if (c == 'P') {
            min_cost++; max_cost++;
        } else {
            min_cost += 2;
            max_cost += 5;
        }
    }

    cout << min_cost << " " << max_cost << endl;

    return 0;
}