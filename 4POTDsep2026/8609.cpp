//3871. Count Commas in Range II
/**
 You are given an integer n.
 Return the total number of commas used when writing all integers 
 from [1, n] (inclusive) in standard number formatting.
 In standard formatting:
 A comma is inserted after every three digits from the right.
 Numbers with fewer than 4 digits contain no commas.
*/

class Solution {
public:
    long long countCommas(long long n) {
        long long total = 0;
        for(long long p = 1000; p <= n; p*=1000){
            total += (n-p+1);
            if(p>LLONG_MAX / 1000) break;
        }
        return total;
    }
};