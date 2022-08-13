#include <bits/stdc++.h>
#define ll long long
#define endl '\n'

using namespace std;

int CountSteps(string s1, string s2, int size)
{
    int i = 0, j = 0;
    int result = 0;
 
    while (i < size) {
        j = i;
 
        while (s1[j] != s2[i]) {
            j += 1;
        }
 
        while (i < j) {
            char temp = s1[j];
            s1[j] = s1[j - 1];
            s1[j - 1] = temp;
            j -= 1;
            result += 1;
        }
        i += 1;
    }
    return result;
}

int main() {
    string s;
    cin >> s;
    cout << CountSteps(s, "atcoder", 7);
    cout << flush;
    return 0;
}