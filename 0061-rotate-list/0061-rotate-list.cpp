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

 /*
 m sbse phle calculate kr rha hun ki 
 */
class Solution {
public:
    ListNode* rotateRight(ListNode* head, int k) {
        if(k==0){return head;}  //agr k=0 mtlb no rotation
       int size = fillq(head); //loop for getting size
       if(size==0 || size==1){return head;} //agr size 0 to kya rotate kroge
       while(k>=size){k=k-size;} //to reduce k
       if(k==0){return head;}

       rot(head,head,k);

       return head;
    }

    void rot(ListNode* &head,ListNode* &l,int k)
    {
       static int c=0;
       if(head!=nullptr)
       {
           rot(head->next,l,k);
           if(c<k){
           ListNode* t=new ListNode(head->val);
           t->next=l;
           l=t;   
           head=nullptr;c++;}
       }
       else{c=0;} //taki static c ka effect na aye
    }

    int fillq(ListNode* head)
    {   int count=0;
        while(head!=nullptr)
        {
            head=head->next;
            count++;
        }
        return count;
    }
};