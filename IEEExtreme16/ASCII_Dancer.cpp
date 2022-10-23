#include <bits/stdc++.h>
#define ll long long

using namespace std;

string trim(string s) {
    while (s.size() && s.back() == ' ') s.pop_back();
    return s;
}

bool eq(string s, string t) {
    for (int i = 0; i < t.size(); i++) {
        if (t[i] != s[i]) return false;
    }
    return true;
}

string sr(vector<char> s) {
    string res = "";
    for (auto el: s) res += el;
    return res;
}

void testCase() {
    int n;
    cin >> n;
    vector<char> p1(3);
    p1[1] = 'o';
    p1[0] = ' ';
    p1[2] = ' ';
    vector<char> p2(3);
    vector<char> p3(3);
    p2[0] = '/';
    p2[1] = '|';
    p2[2] = '\\';
    p3[0] = '/';
    p3[1] = ' ';
    p3[2] = '\\';

    string left = "left";
    string right = "right";
    for (int i = 0; i < n; i++) {
        string s;
        getline(cin >> ws, s);
        if (s.empty()) {
            continue;
        }
        
        bool dont = false;
        if (eq(s, left + " hand to head")) {
            p1[2] = ')';
            p2[2] = ' ';
        } else if (eq(s, left + " hand to hip")) {
            p1[2] = ' ';
            p2[2] = '>';
        } else if (eq(s, left + " hand to start")) {
            p1[2] = ' ';
            p2[2] = '\\';
        } else if (eq(s, right + " hand to head")) {
            p1[0] = '(';
            p2[0] = ' ';
        } else if (eq(s, right + " hand to hip")) {
            p1[0] = ' ';
            p2[0] = '<';
        } else if (eq(s, right + " hand to start")) {
            p1[0] = ' ';
            p2[0] = '/';
        } else if (eq(s, left + " leg out")) {
            p3[2] = '\\';
        } else if (eq(s, left + " leg in")) {
            p3[2] = '>';
        } else if (eq(s, right + " leg out")) {
            p3[0] = '/';
        } else if (eq(s, right + " leg in")) {
            p3[0] = '<';
        } else if (eq(s, "turn")) {
            swap(left, right);
            swap(p1[0], p1[2]);
            swap(p2[0], p2[2]);
            swap(p3[0], p3[2]);
            if (p1[0] == ')') p1[0] = '(';
            if (p1[2] == '(') p1[2] = ')';
            if (p2[0] == '>') p2[0] = '<';
            if (p2[2] == '<') p2[2] = '>';
            if (p3[0] == '>') p3[0] = '<';
            if (p3[2] == '<') p3[2] = '>';
            if (p2[0] == '\\') p2[0] = '/';
            if (p2[2] == '/') p2[2] = '\\';
            if (p3[0] == '\\') p3[0] = '/';
            if (p3[2] == '/') p3[2] = '\\';

        } else {
            dont = true;
            if (s.size() > 4) cout << s.substr(4, s.size() - 4) << endl;
        }
        if (!dont) {
            printf("%c%c%c\n", p1[0], p1[1], p1[2]);
            printf("%c%c%c\n", p2[0], p2[1], p2[2]);
            printf("%c%c%c\n", p3[0], p3[1], p3[2]);
        }
    }
}

int main() {
    cin.tie(0);
    
    int t;
    cin >> t;

    while (t--) {
        testCase();
    }

    return 0;
}