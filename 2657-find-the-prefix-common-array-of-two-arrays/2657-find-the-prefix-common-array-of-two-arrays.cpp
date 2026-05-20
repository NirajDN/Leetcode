class Solution {
public:
    vector<int> findThePrefixCommonArray(vector<int>& A, vector<int>& B) {
        uint64_t maskA = 0, maskB = 0;

        for (uint8_t i = 0; i < A.size(); i++) {
            maskA |= 1ULL << A[i];
            maskB |= 1ULL << B[i];
            B[i] = __builtin_popcountll(maskA & maskB);
        }

        return B;
    }
};