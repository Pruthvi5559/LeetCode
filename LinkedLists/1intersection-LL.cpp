struct ListNode {
        int val;
        ListNode *next;
        ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        //BRUTE
        ListNode* t1 = headA;
        ListNode* t2 = headB;
        unordered_set<ListNode*> visited;
        while(t1!=NULL){
            visited.insert(t1);
            t1 = t1->next;
        }
        while(t2!=NULL){
            if(visited.find(t2)){
                return t2;
            }
            t2 = t2->next;
        }
        return NULL;

        //better
        ListNode* t1 = headA;
        ListNode* t2 = headB;
        int t1count=0, t2count=0;
        while(t1 != NULL){
            t1count++;
            t1 = t1->next;
        }
        while(t2!=NULL){
            t2count++;
            t2 = t2->next;
        }
        int diff = abs(t1count - t2count);
        t1 = headA; t2 = headB;
        if(t2count > t1count){
            for(int i = 0; i < diff; i++){
                t2 = t2->next;
            }
        }else{
            for(int i = 0; i < diff; i++){
                t1 = t1->next;
            }
        }
        while(t1!=NULL && t2!=NULL){
            if(t1==t2){
                return t1;
            }
            t1=t1->next;
            t2=t2->next;
        }
        return NULL;

        //optimal
        ListNode* t1 = headA;
        ListNode* t2 = headB;
        
    };
}