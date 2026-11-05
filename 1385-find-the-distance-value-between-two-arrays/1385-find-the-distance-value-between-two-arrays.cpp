class Solution {
public:
    int findTheDistanceValue(vector<int>& arr1, vector<int>& arr2, int d) {
        auto far = [&](int a) {  
            return ranges::all_of(arr2, [&](int b) { return abs(a - b) > d; });
        };
        return ranges::count_if(arr1, far);
    }
};