// Task: https://mendo.mk/Task.do?id=46

#include <bits/stdc++.h>

using namespace std;

int main() {
    int START, END;
    cin >> START >> END;

    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    vector<int> travel(END + 1, -1);
    travel[START] = 0;
    for (int i = 0; i < n; i++) {
        vector<int> new_travel(END + 1, -1);
        for (int j = 0; j <= END; j++) {
            if (travel[j] == i) {
                if (j+a[i]<=END) new_travel[j+a[i]] = i+1;
                if (j-a[i]>=0) new_travel[j-a[i]] = i+1;
            }
        }
        travel.swap(new_travel);
    }

    int ans = -1;
    for (int i = END; i >= 0; i--) {
        if (travel[i] == n) {
            ans = i;
            break;
        }
    }

    cout << ans << endl;
    return 0;
}