// Statement

// Given an array of integers nums, return the length of the longest consecutive sequence of elements that can be formed.
// A consecutive sequence is a sequence of elements in which each element is exactly 1 greater than the previous element. The elements do not have to be consecutive in the original array.
// You must write an algorithm that runs in O(n) time.

class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        if(nums.size()==0){
            return 0;
        }
        set<int> s;
        int result=1;
        int temp=1;
        for(int i=0;i<nums.size();i++){
            s.insert(nums[i]);
        }
        int curr=*s.begin();
        for(auto it = next(s.begin()); it != s.end(); it++){
            if((curr+1)==*it){
                temp++;
                if(temp>result){
                    result=temp;
                }
            }
            else{  
                temp=1;
            }
            curr=*it;
        }
        return result;
    }
};


//Or

class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> s;
        for(int i = 0; i < nums.size(); i++){
            s.insert(nums[i]);
        }
        int longest = 0;
        for(auto x : s){
            // check if it's a starting point
            if(s.find(x - 1) == s.end()){
                int curr = x;
                int count = 1;

                // build sequence
                while(s.find(curr + 1) != s.end()){
                    curr++;
                    count++;
                }

                if(count > longest){
                    longest = count;
                }
            }
        }

        return longest;
    }
};
