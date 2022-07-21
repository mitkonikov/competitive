#include <bits/stdc++.h>

using namespace std;

int main() {
    int n, k;
    cin >> n >> k;

    int memory[11][11];
    memset(memory, 0, sizeof(int) * 11 * 11);

    int num, count, digit;
    for (int i = 0; i < n; i++) {
        scanf("%d", &num);
        count = 0;
        while (num) {
            digit = num % 10;
            memory[digit][count++]++;
            num /= 10;
        }
    }

    string ans = "000000000000";

    for (int i = 0; i <= 10; i++) {
        for (int j = 0; j <= 10; j++) {
            memory[i][j] %= k;
            if (memory[i][j] > 0) {
                ans[j] = '0' + i;
            }
        }
    }

    reverse(ans.begin(), ans.end());
    
    int i = 0;
    for (; i < ans.size(); i++) {
        if (ans[i] != '0') break;
    }

    for (; i < ans.size(); i++) {
        cout << ans[i];
    }
    cout << endl;

    return 0;
}