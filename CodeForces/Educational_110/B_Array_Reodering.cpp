#include <bits/stdc++.h>

using namespace std;

int gcd(int a, int b)
{
    if (a == 0)
        return b;
    return gcd(b % a, a);
}

int main() {
    int t;
    cin >> t;

    while (t--) {
        int n;
        cin >> n;

        vector<int> odd, even;
        for (int i = 0; i < n; i++) {
            int c;
            cin >> c;
            if (c % 2 == 0) even.push_back(c);
            else odd.push_back(c);
        }

        vector<int> a(even.size());
        for (int i = 0; i < even.size(); i++) {
            a[i] = even[i];
        }

        for (int i = 0; i < odd.size(); i++) {
            a.push_back(odd[i]);
        }

        int result = 0;
        for (int i = 0; i < n-1; i++) {
            for (int k = i+1; k < n; k++) {
                if (gcd(a[i], 2*a[k]) > 1) {
                    result++;
                }
            }
        }

        cout << result << endl;
    }
    return 0;
}