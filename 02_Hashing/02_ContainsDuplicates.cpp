// Statement

// Given an integer array nums, return true if any value appears at least twice in the array, and return false if every element is distinct.

class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        unordered_set<int> set;
        for(int i=0;i<nums.size();i++){
            if(set.find(nums[i])!=set.end()){
                return true;
            }
            set.insert({nums[i]});
        }
        return false;
    }
};