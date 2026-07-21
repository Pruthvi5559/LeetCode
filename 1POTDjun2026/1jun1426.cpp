//2130. Maximum Twin Sum of a Linked List
class Solution {
public:
    int pairSum(ListNode* head) {
        ListNode *temp = head;
        ListNode *slow = head;
        ListNode *fast = head->next;
        while(fast != NULL && fast->next!=NULL){
            slow = slow->next;
            fast = fast->next->next;
        }
        ListNode* prev = NULL;
        ListNode* temp2 = slow->next;
        slow->next = NULL;
        while(temp2!=NULL){
            ListNode* front = temp2->next;
            temp2->next = prev;
            prev = temp2;
            temp2 = front;
        }
        ListNode* head2 = prev;
        ListNode* head1 = head;
        int max= 0;
        while(head2 != NULL){
            if(head1->val + head2->val > max){
                max = head1->val + head2->val;
            }
            head1 = head1->next;
            head2 = head2->next;
        }
        return max;
    }
};