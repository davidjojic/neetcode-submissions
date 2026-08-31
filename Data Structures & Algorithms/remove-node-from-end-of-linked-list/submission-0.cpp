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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        int velicina = 0;
        ListNode* tren = head;
        while(tren != nullptr){
            velicina++;
            tren=tren->next;
        }
        int izbaciti=velicina-n;
        tren = head;
        if(izbaciti == 0){
            head=head->next;
            return head;
        }
        izbaciti--;
        while(izbaciti--){
            tren=tren->next;
        }
        tren->next = tren->next->next;
        return head;
    }
};
