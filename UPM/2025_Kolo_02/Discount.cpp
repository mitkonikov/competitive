#include "bits/stdc++.h"
 
using namespace std;
 
void test() {
    string S;
    cin >> S;
    int ls = 0;
    for (int i = 1; i < S.size(); i++) {
        if (S[i] == '0') continue;
        if (S[i] <= S[ls]) {
            ls = i;
        }
    }
    for (int i = 0; i < S.size() - 1; i++) {
        if (S[i] == '0') continue;
        if (S[i] == S[ls] && S[i+1] == '0') {
            ls = i;
            break;
        }
    }
    cout << S[ls];
    for (int i = 0; i < S.size(); i++) {
        if (i == ls) continue;
        cout << S[i];
    }
    cout << endl;
}
 
int main() {
    int T;
    cin >> T;
    for (int i = 0; i < T; i++) {
        test();
    }
    return 0;
}