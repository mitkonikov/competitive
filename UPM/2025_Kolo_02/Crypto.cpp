#include "bits/stdc++.h"
#define endl '\n'
 
using namespace std;
 
int main() {
    cin.tie(0)->sync_with_stdio(0);
    int N;
    cin >> N;
    vector<pair<string, int>> A(N);
    for (int i = 0; i < N; i++) {
        cin >> A[i].first >> A[i].second;
    }
    sort(A.begin(), A.end());
    map<string, int> index;
    for (int i = 0; i < N; i++) {
        index[A[i].first] = i;
    }
    int inc = 0, dec = 0;
    for (int i = 1; i < N; i++) {
        if (A[i].second >= A[i-1].second) inc++;
    }
    for (int i = 0; i < N - 1; i++) {
        if (A[i].second >= A[i+1].second) dec++;
    }
 
    int K;
    cin >> K;
    vector<bool> ans;
    ans.push_back(inc == N - 1 || dec == N - 1);
    for (int i = 0; i < K; i++) {
        string name;
        int value;
        cin >> name >> value;
        int id = index[name];
        
        for (int j = -1; j <= 1; j++) {
            if (id+j > 0 && id+j < N && A[id+j].second >= A[id+j-1].second) inc--;
            if (id+j >= 0 && id+j < N - 1 && A[id+j].second >= A[id+j+1].second) dec--;
        }
 
        A[id].second = value;
 
        for (int j = -1; j <= 1; j++) {
            if (id+j > 0 && id+j < N && A[id+j].second >= A[id+j-1].second) inc++;
            if (id+j >= 0 && id+j < N - 1 && A[id+j].second >= A[id+j+1].second) dec++;
        }
 
        ans.push_back(inc == N - 1 || dec == N - 1);
    }
 
    for (int i = 0; i < ans.size(); i++) {
        if (ans[i]) {
            cout << "Super!" << endl;
        } else {
            cout << "Zzz..." << endl;
        }
    }
    return 0;
}