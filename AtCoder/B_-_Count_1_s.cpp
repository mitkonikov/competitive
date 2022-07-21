#include <bits/stdc++.h>
#define ll long long
#define endl '\n'

using namespace std;

int main() {
    int n;
    cin >> n;

    int score = 0;
    vector<int> v(n);
    for (int i = 0; i < n; i++) {
        cin >> v[i];
        score += v[i];
    }

    int current = 0;
    int max_hit = 0;
    int min_hit = 0;
    int max_up = 0;
    int max_down = 0;
    for (int i = 0; i < n; i++) {
        current += (v[i] ? -1 : 1);
        max_hit = max(max_hit, current);
        min_hit = min(min_hit, current);
        max_up = max(max_up, abs(current - min_hit)); 
        max_down = max(max_down, abs(current - max_hit)); 
    }

    cout << score + max_up - (score - max_down) + 1 << endl;
}