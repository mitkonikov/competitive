#include <bits/stdc++.h>
#define ll long long
#define endl '\n'

using namespace std;

int main() {
    int count = 0;
    for (int i = 0; i < 12; i++) {
        string S;
        cin >> S;
        if (S.size() == i + 1) count++;
    }
    cout << count << endl;
    return 0;
}