#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    string removeKdigits(string num, int k) {
        stack<char> st;

        for (char digit : num) {
            // While we can remove and top is greater than current digit
            while (!st.empty() && k > 0 && st.top() > digit) {
                st.pop();
                k--;
            }
            st.push(digit);
        }

        // If still k > 0, remove from end
        while (!st.empty() && k > 0) {
            st.pop();
            k--;
        }

        // Build result
        string result = "";
        while (!st.empty()) {
            result.push_back(st.top());
            st.pop();
        }
        reverse(result.begin(), result.end());

        // Remove leading zeros
        int i = 0;
        while (i < (int)result.size() && result[i] == '0') i++;

        result = result.substr(i);

        // Edge case
        return result.empty() ? "0" : result;
    }
};
