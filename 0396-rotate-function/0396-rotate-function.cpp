class Solution {
public:
    int maxRotateFunction(vector<int>& A) {
        int sum = 0, F = 0;
        int n = A.size();

        for (int i = 0; i < n; i++) {
            sum += A[i];
            F += i * A[i];
        }

        int maxi = F;

        for (int i = 1; i < n; i++) {
            F += sum - n * A[n - i];
            maxi = max(maxi, F);
        }

        return maxi;
    }
};