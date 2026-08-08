//3302. Find the Lexicographically Smallest Valid Sequence
class Solution {
public:
    vector<int> validSequence(string word1, string word2) {
        int n = word1.size();
        int m = word2.size();

        // last[i] = index in word1 where word2[i] can be matched
        // while matching word2 from right to left.
        vector<int> last(m, -1);

        int word2Index = m - 1;

        // Find a subsequence of word2 from right to left.
        for (int word1Index = n - 1; word1Index >= 0 && word2Index >= 0;
             word1Index--) {

            if (word1[word1Index] == word2[word2Index]) {
                last[word2Index] = word1Index;
                word2Index--;
            }
        }

        vector<int> result(m);

        // Whether we have already used our one allowed modification.
        bool usedChange = false;

        word2Index = 0;

        // Greedily choose the smallest possible index.
        for (int word1Index = 0; word1Index < n && word2Index < m;
             word1Index++) {

            char currentChar = word1[word1Index];
            char requiredChar = word2[word2Index];

            // Case 1: Characters already match.
            bool charactersMatch = (currentChar == requiredChar);

            // Case 2: Use the one allowed modification.
            // The remaining word2 suffix must still be matchable.
            bool canUseChange =
                !usedChange &&
                (word2Index == m - 1 || word1Index < last[word2Index + 1]);

            if (charactersMatch || canUseChange) {

                result[word2Index] = word1Index;

                // Mark the modification as used if characters differ.
                if (!charactersMatch) {
                    usedChange = true;
                }

                word2Index++;
            }
        }

        // Could not match the entire word2.
        if (word2Index < m) {
            return {};
        }

        return result;
    }
};