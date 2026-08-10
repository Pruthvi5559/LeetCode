//23. Merge k Sorted Lists
class Compare {
public:
    // Min-heap: node with the smallest value comes first
    bool operator()(ListNode* a, ListNode* b) {
        return a->val > b->val;
    }
};

class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {

        // Min-heap containing the current smallest node
        // from each linked list
        priority_queue<ListNode*, vector<ListNode*>, Compare> pq;

        // Add the first node of every non-empty list
        for (auto list : lists) {
            if (list != NULL) {
                pq.push(list);
            }
        }

        // Dummy node simplifies building the result list
        ListNode* dummy = new ListNode(0);
        ListNode* tail = dummy;

        while (!pq.empty()) {

            // Get the smallest available node
            ListNode* smallest = pq.top();
            pq.pop();

            // Add it to the merged list
            tail->next = smallest;
            tail = tail->next;

            // Add the next node from the same list
            if (smallest->next != NULL) {
                pq.push(smallest->next);
            }
        }

        return dummy->next;
    }
};