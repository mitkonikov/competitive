#include <bits/stdc++.h>
#define ll long long
#define endl '\n'

using namespace std;

int main() {
    int N;
    cin >> N;
    int count = 0;
    for (int i = 1; i <= N; i++) {
        int D;
        cin >> D;
        for (int j = 1; j <= D; j++) {
            string Si = to_string(i);
            string Sj = to_string(j);
            set<char> s;
            for (auto el: Si) s.insert(el);
            for (auto el: Sj) s.insert(el);
            count += (s.size() == 1);
        }
    }
    cout << count << endl;
    return 0;
}