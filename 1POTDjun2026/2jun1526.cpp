//2095. Delete the Middle Node of a Linked List
class Solution {
public:
    ListNode* deleteMiddle(ListNode* head) {
        ListNode* prev = NULL, *slow = head, *fast = head;
        if(head == NULL || head->next==NULL) return NULL;
        while(fast!=NULL && fast->next!=NULL){
            fast = fast->next->next;
            prev = slow;
            slow = slow->next;
        }
        prev->next = slow->next;
        delete slow;
        return head;
    }
};
