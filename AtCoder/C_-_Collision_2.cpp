#include <bits/stdc++.h>
#define ll long long
#define endl '\n'

using namespace std;

int main() {
    int n;
    cin >> n;

    map<int, vector<pair<int, int>>> points;
    for (int i = 0; i < n; i++) {
        int x, y;
        cin >> x >> y;
        points[y].push_back(make_pair(x, i));
    }

    string s;
    cin >> s;

    bool col = false;
    for (auto it: points) {
        sort(it.second.begin(), it.second.end());
        bool right_face = false;
        for (int i = 0; i < it.second.size(); i++) {
            if (s[it.second[i].second] == 'R') {
                right_face = true;
            } else {
                if (right_face) {
                    col = true;
                    break;
                }
            }
        }

        bool left_face = false;
        for (int i = it.second.size() - 1; i >= 0; i--) {
            if (s[it.second[i].second] == 'L') {
                left_face = true;
            } else {
                if (left_face) {
                    col = true;
                    break;
                }
            }
        }
    }

    cout << (col ? "Yes" : "No") << endl << flush;
    return 0;
}