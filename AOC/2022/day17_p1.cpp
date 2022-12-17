#include <bits/stdc++.h>
#define ll long long

using namespace std;

const int mx = 1000000;
const int rounds = 2022;

int main() {
    string s;
    cin >> s;
    vector<vector<char>> mat(mx, vector<char>(7, '.'));
    int floor = mx;
    vector<vector<string>> rocks(5);
    rocks[0] = { "####" };
    rocks[1] = { ".#.", "###", ".#." };
    rocks[2] = { "..#", "..#", "###" };
    rocks[3] = { "#", "#", "#", "#" };
    rocks[4] = { "##", "##" };
    int jet = 0;
    auto valid = [&](int x, int y) {
        return (x >= 0 && y >= 0 && x < mx && y < 7 && mat[x][y] == '.');
    };
    for (int i = 0; i < rounds; i++) {
        int x = floor - 3 - rocks[i%5].size();
        int y = 2;
        int index = 0;
        while (true) {
            if (index % 2 == 0) {
                // The rock should be pushed
                bool ok = true;
                for (int k = 0; k < rocks[i%5].size(); k++) {
                    for (int l = 0; l < rocks[i%5][k].size(); l++) {
                        if (rocks[i%5][k][l] != '.' && 
                            !valid(x + k, y + l + (s[jet] == '>' ? 1 : -1))) {
                                ok = false;
                        }
                    }
                }
                if (ok) {
                    y += (s[jet] == '>' ? 1 : -1);
                }
                jet = (jet + 1) % s.size();
            } else {
                // It falls
                bool ok = true;
                for (int k = 0; k < rocks[i%5].size(); k++) {
                    for (int l = 0; l < rocks[i%5][k].size(); l++) {
                        if (rocks[i%5][k][l] != '.' && !valid(x + k + 1, y + l)) {
                            ok = false;
                        }
                    }
                }
                if (ok) {
                    x++;
                } else {
                    break;
                }
            }
            index++;
        }
        for (int k = 0; k < rocks[i%5].size(); k++) {
            for (int l = 0; l < rocks[i%5][k].size(); l++) {
                if (rocks[i%5][k][l] != '.') mat[x+k][y+l] = '#';
            }
        }
        floor = min(floor, x);
    }
    cout << mx - floor << endl;
    return 0;
}