class Solution {
public:
    int totalFruit(vector<int>& fruits) {
        unordered_map<int, int> basket;
        int left = 0, maxLen = 0;

        for (int right = 0; right < fruits.size(); right++) {
            basket[fruits[right]]++;  // Add current fruit to basket

            // If more than 2 types of fruits in basket, shrink window
            while (basket.size() > 2) {
                basket[fruits[left]]--;  // Remove fruit from left
                if (basket[fruits[left]] == 0) {
                    basket.erase(fruits[left]);  // Erase type if count is 0
                }
                left++;  // Move left pointer to shrink window
            }

            maxLen = max(maxLen, right - left + 1);  // Update max length
        }

        return maxLen;
    }
};
