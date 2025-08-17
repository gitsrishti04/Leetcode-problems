class Solution {
private:
    void findCombination(int start, int k, int n, vector<vector<int>> &ans, vector<int> &ds) {
        // Base case: if sum = 0 and exactly k numbers are chosen
        if (n == 0 && ds.size() == k) {
            ans.push_back(ds);
            return;
        }
        
        // If size exceeds k or sum goes negative → stop
        if (ds.size() > k || n < 0) return;

        // Try numbers from 'start' to 9
        for (int i = start; i <= 9; i++) {
            ds.push_back(i);
            findCombination(i + 1, k, n - i, ans, ds); // next index
            ds.pop_back(); // backtrack
        }
    }

public:
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<vector<int>> ans;
        vector<int> ds;
        findCombination(1, k, n, ans, ds); // start from 1, not 0
        return ans;
    }
};
