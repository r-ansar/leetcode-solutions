// Statement

// Given an array of integers nums and an integer target, return indices of the two numbers such that they add up to target.
// You may assume that each input would have exactly one solution, and you may not use the same element twice.
// You can return the answer in any order.

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