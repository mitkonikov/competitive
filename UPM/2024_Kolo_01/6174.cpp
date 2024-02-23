#include "bits/stdc++.h"
#define ll long long
 
using namespace std;
 
int main() {
    int N;
    cin >> N;
    int count = 0;
    while (N != 6174) {
        string NS = to_string(N);
        while (NS.size() < 4) NS.push_back('0');
        string A = NS, D = NS;
        sort(A.begin(), A.end());
        sort(D.rbegin(), D.rend());
        reverse(A.begin(), A.end());
        reverse(D.begin(), D.end());
        while (A.size() > 1 && A.back() == '0') A.pop_back();
        while (D.size() > 1 && D.back() == '0') D.pop_back();
        reverse(A.begin(), A.end());
        reverse(D.begin(), D.end());
        int y = stoi(A);
        int x = stoi(D);
        N = x - y;
        count++;
    }
    cout << count << endl;
    return 0;
}