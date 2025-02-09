#include <bits/stdc++.h>
#define ll long long
 
using namespace std;
 
vector<string> split(string S) {
    vector<string> vec;
    string current = "";
    for (int i = 0; i < S.size(); i++) {
        if (S[i] == ' ') {
            if (!current.empty()) vec.push_back(current);
            current = "";
        } else {
            current += S[i];
        }
    }
    if (!current.empty()) vec.push_back(current);
    return vec;
}
 
struct Party {
    string name;
    int party_votes;
    vector<pair<string, int>> votes;
    int M;
 
    pair<string, int> get() {
        string S;
        getline(cin, S);
        auto vec = split(S);
        S = "";
        for (int i = 0; i < vec.size() - 1; i++) {
            if (i == vec.size() - 2) S += vec[i];
            else S += vec[i] + " ";
        }
        return make_pair(S, stoi(vec.back()));
    }
 
    void read(int M) {
        this->M = M;
        auto p = get();
        name = p.first;
        party_votes = p.second;
        votes.resize(M);
        for (int i = 0; i < M; i++) {
            votes[i] = get();
        }
    }
 
    void solve(int cand) {
        vector<string> ans;
        vector<bool> chosen(M);
        vector<int> order(M);
        iota(order.begin(), order.end(), 0);
        sort(order.begin(), order.end(), [&](int x, int y) {
            if (votes[x].second == votes[y].second) return x < y;
            return votes[x].second > votes[y].second;
        });
        int rem = cand;
        for (int i = 0; i < cand; i++) {
            int u = order[i];
            ll vt = votes[u].second;
            if (vt * 2 * M >= party_votes) {
                ans.push_back(votes[u].first);
                chosen[u] = true;
                rem--;
            }
        }
        for (int i = 0; rem > 0 && i < M; i++) {
            if (chosen[i]) continue;
            ans.push_back(votes[i].first);
            chosen[i] = true;
            rem--;
        }
 
        for (int i = 0; i < ans.size(); i++) {
            cout << ans[i] << " (" << name << ")" << endl;
        }
    }
};
 
struct Slot {
    ll A, B;
    int party_id;
    int party_votes;
 
    bool operator<(const Slot& b) const {
        if (A * b.B == B * b.A) return party_votes > b.party_votes;
        return A * b.B > B * b.A;
    }
};
 
int main() {
    int M, N;
    string S;
    getline(cin, S);
    auto vec = split(S);
    M = stoi(vec[0]);
    N = stoi(vec[1]);
    vector<Party> parties(N);
    for (int i = 0; i < N; i++) {
        parties[i].read(M);
    }
    // priority_queue<Slot, vector<Slot>, greater<Slot>> pq;
    vector<Slot> pq;
    for (int i = 0; i < N; i++) {
        for (int j = 1; j <= M; j++) {
            pq.push_back({ parties[i].party_votes, j, i, parties[i].party_votes });
        }
    }
    sort(pq.begin(), pq.end());
    vector<int> per_party(N);
    for (int i = 0; i < M; i++) {
        auto top = pq[i];
        per_party[top.party_id]++;
    }
    for (int i = 0; i < N; i++) {
        if (per_party[i] > 0)
            parties[i].solve(per_party[i]);
    }
    return 0;
}