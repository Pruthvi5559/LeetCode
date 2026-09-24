//3525. Find X Value of Array II
/*
You are given an array of positive integers nums and a positive integer k. You are also given a 2D array queries, 
where queries[i] = [indexi, valuei, starti, xi].

You are allowed to perform an operation once on nums, where you can remove any suffix from nums such that nums remains non-empty.
The x-value of nums for a given x is defined as the number of ways to perform this operation so that the product of the 
remaining elements leaves a remainder of x modulo k.

For each query in queries you need to determine the x-value of nums for xi after performing the following actions:

Update nums[indexi] to valuei. Only this step persists for the rest of the queries.
Remove the prefix nums[0..(starti - 1)] (where nums[0..(-1)] will be used to represent the empty prefix).
Return an array result of size queries.length where result[i] is the answer for the ith query.

A prefix of an array is a subarray that starts from the beginning of the array and extends to any point within it.
A suffix of an array is a subarray that starts at any point within the array and extends to the end of the array.

Note that the prefix and suffix to be chosen for the operation can be empty.
Note that x-value has a different definition in this version.
*/

class Solution {
public:
    struct Node {
        int product = 1;
        array<int, 5> prefixCount{};
    };

    int n, k, size;
    vector<Node> segTree;

    // Combine two adjacent segments.
    Node merge(const Node& left, const Node& right) {
        Node result;

        result.product = (left.product * right.product) % k;

        // Prefixes entirely inside the left segment.
        for (int r = 0; r < k; r++) {
            result.prefixCount[r] = left.prefixCount[r];
        }

        // Prefixes that extend into the right segment.
        for (int r = 0; r < k; r++) {
            int newRemainder = (left.product * r) % k;

            result.prefixCount[newRemainder] += right.prefixCount[r];
        }

        return result;
    }

    // Create a leaf representing one element.
    Node makeNode(int value) {
        Node node;

        node.product = value % k;
        node.prefixCount[node.product] = 1;

        return node;
    }

    // Apply a point update and rebuild its ancestors.
    void update(int index, int value) {
        index += size;
        segTree[index] = makeNode(value);

        for (index >>= 1; index > 0; index >>= 1) {
            segTree[index] = merge(
                segTree[index << 1],
                segTree[index << 1 | 1]
            );
        }
    }

    // Query the ordered range [left, right].
    Node query(int left, int right) {
        Node leftResult, rightResult;

        left += size;
        right += size + 1;

        while (left < right) {
            if (left & 1) {
                leftResult = merge(leftResult, segTree[left]);
                left++;
            }

            if (right & 1) {
                right--;
                rightResult = merge(segTree[right], rightResult);
            }

            left >>= 1;
            right >>= 1;
        }

        return merge(leftResult, rightResult);
    }

    vector<int> resultArray(vector<int>& nums, int k,
                            vector<vector<int>>& queries) {
        this->n = nums.size();
        this->k = k;

        vector<int> result;
        result.reserve(queries.size());

        // Every non-empty product is 0 modulo 1.
        if (k == 1) {
            for (const auto& q : queries) {
                nums[q[0]] = q[1];

                result.push_back(q[3] == 0 ? n - q[2] : 0);
            }

            return result;
        }

        // Build an iterative segment tree.
        size = 1;
        while (size < n) {
            size <<= 1;
        }

        segTree.assign(2 * size, Node());

        for (int i = 0; i < n; i++) {
            segTree[size + i] = makeNode(nums[i]);
        }

        for (int i = size - 1; i > 0; i--) {
            segTree[i] = merge(
                segTree[i << 1],
                segTree[i << 1 | 1]
            );
        }

        for (const auto& q : queries) {
            int index = q[0];
            int value = q[1];
            int start = q[2];
            int x = q[3];

            // Updates persist across queries.
            nums[index] = value;
            update(index, value);

            // Count valid non-empty prefixes of nums[start ... n-1].
            Node suffix = query(start, n - 1);

            result.push_back(suffix.prefixCount[x]);
        }

        return result;
    }
};