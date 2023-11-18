#include <bits/stdc++.h>

typedef long long ll;

using namespace std;

unordered_map<string, ll> m;
vector<ll> neg;
vector<ll> pos;
int T, M, N;

int main() {
    cin >> T;

    string paidPerson, receivedPerson;
    int num;

    for (int i = 0; i < T; i++) {
        m.clear();
        neg.clear();
        pos.clear();
        cin >> M;

        for (int j = 0; j < M; j++) {
            cin >> paidPerson;
            cin >> num;

            m[paidPerson] -= num;
            for (int k = 0; k < num; k++) {
                cin >> receivedPerson;
                m[receivedPerson]++;
            }
        }
        ll res = 0;
        for (const auto &a: m) {
            if (a.second < 0) {
                neg.push_back(a.second);
            } else if (a.second > 0) {
                res += a.second;
                pos.push_back(a.second);
            }
        }
        cout << res << " ";

        sort(neg.begin(), neg.end());
        sort(pos.begin(), pos.end());

        bool ok = true;
        ll it = 0;
        while (ok) {
            it++;
            int k = 0;
            for (int j = 0; j < pos.size(); j++) {
                if (pos[j] <= 0) continue;

                for (k; k < neg.size() && pos[j] > 0; k++) {
                    if (neg[k] < 0) {
                        pos[j]--;
                        neg[k]++;
                    }
                }
            }

            ok = false;
            for (int j = 0; j < neg.size(); j++) {
                if (neg[j] < 0) {
                    ok = true;
                    break;
                }
            }
        }
        cout << it << endl;
    }


    return 0;
}