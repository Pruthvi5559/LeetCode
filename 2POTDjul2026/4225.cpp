//3536. Maximum Product of Two Digits
class Solution {
public:
    int maxProduct(int n) {

        // Largest and second largest digits seen so far
        int large = -1, prevlarge = -1;

        while (n > 0) {

            int digit = n % 10;

            // Update largest and second largest digits
            if (digit > large) {
                prevlarge = large;
                large = digit;
            } 
            else if (digit > prevlarge) {
                prevlarge = digit;
            }

            n /= 10;
        }

        return large * prevlarge;
    }
};