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
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        ListNode *root = nullptr;
        ListNode *tren = nullptr;
        if(list1 == nullptr){
            root = list2;
            return root;
        }
        if(list2 == nullptr){
            root = list1;
            return root;
        }
        if(list1->val < list2->val){
            root = list1;
            list1=list1->next;
        }else{
            root = list2;
            list2=list2->next;
        }
        tren = root;
        while(list1 != nullptr && list2 != nullptr){
            if(list1->val < list2->val){
                tren->next = list1;
                list1=list1->next;
            }else{
                tren->next = list2;
                list2=list2->next;
            }
            tren=tren->next;
        }
        while(list1 != nullptr){
            tren->next = list1;
            list1=list1->next;
            tren=tren->next;

        }
        while(list2 != nullptr){
            tren->next = list2;
            list2=list2->next;
            tren=tren->next;
        }
        return root;
    }
};
