class Solution {
public:
    int maxArea(vector<int>& heights) {
        int n = heights.size();
        int l = 0;
        int r = n-1;
        int maxArea = 0;
        while(l<r){
            int height = min(heights[l], heights[r]);
            int width = r - l;
            maxArea = max(maxArea, height * width);
            if(heights[l] < heights[r]){
                l++;
            }else if(heights[r] < heights[l]){
                r--;
            }else{
              
                    if(heights[l+1] > heights[r-1]){
                        l++;
                    }
                    r--;
               
            }
        }
        return maxArea;
    }
};
