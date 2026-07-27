//904. Fruit Into Baskets
class Solution {
public:
    int totalFruit(vector<int>& fruits) {
        int left = 0, right = 0;
        int maxlen = 0;
        int n = fruits.size();

        // Stores the count of each fruit type in the current window
        unordered_map<int, int> mpp;

        while (right < n) {

            // Include current fruit in the window
            mpp[fruits[right]]++;

            // Shrink the window until it contains at most 2 fruit types
            while (mpp.size() > 2) {

                mpp[fruits[left]]--;

                // Remove fruit type if its count becomes zero
                if (mpp[fruits[left]] == 0) {
                    mpp.erase(fruits[left]);
                }

                left++;
            }

            // Update the maximum valid window length
            maxlen = max(maxlen, right - left + 1);

            right++;
        }

        return maxlen;
    }
};