#include <bits/stdc++.h>
#define ll long long

using namespace std;

int main() {
    int n;
    cin >> n;

    vector<pair<int, int>> a(n);
    for (int i = 0; i < n; i++) {
        int count, productivity;
        cin >> count >> productivity;

        a[i] = { productivity, -count };
    }

    sort(a.rbegin(), a.rend());

    ll best_ans = 0;
    ll count_people = 0;
    ll smallest_pr = INT_MAX;
    for (int i = 0; i < n; i++) {
        smallest_pr = min(smallest_pr, (ll)a[i].first);
        count_people += -a[i].second;
        best_ans = max(best_ans, smallest_pr * count_people);        
    }

    cout << best_ans << endl;

    return 0;
}