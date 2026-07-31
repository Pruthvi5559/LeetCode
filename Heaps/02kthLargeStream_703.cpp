//703. Kth Largest Element in a Stream
class KthLargest {
public:
    // Min-heap to store the k largest elements
    priority_queue<int, vector<int>, greater<int>> pq;

    // Stores the value of k
    int k;

    KthLargest(int k, vector<int>& nums) {
        this->k = k;

        // Process all initial elements
        for (int num : nums) {

            // Fill the heap until it contains k elements
            if (pq.size() < k) {
                pq.push(num);
            }
            // If the current element is larger than the
            // smallest element in the heap, replace it
            else if (num > pq.top()) {
                pq.pop();
                pq.push(num);
            }
        }
    }

    int add(int val) {

        // If the heap has fewer than k elements,
        // simply insert the new value
        if (pq.size() < k) {
            pq.push(val);
        }
        // Otherwise, replace the smallest element
        // only if the new value is larger
        else if (val > pq.top()) {
            pq.pop();
            pq.push(val);
        }

        // The top of the min-heap is the kth largest element
        return pq.top();
    }
};