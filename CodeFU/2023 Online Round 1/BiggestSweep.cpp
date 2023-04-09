#include <bits/stdc++.h>

using namespace std;

class BiggestSweep {
   public:
    int findBiggest(vector<int> array, int repetitions) {
        int N = array.size();
        repetitions = min(repetitions, 2 * (int)array.size() + 1);
        vector<int> A(N * repetitions);
        int id = 0;
        for (int i = 0; i < repetitions; i++) {
            for (int j = 0; j < N; j++) {
                A[id++] = array[(j + i) % N];
            }
        }
        int ans = 0;
        for (int i = 0; i < A.size(); i++) {
            set<int> s;
            for (int j = i; j >= 0; j--) {
                if (s.count(A[j])) break;
                s.insert(A[j]);
            }
            int sum = 0;
            for (auto el : s) sum += el;
            ans = max(ans, sum);
        }
        return ans;
    }
};