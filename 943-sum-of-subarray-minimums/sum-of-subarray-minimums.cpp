#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int sumSubarrayMins(vector<int>& A) {
        int n = A.size();
        const int MOD = 1'000'000'007;
        vector<int> prev(n), next(n);
        stack<int> st;

        // prev less (strictly less): index of previous element < A[i]
        for (int i = 0; i < n; ++i) {
            while (!st.empty() && A[st.top()] >= A[i]) st.pop();
            prev[i] = st.empty() ? -1 : st.top();
            st.push(i);
        }

        // clear stack to reuse
        while (!st.empty()) st.pop();

        // next less or equal: index of next element <= A[i]
        for (int i = n - 1; i >= 0; --i) {
            while (!st.empty() && A[st.top()] > A[i]) st.pop();
            next[i] = st.empty() ? n : st.top();
            st.push(i);
        }

        long long ans = 0;
        for (int i = 0; i < n; ++i) {
            long long left = i - prev[i];
            long long right = next[i] - i;
            long long contrib = (left * right) % MOD;
            contrib = (contrib * (A[i] % MOD)) % MOD;
            ans = (ans + contrib) % MOD;
        }
        return (int)ans;
    }
};
