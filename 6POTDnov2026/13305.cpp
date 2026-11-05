//1385. Find the Distance Value Between Two Arrays
/*
Given two integer arrays arr1 and arr2, and the integer d, 
return the distance value between the two arrays.

The distance value is defined as the number of elements arr1[i] 
such that there is not any element arr2[j] where |arr1[i]-arr2[j]| <= d.
*/

class Solution {
public:
    int findTheDistanceValue(vector<int>& arr1, vector<int>& arr2, int d) {
        sort(arr2.begin(), arr2.end());
        int cnt = 0;
        for(int x : arr1){
            auto it = lower_bound(arr2.begin(), arr2.end(), x);
            bool ok = true;
            if (it != arr2.end() && *it-x <= d) ok = false;
            if (it != arr2.begin() && x - *prev(it) <=d) ok = false;
            cnt += ok;
        }
        return cnt;
    }
};