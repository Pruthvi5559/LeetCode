//3348. Smallest Divisible Digit Product II

class Solution {
public:
    typedef long long ll;

    // Builds the lexicographically smallest suffix of given length
    // whose digit product is divisible by 'required'
    string freeSlotsFiller(ll required, int length) {
        string str;

        // Greedily extract factors using largest possible digits
        for (int digit = 9; digit >= 2; digit--) {
            while (required % digit == 0) {
                str.push_back(digit + '0');
                required /= digit;
            }
        }

        // Fill remaining positions with '1'
        while (str.length() < length) {
            str.push_back('1');
        }

        // Reverse to obtain the smallest lexicographical order
        reverse(begin(str), end(str));

        return str;
    }

    string smallestNumber(string num, long long t) {

        int n = num.length();

        // Check whether t contains prime factors other than {2,3,5,7}
        ll temp = t;
        for (int primeFact : {2, 3, 5, 7}) {
            while (temp % primeFact == 0) {
                temp /= primeFact;
            }
        }

        // Impossible to form using decimal digits
        if (temp != 1) {
            return "-1";
        }

        // remainingFactor[i] = factor still needed after processing
        // the prefix num[0...i-1]
        vector<ll> remainingFactor(n + 1, t);

        for (int i = 0; i < n; i++) {

            int digit = num[i] - '0';

            // Zero is not allowed in the answer
            if (digit == 0) {
                break;
            }

            remainingFactor[i + 1] =
                remainingFactor[i] / gcd(remainingFactor[i], (ll)digit);
        }

        // Current number already satisfies the condition
        if (remainingFactor[n] == 1) {
            return num;
        }

        // First zero cannot remain in the answer
        int zeroPos = num.find('0');
        int zeroIdx = n - 1;

        if (zeroPos != -1) {
            zeroIdx = zeroPos;
        }

        // Try increasing one digit from right to left
        for (int i = zeroIdx; i >= 0; i--) {

            ll required = remainingFactor[i];

            // Remaining positions after index i
            int freeSlots = n - 1 - i;

            // Try every larger digit at this position
            for (int digit = (num[i] - '0') + 1; digit <= 9; digit++) {

                // Remaining factor after choosing this digit
                ll furtherRequired =
                    required / gcd(required, (ll)digit);

                // Build the smallest possible suffix
                string requiredNumber =
                    freeSlotsFiller(furtherRequired, freeSlots);

                // Valid suffix found
                if (requiredNumber.length() == freeSlots) {
                    return num.substr(0, i) +
                           char(digit + '0') +
                           requiredNumber;
                }
            }
        }

        // No solution with the current length, use one extra digit
        return freeSlotsFiller(t, n + 1);
    }
};