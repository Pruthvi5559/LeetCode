//3870. Count Commas in Range
/*You are given an integer n.

Return the total number of commas used when writing all integers from [1, n] (inclusive) in standard number formatting.

In standard formatting:

A comma is inserted after every three digits from the right.
Numbers with fewer than 4 digits contain no commas.*/

class Solution {
public:
    int countCommas(int n) {

        //Numbers from 1 to 999 have NO commas. 
        //Numbers from 1,000 to 100,000 have EXACTLY 1 comma.
        return max(0, n - 999);
    }
};