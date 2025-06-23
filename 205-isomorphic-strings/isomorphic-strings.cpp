class Solution {
public:
    bool isIsomorphic(string s, string t) {
        if (s.length() != t.length()) return false;

        unordered_map<char, char> s_to_t, t_to_s;

        for (int i = 0; i < s.length(); i++) {
            char c1 = s[i];
            char c2 = t[i];

            // If mapping exists, check if it's consistent
            if (s_to_t.count(c1) && s_to_t[c1] != c2) return false;
            if (t_to_s.count(c2) && t_to_s[c2] != c1) return false;

            // Otherwise, create a new mapping
            s_to_t[c1] = c2;
            t_to_s[c2] = c1;
        }

        return true;
    }
};
