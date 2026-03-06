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