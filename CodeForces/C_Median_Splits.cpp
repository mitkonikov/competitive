#include <bits/stdc++.h>
#define ll long long
#define endl '\n'

using namespace std;

template<typename T>
struct Median {
  priority_queue<T, vector<T>, greater<T>> right;
  priority_queue<T, vector<T>, less<T>> left;
  
  T get() {
    if (left.empty() && right.empty()) return -1;
    if (left.empty()) return right.top();
    if (right.empty()) return left.top();
    if (left.size() == right.size()) return left.top();
    return left.size() > right.size() ? left.top() : right.top();
  }

  void insert(T num) {
    T median = get();
    if (num < median) {
      if (left.size() > right.size()) {
        right.push(left.top());
        left.pop();
      }
      left.push(num);
    } else {
      if (right.size() > left.size()) {
        left.push(right.top());
        right.pop();
      }
      right.push(num);
    }
  }
};

void testCase() {
    int N, K;
    cin >> N >> K;
    vector<int> A(N);
    for (int i = 0; i < N; i++) {
        cin >> A[i];
    }
    Median<int> left;
    Median<int> right;
    vector<int> med_left(N);
    vector<int> med_right(N);
    vector<bool> right_bool(N);
    for (int i = N - 1; i >= 0; i--) {
        right.insert(A[i]);
        med_right[i] = right.get();
        right_bool[i] = med_right[i] <= K;
        if (i < N - 1) right_bool[i] = right_bool[i] || right_bool[i+1];
    }
    for (int i = 0; i < N; i++) {
        left.insert(A[i]);
        med_left[i] = left.get();
        if (med_left[i] <= K) {
            if (i + 2 < N && right_bool[i+2]) {
                cout << "YES" << endl;
                return;
            }
        }
    }
    vector<bool> smaller(N);
    for (int i = 0; i < N; i++) {
        smaller[i] = (A[i] <= K);
    }
    vector<bool> extended = smaller;
    int current = 0;
    for (int i = 1; i < N - 1; i++) {
        if (smaller[i]) {
            current++;
        }
        extended[i] = extended[i] || (current > 0);
        if (!smaller[i]) {
            current--;
            current = max(current, 0);
        }
    }
    for (int i = 1; i < N - 1; i++) {
        if (extended[i]) {
            if (i < N - 1 && med_right[i+1] <= K) {
                cout << "YES" << endl;
                return;
            }
        }
    }
    extended = smaller;
    current = 0;
    for (int i = N - 2; i >= 1; i--) {
        if (smaller[i]) {
            current++;
        }
        extended[i] = extended[i] || (current > 0);
        if (!smaller[i]) {
            current--;
            current = max(current, 0);
        }
    }
    for (int i = 1; i < N - 1; i++) {
        if (extended[i]) {
            if (i > 0 && med_left[i-1] <= K) {
                cout << "YES" << endl;
                return;
            }
        }
    }
    cout << "NO" << endl;
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