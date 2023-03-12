#include <bits/stdc++.h>
#define endl '\n'

using namespace std;

int main() {
    int R, B;
    cin >> R >> B;
    if (R < B) swap(R, B);
    cout << min((R - B) / 2, B) << endl;
    return 0;
}
