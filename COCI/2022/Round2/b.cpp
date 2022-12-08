#include <bits/stdc++.h>
#define ll long long
#define endl '\n'

using namespace std;

vector<string> solve(ll X, ll Y, bool flip) {
    vector<string> ans;
    if (!flip) ans.push_back("C C B"); // B = 0
    else ans.push_back("C C A"); // B = 0
    ll x = X;
    for (int i = 0; i < 60; i++) {
        if ((1LL << i) & Y) {
            if (!flip) ans.push_back("A B B"); // B += A
            else ans.push_back("B A A");
        }
        if ((unsigned ll)x + x > 1e18) break;
        if (!flip) ans.push_back("A A A"); // A += A
        else ans.push_back("B B B"); // A += A
        x *= 2;
    }
    return ans;
}

int main() {
    ll X, Y;
    cin >> X >> Y;

    auto v1 = solve(X, Y, false);
    auto v2 = solve(Y, X, true);

    bool swapped = false;
    if (v2.size() < v1.size()) {
        swap(v1, v2);
        swapped = true;
    }
    
    cout << v1.size() << endl;
    for (auto el: v1) {
        cout << el << endl;
    }
    
    if (!swapped) {
        cout << "B" << endl;
    } else {
        cout << "A" << endl;
    }

    return 0;
}