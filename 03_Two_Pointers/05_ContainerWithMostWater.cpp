// Statement

// You are given an integer array heights where heights[i] represents the height of the ith bar.
// You may choose any two bars to form a container. Return the maximum amount of water a container can store.

class Solution {
public:
    int maxArea(vector<int>& heights) {
        int curr;
        int m=0;
        int left=0;
        int right=heights.size()-1;
        while(left<right){
            int width = right - left;
            int h = min(heights[left], heights[right]);
            int curr = h * width;
            m = max(m, curr);
            if(heights[left] < heights[right]){
                left++;
            }
            else{
                right--;
            }
        }
        return m;
    }
};
