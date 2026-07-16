class Solution {
public:
    int numOfSubarrays(vector<int>& arr, int k, int threshold) {
        int totalSum =0;
        int n = arr.size();
        int count=0;
        for(int i=0;i<k;i++){
            totalSum+=arr[i];
        }
        int avg = totalSum/k;
        if(avg >= threshold){
            count++;
        }
        for(int i=k;i<n;i++){
            totalSum=totalSum+arr[i]-arr[i-k];
            avg=totalSum/k;
            if(avg>=threshold){
                count++;
            }
        }
        return count;
    }
};