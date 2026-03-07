class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {    //Bucket Sort
        int n=nums.size();
        unordered_map<int,int> m;
        vector<vector<int>> bucket(n+1);
        int count=0;
        vector<int> result;
        for(int i=0;i<nums.size();i++){
            m[nums[i]]++;
        }
        for(auto x : m){
            bucket[x.second].push_back(x.first);
        }

        for(int i=n;i>=0&&count<k;i--){
            for(auto b:bucket[i]){
                result.push_back(b);
                count++;
            }
        }
        return result;
    }
};

//Or

class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {    // Simple Sort
        unordered_map<int,int> m;
        for(int n : nums)
            m[n]++;
        vector<pair<int,int>> v(m.begin(), m.end());
        sort(v.begin(), v.end(), [](auto a, auto b){
            return a.second > b.second;
        });
        vector<int> ans;
        for(int i = 0; i < k; i++)
            ans.push_back(v[i].first);

        return ans;
    }
};