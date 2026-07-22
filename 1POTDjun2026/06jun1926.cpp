//1732. Find the Highest Altitudeclass Solution {
class Solution {
public:
    int largestAltitude(vector<int>& gain) {
        int n = gain.size();
        int maxi = 0;
        int gains = 0;
        for(int i = 0; i < n; i++){
            gains = gains + gain[i];
            maxi = max(maxi,gains);
        }
        return maxi;
    }
};