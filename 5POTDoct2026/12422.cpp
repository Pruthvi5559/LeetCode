//3942. Minimum Operations to Sort a Permutation
/*
You are given an integer array nums of length n, 
where nums is a permutation of the integers from 0 to n - 1.

You may perform only the following operations:
Reverse the entire array.
Rotate Left by One: Move the first element to the 
end of the array, and rest elements to left by one position.
Return an integer denoting the minimum number of operations 
required to sort the array in increasing order. If it is not 
possible to sort the array using only the given operations, return -1.
*/

class Solution {
public:
    int minOperations(vector<int>& nums) {
        int n = nums.size();
        
        //if there is only one element in the array
        if( n == 1 ) return 0;

        //find the pivot 0 where the dip occurs
        int piv;
        for(int i = 0; i < n; i++){
            if( nums[i] == 0){
                piv = i;
                break;
            }
        }

        //check for cyclic ascending or descending
        bool asc = true;
        bool desc = true;
        for( int i = 1; i < n; i++){
            int val = nums[ ( piv + i ) % n ];

            //if val doesn't match expected ascending seq, set asc=false
            if( val != i ) asc = false;

            //if val doesn't match expected descending seq, set desc=false
            if( val != n-i ) desc = false;

            //if neither order is possible then sorting is not possible return -1
            if( !asc && !desc ) return -1;
        }

        //if arr cyclically asc then cal min operations using left rotation or right rotations
        if(asc) return min( piv, n-piv+2 );

        //// if it's cyclically desc, cal the min operations for that case.
        return min( n-piv, piv+2 );
    }
};