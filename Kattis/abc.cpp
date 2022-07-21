#include <bits/stdc++.h>

using namespace std;

int main() {
    vector<int> arr(3);
    cin >> arr[0] >> arr[1] >> arr[2];
    string s;
    cin >> s;

    sort(arr.begin(), arr.end());

    for (int i = 0; i < 3; i++) {
        cout << arr[s[i]-'A'] << " ";    
    }
    cout << endl;

    return 0;
}