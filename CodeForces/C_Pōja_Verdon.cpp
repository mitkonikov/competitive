#include <bits/stdc++.h>
#define ll long long
#define endl '\n'
 
using namespace std;
 
int main() {
    int n;
    cin >> n;
    int sum = 0;
    for (int i = 0; i < n; i++) {
        int a;
        cin >> a;
        sum += a;
    }
    cout << sum << endl;
    return 0;
}