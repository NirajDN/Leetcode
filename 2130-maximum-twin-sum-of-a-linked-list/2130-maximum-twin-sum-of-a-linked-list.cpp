class Solution {
public:
    int pairSum(ListNode* head) {
        int res = 0;
        ListNode* left = head;

        auto dfs = [&](this auto&& dfs, ListNode* right) -> void {
            if (right->next)
                dfs(right->next);

            res = max(res, left->val + right->val);
            left = left->next;
        };

        dfs(head);
        return res;
    }
};