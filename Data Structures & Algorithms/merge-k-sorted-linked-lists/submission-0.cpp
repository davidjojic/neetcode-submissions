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
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        priority_queue<pair<int,ListNode*>,vector<pair<int,ListNode*>>,greater<pair<int,ListNode*>>>pq;
        for(int i =0 ;i<lists.size();i++){
            if(lists[i] != nullptr){
                pq.push({lists[i]->val,lists[i]});
            }
        }
        ListNode* root = nullptr;
        ListNode* temp = root;
        while(!pq.empty()){
            auto [val,list] = pq.top();
            pq.pop();
            if(temp == nullptr){
                temp = new ListNode(val);
                root = temp;
            }else{
                temp -> next = new ListNode(val);
                temp = temp->next;
            }
            if(list->next != nullptr){
                pq.push({list->next->val,list->next});
            }
        }
        return root;
    }
};
