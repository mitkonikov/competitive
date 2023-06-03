#include <bits/stdc++.h>
#define ll long long
#define endl '\n'

using namespace std;

int main() {
    int N;
    cin >> N;
    vector<pair<int, string>> names(N);
    int youngest = 0;
    for (int i = 0; i < N; i++) {
        cin >> names[i].second >> names[i].first;
        if (names[i].first < names[youngest].first) youngest = i;
    }
    for (int i = youngest; i < youngest + N; i++) {
        cout << names[i%N].second << endl;
    }
    cout << flush;
    return 0;
}