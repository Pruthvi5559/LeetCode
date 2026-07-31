//3016. Minimum Number of Pushes to Type Word II
class Solution {
public:
    int minimumPushes(string word) {
        // Store the frequency of each character
        vector<int> freq(26, 0);

        for (char c : word) {
            freq[c - 'a']++;
        }

        // Sort frequencies in descending order
        sort(freq.begin(), freq.end(), greater<int>());

        int result = 0;

        // Assign the minimum push count to the most frequent characters
        for (int i = 0; i < 26 && freq[i] > 0; i++) {
            result += ((i / 8) + 1) * freq[i];
        }

        return result;
    }
};