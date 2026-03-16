class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int left=0;
        int right=nums.size()-1;
        int start=-1;
        int end=-1;
        // First Finding start
        while(left<=right){
            int mid=(left+right)/2;
            if(nums[mid]==target){
                start=mid;
                right=mid-1;
            }
            if(nums[mid]>target){
                right=mid-1;
            }
            if(nums[mid]<target){
                left=mid+1;
            }
        }
        //Finding End
        left=0;
        right=nums.size()-1;
        while(left<=right){
            int mid=(left+right)/2;
            if(nums[mid]==target){
                end=mid;
                left=mid+1;
            }
            if(nums[mid]>target){
                right=mid-1;
            }
            if(nums[mid]<target){
                left=mid+1;
            }
        }
        return {start,end};
    }
};