//3622. Check Divisibility by Digit Sum and Product

class Solution {
public:
    bool checkDivisibility(int n) {
        int num = n;        // Store original number
        int sum = 0;        // Sum of digits
        int product = 1;    // Product of digits

        while(n != 0){
            int lastDigit = n % 10;  // Extract last digit
            sum += lastDigit;        // Add digit to sum
            product *= lastDigit;    // Multiply digit to product
            n /= 10;                 // Remove last digit
        }
        
        // Check if number is divisible by sum + product
        return num % (sum + product) == 0;
    }
};