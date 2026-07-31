//215. Kth Largest Element in an Array
class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        int n = nums.size();

        // Min-heap to store the k largest elements
        priority_queue<int, vector<int>, greater<int>> pq;

        // Insert the first k elements into the heap
        for (int i = 0; i < k; i++)
            pq.push(nums[i]);

        // Process the remaining elements
        for (int i = k; i < n; i++) {

            // If the current element is larger than the
            // smallest element in the heap, replace it
            if (nums[i] > pq.top()) {
                pq.pop();
                pq.push(nums[i]);
            }
        }

        // The top of the min-heap is the kth largest element
        return pq.top();
    }
};