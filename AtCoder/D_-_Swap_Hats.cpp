#include <bits/stdc++.h>
#define ll long long
#define endl '\n'

using namespace std;

int main() {
    string s1 = "", s2 = "";
    for (int i = 0; i < 3; i++) {
        char c;
        cin >> c;
        s1 += c;
    }
    for (int i = 0; i < 3; i++) {
        char c;
        cin >> c;
        s2 += c;
    }
    set<string> ss1, ss2;
    if (s1 == "RGB" || s1 == "GBR" || s1 == "BRG") {
        ss1.insert(s1);
    } else {
        ss2.insert(s1);
    }
    if (s2 == "RGB" || s2 == "GBR" || s2 == "BRG") {
        ss1.insert(s2);
    } else {
        ss2.insert(s2);
    }
    if (ss1.size() == 1 && ss2.size() == 1) {
        cout << "No" << endl;
    } else {
        cout << "Yes" << endl;
    }
    return 0;
}