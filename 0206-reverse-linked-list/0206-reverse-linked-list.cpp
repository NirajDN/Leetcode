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
    ListNode* reverseList(ListNode* head) {
        ListNode* temp=head;
        ListNode* past=nullptr;
        ListNode* future;

        while(temp!=nullptr){
            future=temp->next;
            temp->next=past;
            past=temp;
            temp=future;
        }
        head=past;
        return head;
        
    }
};