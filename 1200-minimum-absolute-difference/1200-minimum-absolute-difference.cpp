class Solution {
public:
    vector<vector<int>> minimumAbsDifference(vector<int>& arr) {
        int n=arr.size();
        sort(arr.begin(),arr.end());
        int diff=0;
        if(n<2) return {};
        int mindiff=arr[1]-arr[0];

        for(int i=0;i<n-1;i++){
            diff=arr[i+1]-arr[i];
            mindiff=min(diff,mindiff);
        }
        vector<vector<int>> arr1;
        for(int i=0;i<n-1;i++){
            if(arr[i+1]-arr[i]==mindiff){
                arr1.push_back({arr[i],arr[i+1]});
            }
        }
        return arr1;
        
    }
};