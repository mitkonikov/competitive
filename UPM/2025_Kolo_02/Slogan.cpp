#include "bits/stdc++.h"
 
using namespace std;
 
int main() {
    string S;
    cin >> S;
    int K;
    cin >> K;
    vector<pair<int, char>> modifications;
    int last_mod = -1;
    for (int i = 0; i < K; i++) {
        string first;
        cin >> first;
        if (first.size() == 1) {
            if (first == "V" || first == "M") {
                last_mod = i;
                modifications.push_back({ -1, first[0] });
                continue;
            }
        }
 
        int id = stoi(first);
        char ch;
        cin >> ch;
        modifications.push_back({ id, ch });
    }
    for (int i = 0; i < K; i++) {
        if (i == last_mod) {
            if (modifications[i].second == 'V') {
                for (int j = 0; j < S.size(); j++) {
                    S[j] = toupper(S[j]);
                }
            } else {
                for (int j = 0; j < S.size(); j++) {
                    S[j] = tolower(S[j]);
                }
            }
        } else {
            if (modifications[i].first != -1) {
                S[modifications[i].first - 1] = modifications[i].second;
            }
        }
    }
    cout << S << endl;
    return 0;
}