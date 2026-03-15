// Statement

// Given an integer array nums, find a subarray that has the largest product, and return the product.
// The test cases are generated so that the answer will fit in a 32-bit integer.
// Note that the product of an array with a single element is the value of that element.

class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int n=nums.size();
        int maxP=nums[0];
        int minP=nums[0];
        int result=nums[0];
        for(int i=1;i<n;i++){
            if(nums[i]<0){
                int temp=maxP;
                maxP=minP;
                minP=temp;
            }
            maxP=max(nums[i],maxP*nums[i]);
            minP=min(nums[i],minP*nums[i]);
            result=max(result,maxP);
        }   
        return result;
    }
};