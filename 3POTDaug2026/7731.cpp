//2058. Find the Minimum and Maximum Number of Nodes Between Critical Points
/*
A critical point in a linked list is defined as either a local maxima or a local minima.
A node is a local maxima if the current node has a value strictly greater than the previous node and the next node.
A node is a local minima if the current node has a value strictly smaller than the previous node and the next node.

Note that a node can only be a local maxima/minima if there exists both a previous node and a next node.
Given a linked list head, return an array of length 2 containing [minDistance, maxDistance] where minDistance is
 the minimum distance between any two distinct critical points and maxDistance is the maximum distance between any two distinct critical points. If there are fewer than two critical points, return [-1, -1].
*/

class Solution {
public:
    vector<int> nodesBetweenCriticalPoints(ListNode* head) {
        int first = -1;       // First critical point
        int prev = -1;        // Previous critical point
        int minDist = INT_MAX;

        int index = 1;        // Current node's position (1-indexed)

        ListNode* left = head;
        ListNode* curr = head->next;

        while (curr->next != nullptr) {

            // Check whether current node is a critical point
            if ((curr->val > left->val && curr->val > curr->next->val) ||
                (curr->val < left->val && curr->val < curr->next->val)) {

                // First critical point
                if (first == -1) {
                    first = index;
                }

                // Calculate distance from previous critical point
                if (prev != -1) {
                    minDist = min(minDist, index - prev);
                }

                prev = index;
            }

            left = curr;
            curr = curr->next;
            index++;
        }

        // Fewer than two critical points
        if (first == -1 || first == prev)
            return {-1, -1};

        int maxDist = prev - first;

        return {minDist, maxDist};
    }
};