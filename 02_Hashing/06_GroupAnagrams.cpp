// Statement

// Given an array of strings strs, group all anagrams together into sublists. You may return the output in any order.
// An anagram is a string that contains the exact same characters as another string, but the order of the characters can be different.

class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string>> m;
        vector<vector<string>> result;
        for(int i = 0; i < strs.size(); i++){
            int arr[26] = {0};
            for(char j : strs[i]){
                arr[j-'a']++;
            }
            string s = "";
            for(int k : arr){
                s+=to_string(k)+"#";
            }
            m[s].push_back(strs[i]);
        }
        for(auto r : m){
            result.push_back(r.second);
        }
        return result;
    }
};