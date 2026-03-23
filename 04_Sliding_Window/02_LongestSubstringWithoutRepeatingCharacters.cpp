// Statement

// Given a string s, find the length of the longest substring without duplicate characters.
// A substring is a contiguous sequence of characters within a string.


// Not the best one but mine
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        if(s.size()==0){
            return 0;
        }
        unordered_set<char> container;
        int longest=0;
        int current=0;
        int l=0;
        for(char c:s){
            if(container.find(c)==container.end()){
                container.insert(c);
                current=container.size();
                longest=max(current,longest);
            }
            else{
                while(s[l]!=c){
                    container.erase(s[l]);
                    l++;
                }
                l++;
                current=container.size();
                longest=max(current,longest);
            }
        }
        return longest;
    }
};

//Or

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_set<char> st;   // stores current window characters
        int l = 0, res = 0;       // left pointer and result

        for(int r = 0; r < s.size(); r++) {  // r = right pointer
            // shrink window until no duplicate
            while(st.count(s[r])) {   
                st.erase(s[l]);
                l++;
            }

            st.insert(s[r]);              // insert current character
            res = max(res, r - l + 1);    // update max length
        }

        return res;
    }
};
