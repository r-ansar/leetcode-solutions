// Statement

// You are given an array of distinct integers nums and a target integer target. Your task is to return a list of all unique combinations of nums where the chosen numbers sum to target.
// The same number may be chosen from nums an unlimited number of times. Two combinations are the same if the frequency of each of the chosen numbers is the same, otherwise they are different.
// You may return the combinations in any order and the order of the numbers in each combination can be in any order.

class Solution {
public:
    set<vector<int>> s;
    void helper(vector<int>& nums,int target,int index,vector<int>& combi,vector<vector<int>>& ans){
        if(index==nums.size()) return;
        if(target<0) return;
        if(target==0){
            if(s.find(combi)==s.end()){
                ans.push_back(combi);
                s.insert(combi);
            }
            return;
        }
        combi.push_back(nums[index]);
        helper(nums,target-nums[index],index+1,combi,ans);
        helper(nums,target-nums[index],index,combi,ans);
        combi.pop_back();
        helper(nums,target,index+1,combi,ans);
    }
    vector<vector<int>> combinationSum(vector<int>& nums, int target) {
        vector<int> combi;
        vector<vector<int>> ans;
        helper(nums,target,0,combi,ans);
        return ans;
    }
};
