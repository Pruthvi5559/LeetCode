//1423. Maximum Points You Can Obtain from Cards
class Solution {
public:
    int maxScore(vector<int>& cardPoints, int k) {
        int n = cardPoints.size();

        // lsum -> Sum of cards taken from the left
        // rsum -> Sum of cards taken from the right
        // maxsum -> Maximum score obtained
        int lsum = 0, rsum = 0, maxsum = 0;

        // Initially, take all k cards from the left
        for (int i = 0; i < k; i++) {
            lsum += cardPoints[i];
        }

        // Initialize the answer with the left sum
        maxsum = lsum;

        // Pointer to the last card
        int rIdx = n - 1;

        // Gradually replace one left card with one right card
        for (int i = k - 1; i >= 0; i--) {

            // Remove the current left card
            lsum -= cardPoints[i];

            // Add one card from the right
            rsum += cardPoints[rIdx];
            rIdx--;

            // Update the maximum score
            maxsum = max(maxsum, lsum + rsum);
        }

        return maxsum;
    }
};