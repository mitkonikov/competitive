#include <bits/stdc++.h>
#define ll long long
#define endl '\n'

using namespace std;

int main() {
    string alp[26] = { "@", "8", "(", "|)", "3", "#", "6", "[-]", "|", "_|", "|<", "1", "[]\\/[]", "[]\\[]", "0", "|D", "(,)", "|Z", "$", "']['", "|_|", "\\/", "\\/\\/", "}{", "`/", "2"};
    
    string s;
    while (cin >> s) {
        string ans = "";
        for (int i = 0; i < s.size(); i++) {
            if (s[i] >= 'a' && s[i] <= 'z') {
                ans += alp[s[i]-'a'];
            } else if (s[i] >= 'A' && s[i] <= 'Z') {
                ans += alp[s[i]-'A'];
            } else {
                ans += s[i];
            }
        }
        cout << ans << " ";
    }
    cout << endl;
    return 0;
}