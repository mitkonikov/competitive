#include<bits/stdc++.h>
using namespace std;
int gcd(int a, int b) {
    for (int tmp;b;) {
        tmp = a;
        a = b;
        b = tmp % b;
    }
    return a;
}
int main() {
    ios::sync_with_stdio(false);
    int n;
    string s;
    cin >> n;
    cin >> s;
    int sm = 0;
    for (int i = 0; i < n; i++) {
        if (s[i] == '+')sm++;
    }
    int gr = n - sm;
    if (sm > gr)swap(sm, gr);
    int q;
    cin >> q;
    for (int i = 0, a, b; i < q; i++) {
        cin >> a >> b;
        if (a > b)swap(a, b);
        if (gr == sm) {
            cout << "YES" << endl;
            continue;
        }
        if (a == b) {
            cout << "NO" << endl;
            continue;
        }
        int gc = gcd(b, a);
        int mna = b / gc;
        int mnb = a / gc;
        if ((gr - sm) % (mna - mnb)) {
            cout << "NO" << endl;
            continue;
        }
        long long iter = (gr - sm) / (mna - mnb);
        if (iter * mna > gr || iter * mnb > sm) {
            cout << "NO" << endl;
            continue;
        }
        cout << "YES" << endl;
    }
}