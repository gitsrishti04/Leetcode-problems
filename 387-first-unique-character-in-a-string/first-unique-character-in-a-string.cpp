class Solution {
public:
    int firstUniqChar(string s) {
         vector<int> freq(26, 0);

        // Count frequency
        for (char c : s) {
            freq[c - 'a']++;
        }

        // Find first unique
        for (int i = 0; i < s.size(); i++) {
            if (freq[s[i] - 'a'] == 1) {
                return i;
            }
        }

        return -1;
        
    }
};