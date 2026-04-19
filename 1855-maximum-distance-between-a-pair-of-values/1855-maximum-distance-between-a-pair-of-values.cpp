class Solution {
public:
    int maxDistance(vector<int>& A, vector<int>& B) {
        int i, j = 1;

        for (i = 0; i < A.size() && j < B.size(); j++)
            i += A[i] > B[j];

        return j - i - 1;
    }
};