#include <bits/stdc++.h>
#define ll long long
#define endl '\n'

using namespace std;

int main() {
    int h, m;
    cin >> h >> m;

    int start = h * 60 + m;
    for (int i = start; i < 3000; i++) {
        int t = i % 1440;
        int h = t / 60;
        int m = t % 60;
        string hs = to_string(h);
        if (hs.size() == 1) hs = "0" + hs;
        string ms = to_string(m);
        if (ms.size() == 1) ms = "0" + ms;
        swap(ms[0], hs[1]);
        int hhs = stoi(hs);
        int mms = stoi(ms);
        if (mms >= 0 && mms <= 59 && hhs >= 0 && hhs <= 23) {
            cout << h << " " << m << endl;
            return 0;
        }
    }

    cout << flush;
    return 0;
}