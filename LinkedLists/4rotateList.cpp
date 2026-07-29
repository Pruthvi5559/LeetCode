//suboptimal i worst casr can take O(n^2)
class Solution {
public:
    int lengthOfList(ListNode* head){
        ListNode* temp = head;
        int count = 0;
        while(temp!=NULL){
            count++;
            temp=temp->next;
        }
        return count;
    }

    ListNode* rotateRight(ListNode* head, int k) {
        if(head == NULL || head->next == NULL || k==0) return head;
        int n = lengthOfList(head);
        int rotation = k%n;
        while(rotation>0){
            ListNode* temp = head;
            ListNode* prev = NULL;
            while(temp->next!=NULL){
                prev = temp;
                temp = temp->next;
            }
            temp->next = head;
            prev->next = NULL;
            head = temp;
            rotation--;
        }
        return head;
    }
};

//optimal
