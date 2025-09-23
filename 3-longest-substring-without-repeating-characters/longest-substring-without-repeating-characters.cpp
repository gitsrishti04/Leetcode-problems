class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_map<char, int> lastSeen; // store last index of each char
        int left = 0;  // left pointer of window
        int maxLen = 0;

        for (int right = 0; right < s.size(); right++) {
            char c = s[right];

            // If char is already seen and inside the current window
            if (lastSeen.count(c) && lastSeen[c] >= left) {
                left = lastSeen[c] + 1; // move left pointer
            }

            lastSeen[c] = right; // update last seen index
            maxLen = max(maxLen, right - left + 1);
        }

        return maxLen;
    }
};
