//3345. Smallest Divisible Digit Product I

class Solution {
public:

    // Returns true if the product of digits is divisible by t
    bool isValid(int num, int t) {

        int product = 1;

        while (num > 0) {

            int digit = num % 10;

            // Product becomes 0, which is divisible by any positive t
            if (digit == 0)
                return true;

            product *= digit;
            num /= 10;
        }

        return product % t == 0;
    }

    int smallestNumber(int n, int t) {

        // Check numbers starting from n
        while (!isValid(n, t)) {
            n++;
        }

        return n;
    }
};