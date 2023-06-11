#include <bits/stdc++.h>
#define ll long long

using namespace std;

vector<string> split(string& s, char del) {
    int prev = 0;
    vector<string> res;
    s += del;
    for (int i = 0; i < s.size(); i++) {
        if (s[i] == del) {
            res.push_back(s.substr(prev, i - prev));
            prev = i + 1;
        }
    }
    return res;
};

vector<int> convert(vector<string>& str) {
    int N = str.size();
    vector<int> result(N);
    for (int i = 0; i < N; i++) {
        // assert(false);  // check ll
        result[i] = stoll(str[i]);
    }
    return result;
}

class BeatifulMatrix {
   public:
    int numberOfDefects(vector<string> matrix) {
        int N = matrix.size();
        vector<vector<int>> mat(N);
        for (int i = 0; i < N; i++) {
            auto row = split(matrix[i], ';');
            mat[i] = convert(row);
        }
        int ans = 0;
        int M = mat[0].size();
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < M; j++) {
                bool df = 0;
                for (int k = 0; k < N; k++) {
                    if (k != i && mat[i][j] == mat[k][j]) df = 1;
                }
                for (int k = 0; k < M; k++) {
                    if (k != j && mat[i][j] == mat[i][k]) df = 1;
                }
                if (df) ans++;
            }
        }
        return ans;
    }
};

int main() { return 0; }