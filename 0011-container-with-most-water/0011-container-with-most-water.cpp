class Solution {
public:
    int maxArea(vector<int>& height) {
                int n= height.size();
        int l=0;
        int r=n-1;
        int maxArea=0;
        int area=0;
        while(l<r){
            int width=r-l;
            int heights=min(height[r],height[l]);
            area=width*heights;
            maxArea=max(area,maxArea);
            if(height[l]<height[r]){
                l++;
            }
            else{
                r--;
            }
        }
       return maxArea;
    }
};