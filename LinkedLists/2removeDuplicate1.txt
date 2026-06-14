class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        if(head == NULL || head->next == NULL) return head;
        ListNode* temp = head->next;
        ListNode* prev = head;
        while(temp!=NULL){
            if(prev->val == temp->val){
                prev->next = temp->next;
                delete temp;
            }else{
                prev = temp;
            }
            temp = prev->next;
        }
        return head;
    }
};