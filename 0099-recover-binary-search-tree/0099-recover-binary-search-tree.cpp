/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
int cnt=0;
void validBST(TreeNode*root,TreeNode* &prev,TreeNode* &first,TreeNode* &second,TreeNode* &third,TreeNode* &fourth){
    
        if(root==NULL){
            return;
        }
        validBST(root->left,prev,first,second,third,fourth);
        if(prev!=NULL&&prev->val>=root->val){
            cnt++;
            if(first==NULL){
                first=prev;
                second=root;
            }
            else{
                third=prev;
                fourth=root;
            }
        }
        prev=root;
        validBST(root->right,prev,first,second,third,fourth);
    }
    void recoverTree(TreeNode* root) {
        TreeNode* prev=NULL;
        TreeNode* first=NULL;
        TreeNode* second=NULL;
        TreeNode* third=NULL;
        TreeNode* fourth=NULL;
        validBST(root,prev,first,second, third,fourth);
        if(cnt==1){
            swap(first->val,second->val);
        }

        if(cnt==2){
            swap(first->val,fourth->val);
        }
    }
};