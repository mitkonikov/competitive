#include <bits/stdc++.h>
 
using namespace std;
 
void read(map<string, int>& mp) {
    while (true) {
        string S;
        cin >> S;
        if (S[0] == '-' || S[0] == '=') {
            break;
        }
        int s = stoi(S);
        int e;
        string name;
        cin >> e >> name;
        mp[name] += e - s;
    }
}
 
int main() {
    map<string, int> d1, d2;
    read(d1);
    read(d2);
    map<string, int> ans;
 
    for (auto el: d2) {
        if (d1.count(el.first)) {
            ans[el.first] = el.second - d1[el.first];
        } else {
            ans[el.first] = el.second;
        }
    }
 
    for (auto el: d1) {
        if (!ans.count(el.first)) {
            ans[el.first] = -el.second;
        }
    }
 
    if (ans.size() == 0) {
        cout << "No differences found." << endl;
    } else {
        bool one = false;
        for (auto el: ans) {
            if (el.second == 0) continue;
            cout << el.first << " ";
            if (el.second > 0) cout << "+";
            else cout << "-";
            cout << abs(el.second) << endl;
            one = true;
        }
        if (!one) {
            cout << "No differences found." << endl;
        }
    }
    return 0;
}
