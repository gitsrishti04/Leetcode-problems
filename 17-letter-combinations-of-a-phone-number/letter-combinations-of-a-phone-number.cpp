class Solution {
public:
    vector<string> letterCombinations(string digits) {
        if (digits.empty()) return {};

        // mapping of digits to letters
        vector<string> keypad = {
            "",    "",    "abc", "def", "ghi", 
            "jkl", "mno", "pqrs", "tuv", "wxyz"
        };

        vector<string> result;
        string current = "";
        backtrack(0, digits, keypad, current, result);
        return result;
    }

private:
    void backtrack(int index, const string &digits, const vector<string> &keypad,
                   string &current, vector<string> &result) {
        if (index == digits.size()) {   // base case
            result.push_back(current); // one valid combination found
            return;
        }

        string letters = keypad[digits[index] - '0']; // get possible letters
        for (char c : letters) {
            current.push_back(c);   // choose a letter
            backtrack(index + 1, digits, keypad, current, result); // recurse
            current.pop_back();     // undo the choice (backtrack)
        }
    }
};
