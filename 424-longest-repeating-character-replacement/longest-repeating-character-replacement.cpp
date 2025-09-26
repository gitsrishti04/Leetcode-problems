class Solution {
public:
    int characterReplacement(string s, int k) {
        int hash[26] = {0};   // frequency array
        int l = 0, r = 0;
        int maxf = 0;         // max frequency of a char in current window
        int maxlen = 0;

        while (r < s.size()) {
            hash[s[r] - 'A']++;
            maxf = max(maxf, hash[s[r] - 'A']); // update max frequency

            // shrink window if replacements needed > k
            while ((r - l + 1) - maxf > k) {
                hash[s[l] - 'A']--;
                l++;
            }

            maxlen = max(maxlen, r - l + 1);
            r++;
        }
        return maxlen;
    }
};
