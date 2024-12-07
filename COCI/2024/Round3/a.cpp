#include <bits/stdc++.h>
#define ll long long
#define endl '\n'

using namespace std;

int main() {
    int N;
    cin >> N;
    vector<vector<string>> times(2);
    for (int i = 0; i < N; i++) {
        string place, time;
        cin >> place >> time;
        if (place == "Zagreb-Graz") {
            times[0].push_back(time);
        } else {
            times[1].push_back(time);
        }
    }
    if (times[0].empty() || times[1].empty()) {
        cout << "NEMOGUCE" << endl;
        return 0;
    }
    auto to_min = [](int h, int m) {
        return h * 60 + m;
    };
    auto from_min = [](int m) {
        int hours = m / 60;
        int mins = m % 60;
        string H = to_string(hours);
        string M = to_string(mins);
        if (M.size() == 1) M = "0" + M;
        return H + ":" + M;
    };
    auto get_time = [&](string S) {
        string t1 = "", t2 = "";
        for (int i = 0; i < S.size(); i++) {
            if (S[i] == ':') {
                t2 = S.substr(i + 1);
                break;
            }
            t1 += S[i];
        }
        return to_min(stoi(t1), stoi(t2));
    };
    auto decompose = [&](string S) {
        string t1 = "", t2 = "";
        for (int i = 0; i < S.size(); i++) {
            if (S[i] == '-') {
                t2 = S.substr(i + 2);
                break;
            }
            t1 += S[i];
        }
        int m1 = get_time(t1);
        int m2 = get_time(t2);
        if (m2 < m1) {
            m2 += 24 * 60;
        }
        return make_pair(m1, m2);
    };
    int ans = 1e9;
    for (int i = 0; i < times[0].size(); i++) {
        auto [f1, e1] = decompose(times[0][i]);
        for (int j = 0; j < times[1].size(); j++) {
            auto [f2, e2] = decompose(times[1][j]);
            for (int rep = 0; rep < 3; rep++) {
                if (f2 + rep * 24 * 60 > e1) {
                    ans = min(ans, e1 - f1 + 1 + e2 - f2 + f2 + rep * 24 * 60 - e1);
                }
            }
        }
    }
    cout << from_min(ans) << endl;
    return 0;
}