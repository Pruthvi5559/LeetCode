class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        if(head == NULL || head->next == NULL) return head;
        ListNode* temp = head; 
        ListNode* prev = NULL;
        while(temp!=NULL){
            if(temp->next!=NULL && temp->val == temp->next->val){
                int val = temp->val;
                while(temp!=NULL && temp->val == val){
                    temp = temp->next;
                }
                if(prev!=NULL){
                    prev->next = temp;
                }else{
                    head = temp;
                }
            }else{
                prev = temp;
                temp = temp->next;
            }
        }
        return head;
    }
};