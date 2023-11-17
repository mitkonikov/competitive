#include <bits/stdc++.h>
 
using namespace std;
 
int main() {
    string S;
    while (!(cin >> S).eof()) {
        string T;
        cin >> T;
        int K, F;
        cin >> K >> F;
        int count = 0;
        for (int i = 0; i < S.size(); i++) {
            int mistakes = 0;
            for (int j = 0; j < T.size(); j++) {
                if (i + j >= S.size()) {
                    mistakes = 1e9;
                    break;
                }
                if (S[i+j] == T[j]) continue;
                else mistakes++;
            }
            if (mistakes <= K) count++;
            if (count >= F) break;
        }
        cout << ((count >= F) ? "OK" : "PASS") << endl;
    }
    return 0;
}