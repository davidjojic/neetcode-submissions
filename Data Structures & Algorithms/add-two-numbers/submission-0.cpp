/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */

class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        int prenos = 0;
        ListNode* root = l1;
        ListNode* last = root;
        while(l1 != nullptr && l2 != nullptr){
            last = l1;
            l1->val = l1->val + l2->val+prenos;
            if(l1->val>9){
                l1->val%=10;
                prenos=1;
            }else{
                prenos = 0;
            }
            l1=l1->next;
            l2=l2->next;
        }
        ListNode* llast = last;
        while(l1 != nullptr){
            llast = l1;
            l1->val = l1->val + prenos;
            if(l1->val>9){
                l1->val%=10;
                prenos=1;
            }else{
                prenos = 0;
            }
            l1=l1->next;
        }
        while(l2 != nullptr){
            llast = l2;
            last->next = l2;
            l2->val = l2->val+prenos;

            if(l2->val>9){
                l2->val%=10;
                prenos=1;
            }else{
                prenos = 0;
            }
            l2=l2->next;
            last=last->next;
        }
        if(prenos == 1){
            llast->next = new ListNode(1);
        }
        return root;
    }
};
