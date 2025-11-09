class Solution {
public:
    int countOperations(int num1, int num2, int cnt=0) {
        if (num1==0 || num2==0) return cnt;
    //    if (num1<num2) return countOperations(num2, num1, cnt);
        auto [q, r]=div(num1, num2);
        return countOperations(num2, r, cnt+q);
    }
};