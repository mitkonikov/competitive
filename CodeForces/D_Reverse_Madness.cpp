#include <bits/stdc++.h>
#define ll long long
#define endl '\n'

using namespace std;

// Increments the value at first index and
// decrements at next of last index
void updateRange(vector<int>& count, int i, int j)
{
    count[i]++;
 
    // Check index out of bound
    if (j + 1 < count.size())
        count[j + 1]--;
}
 
// Prefix sum to finalise count value
// at each index
void finaliseCountArray(vector<int>& count)
{
    for (int i = 1; i < count.size(); i++)
        count[i] += count[i - 1];
}
 
// Function for reversing string according
// to each query
string reverseForAll(string S, int N, vector<int> A, int M)
{
    vector<int> count(N, 0);
 
    // Traversal of query array
    for (int i = 0; i < M; i++) {
        int start = A[i] <= (N + 1) / 2 ? A[i] - 1 : N - A[i];
        int end = A[i] <= (N + 1) / 2 ? N - A[i] : A[i] - 1;
 
        // Increment the value of all indices
        // between both indices
        updateRange(count, start, end);
    }
 
    // Finalising count array using prefix sum
    finaliseCountArray(count);
 
    // Storing the characters at indices with
    // odd no. of reversal queries in reverse
    // manner, this stores the required indices
    // to string temp as well as temp is
    // reversed at the same time
    string temp;
    for (int i = count.size() - 1; i >= 0; i--) {
        if (count[i] % 2 != 0)
            temp.push_back(S[i]);
    }
 
    // Storing the new characters in
    // original string
    int i = 0, j = 0;
    for (i = 0; i < count.size(); i++) {
 
        // For characters with odd reversal
        // queries character is taken from
        // string temp
        if (count[i] % 2 != 0)
            S[i] = temp[j++];
 
        // If count is even then there is no
        // need to update characters as those
        // characters do not take part
        // in reversal
    }
 
    // Return final string
    return S;
}

void testCase() {
    int N, K;
    cin >> N >> K;
    string S;
    cin >> S;
    vector<int> L(K), R(K);
    for (int i = 0; i < K; i++) { cin >> L[i]; L[i]--; }
    for (int i = 0; i < K; i++) { cin >> R[i]; R[i]--; }
    int Q;
    cin >> Q;
    vector<string> str;
    for (int i = 0; i < K; i++) {
        str.push_back(S.substr(L[i], R[i]-L[i]+1));
    }
    vector<vector<int>> buckets(K);
    for (int i = 0; i < Q; i++) {
        int X;
        cin >> X;
        X--;
        auto idx = lower_bound(L.begin(), L.end(), X) - L.begin();
        if (idx > 0 && R[idx-1] >= X) idx--;
        buckets[idx].push_back(X - L[idx] + 1);
    }
    string ans = "";
    for (int i = 0; i < K; i++) {
        ans += reverseForAll(str[i], str[i].size(), buckets[i], buckets[i].size());
    }
    cout << ans << endl;
}

int main() {
    int t;
    cin >> t;

    while (t--) {
        testCase();
    }

    cout << flush;
    return 0;
}