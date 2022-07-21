#include <bits/stdc++.h>

using namespace std;

int main() {
    string n;
    cin >> n;

    if (n.size() == 1 && n[0] == '0') {
        cout << 0 << endl;
        return 0;
    }

    n = "00" + n;

    int result = 0;
    for (int i = (int)n.size() - 1; i >= 0; i--) {
        if (n[i] - '0' < 5 || (n[i] - '0' == 5 && n[i-1] - '0' < 5)) {
            result += n[i] - '0';
        } else {
            result += 10 - (n[i] - '0');
            int ni = i-1;
            while (ni >= 0 && n[ni] - '0' == 9) {
                n[ni] = '0';
                ni--;
            }
            
            n[ni] += 1;
        }

        // cout << n << " => " << result << endl;
    }

    cout << result << endl;

    return 0;
}