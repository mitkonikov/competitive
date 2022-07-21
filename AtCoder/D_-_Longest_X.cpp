#include <bits/stdc++.h>

using namespace std;

int main() {
    string s;
    cin >> s;
    int n = s.size();
    vector<bool> lights(n);
    int mx = 0;
    for (int i = 0; i < n; i++) {
        lights[i] = (s[i] == 'X');
        mx += (s[i] == '.');
    }

    int k;
    cin >> k;

    k = min(k, mx);

    int left = 0;
    int right = 0;
    int bestLeft = 0;
    int bestRight = 0;
    int flipZeros = k;
    while (flipZeros > 0) {
        if (!lights[right]) flipZeros--;
        right++;
    }

    while (right < n && lights[right]) right++;

    bestRight = right - 1;
    right--;

    while (right < n && left < n) {
        if (!lights[left]) left++;
        else {
            while (lights[left]) left++;
            left++;
        }

        right++;
        while (right+1 < n && lights[right+1]) right++;

        if (bestRight - bestLeft < right - left) {
            bestRight = right;
            bestLeft = left;
        }
    }

    cout << bestRight - bestLeft + 1 << endl;
    return 0;
}