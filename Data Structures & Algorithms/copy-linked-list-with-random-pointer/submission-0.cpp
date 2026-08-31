/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head) {
        unordered_map<Node*,int> mp;       
        unordered_map<int,Node*> mp2;

        if(head == nullptr)
            return nullptr;
        
        Node* root = new Node(head->val);

        mp2[0] = root;
        mp[head] = 0;

        Node* tren = root;
        Node* headorg = head;
        head=head->next;
        int index = 1;
        while(head!= nullptr){
            tren->next = new Node(head->val);
            mp2[index]=tren->next;
            mp[head] = index;
            index++;
            tren=tren->next;
            head=head->next;
        }
        
        tren = root;
        head = headorg;
        while(head!=nullptr){
            if(head->random == nullptr){
                tren->random = nullptr;
            }else{
                int ind = mp[head->random];
                tren->random = mp2[ind];
            }
            tren=tren->next;
            head=head->next;
        }
        return root;
    }
};
