class Solution {
public:
    TreeNode* createBinaryTree(vector<vector<int>>& A) {
        unordered_map<int, TreeNode*> nodes;
        nodes.reserve(A.size() + 1);
        int root = 0;

        for (auto& d : A) {
            int x = d[0], y = d[1], isLeft = d[2];
            if (!nodes.contains(x)) {
                nodes[x] = new TreeNode(x);
                root ^= x;
            }
            if (!nodes.contains(y)) {
                nodes[y] = new TreeNode(y);
                root ^= y;
            }

            if (isLeft)
                nodes[x]->left = nodes[y];
            else
                nodes[x]->right = nodes[y];
            root ^= y;
        }

        return nodes[root];
    }
};