class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> map;
        for(int i=0;i<nums.size();i++){
            int toFind=target-nums[i];
            if(map.find(toFind) != map.end()) {
                return {map[toFind],i};
            } 
            else {
                map[nums[i]]=i;
            }
        }
        return {};
    }
};