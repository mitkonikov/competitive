#include <iostream>
#include <vector>
#include <string>

using namespace std;

void testCase() {
    int n;
    cin >> n;

    string s;
    cin >> s;

    int count = 0;
    char letter = 'a';
    for (int i = 0; i < n; i++) {
        if (s[i] == 'O' || s[i] == 'X') {
            if (letter == 'a') {
                letter = s[i];
                continue;
            }

            if (letter != s[i]) {
                count++;
                letter = s[i];
            }
        }
    }

    cout << count << endl;
}

int main() {
    int t;
    cin >> t;

    for (int tt = 0; tt < t; tt++) {
        cout << "Case #" << tt+1 << ": ";
        testCase();
    }

    return 0;
}