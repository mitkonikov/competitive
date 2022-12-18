#include <bits/stdc++.h>
#define ll long long

using namespace std;

int main() {
    int N;
    cin >> N;
    string S;
    cin >> S;

    int ones = 0, zeros = 0;
    for (int i = 0; i < N; i++) {
        if (S[i] == '1') ones++;
        else zeros++;
    }
    
    int shift = 1;
    int pos = 0;
    for (int i = 0; i < ones; i++) {
        pos += shift;
        shift *= 2;
    }

    shift = 1;
    int end = (1 << N) - 1;
    for (int i = 0; i < zeros; i++) {
        end -= shift;
        shift *= 2;
    }
    
    for (int i = pos; i <= end; i++) {
        cout << i + 1 << " ";
    } cout << endl;

    cout << endl;
    return 0;
}