#include <bits/stdc++.h>

using namespace std;

int main() {
    string s;
    cin >> s;

    int n = s.size();
    stack<char> output;
    for (int i = 0; i < n; i++) {
        if (s[i] == '<') output.pop();
        else output.push(s[i]);
    }

    string result = "";
    while (!output.empty()) {
        result += output.top();
        output.pop();
    }

    reverse(result.begin(), result.end());
    cout << result << endl;
    
    return 0;
}