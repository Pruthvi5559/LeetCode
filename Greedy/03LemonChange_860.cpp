//860. Lemonade Change
/*
At a lemonade stand, each lemonade costs $5. Customers are standing in a queue to buy from you and order 
one at a time (in the order specified by bills). Each customer will only buy one lemonade and pay with either a $5, $10, or $20 bill. 
You must provide the correct change to each customer so that the net transaction is that the customer pays $5.

Note that you do not have any change in hand at first.

Given an integer array bills where bills[i] is the bill the ith customer pays, return true if you can provide every 
customer with the correct change, or false otherwise.
*/

class Solution {
public:
    bool lemonadeChange(vector<int>& bills) {
        int five = 0;
        int ten = 0;

        for (int bill : bills) {

            if (bill == 5) {
                // No change is needed for a $5 bill.
                five++;
            } else if (bill == 10) {
                // Need one $5 bill as change.
                if (five == 0)
                    return false;

                five--;
                ten++;
            } else {
                // For a $20 bill, change needed is $15.
                // Prefer using one $10 and one $5.
                if (ten > 0 && five > 0) {
                    ten--;
                    five--;
                }
                // Otherwise, use three $5 bills.
                else if (five >= 3) {
                    five -= 3;
                } else {
                    // Not enough change.
                    return false;
                }
            }
        }

        return true;
    }
};