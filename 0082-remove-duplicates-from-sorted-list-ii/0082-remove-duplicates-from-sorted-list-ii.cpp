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

    ListNode* removeEle(ListNode* head, int x){
        if(head==nullptr) return head;
        bool willCurrBeDeleted=false;
        if(head->val==x) willCurrBeDeleted=true;
        if(head->next!=nullptr && head->val==head->next->val)
        willCurrBeDeleted=true;
        head->next=removeEle(head->next, head->val);
        return (willCurrBeDeleted) ? head->next:head;
    }
    ListNode* deleteDuplicates(ListNode* head) {
        return removeEle(head,-101);
    }
};