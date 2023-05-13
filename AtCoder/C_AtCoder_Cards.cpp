#include <bits/stdc++.h>
#define ll long long
#define endl '\n'

using namespace std;

int main() {
    string S, T;
    cin >> S >> T;
    vector<int> fs(26), ft(26);
    string atcoder = "atcoder";
    int AS = 0, AT = 0;
    for (int i = 0; i < S.size(); i++) {
        if (S[i] == '@') AS++;
        else fs[S[i]-'a']++;
    }
    for (int i = 0; i < T.size(); i++) {
        if (T[i] == '@') AT++;
        else ft[T[i]-'a']++;
    }
    for (int i = 0; i < 26; i++) {
        bool inside = 0;
        for (int j = 0; j < atcoder.size(); j++) {
            if (atcoder[j] == (char)('a' + i)) {
                inside = 1;
            }
        }
        if (!inside) {
            if (ft[i] != fs[i]) {
                cout << "No" << endl;
                return 0;
            }
        }
    }
    int mss = 0, mst = 0;
    for (int i = 0; i < 26; i++) {
        if (fs[i] > ft[i]) {
            mst += abs(fs[i] - ft[i]);
        } else {
            mss += abs(fs[i] - ft[i]);
        }
    }
    if (mss > AS || mst > AT) {
        cout << "No" << endl;
        return 0;
    }
    cout << "Yes" << endl;
    return 0;
}