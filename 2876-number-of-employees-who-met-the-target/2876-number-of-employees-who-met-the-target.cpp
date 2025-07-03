class Solution {
public:
    int numberOfEmployeesWhoMetTarget(vector<int>& hours, int target) {
        int count=0;
        for(int num : hours){
            count+=(num>=target);
        }
        return count;
    }
};