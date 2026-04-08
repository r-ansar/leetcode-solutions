// Statement

// Given an integer array nums and an integer k, return true if there are two distinct indices i and j in the array such that nums[i] == nums[j] and abs(i - j) <= k.

class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        unordered_set<int> set;
        for(int i=0;i<nums.size();i++){
            if(set.find(nums[i])!=set.end()){
                return true;
            }
            set.insert(nums[i]);
            if(set.size()>k){
                set.erase(nums[i-k]);
            }
        }
        return false;
    }
};