// Statement

// Given an integer array nums, find the subarray with the largest sum, and return its sum.

class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int n=nums.size();
        int curr=0;
        int m=nums[0];
        for(int i=0;i<n;i++){
            if(curr<0){
                curr=0;
            }
            curr+=nums[i];
            m=max(curr,m);
        }
        return m;
    }
};

class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int maxSoFar = nums[0];
        int maxEndingHere = nums[0];

        for(int i = 1; i < nums.size(); i++) {
            maxEndingHere = max(nums[i], maxEndingHere + nums[i]);
            maxSoFar = max(maxSoFar, maxEndingHere);
        }

        return maxSoFar;
    }
};