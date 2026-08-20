/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    bool hasCycle(ListNode *head) {
        ListNode*a=head;// step size -> 1
        ListNode*b=head;// step size -> 2
        while(a!=nullptr&&b!=nullptr&&b->next!=nullptr){
            a=a->next;
            b=b->next->next;
            if(a==b){
                return true;
            }
        }
        return false;
        
    }
};