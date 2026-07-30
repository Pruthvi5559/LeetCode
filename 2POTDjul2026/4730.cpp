//3014. Minimum Number of Pushes to Type Word I
class Solution {
public:
    int minimumPushes(string word) {
        unordered_map<int, int> mpp;
        int result = 0;
        int j = 2;

        // Assign each character to a keypad button
        for (char &ch : word) {

            // After button 9, start again from button 2
            if (j > 9) j = 2;

            // Increase the number of letters on this button
            mpp[j]++;

            // Pushes required = position of the letter on the button
            result += mpp[j];

            // Move to the next button
            j++;
        }

        return result;
    }
};

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