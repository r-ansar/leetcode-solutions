// Statement

// Given two strings s and t, return true if t is an anagram of s, and false otherwise.

class Solution {
public:
    bool isAnagram(string s, string t) {
        if(s.size() != t.size()) return false;

        unordered_map<char,int> m;
        for(int i=0;i<s.size();i++){
            m[s[i]]++;
        }
        for(int i=0;i<t.size();i++){
            if(m.find(t[i]) == m.end()){
                return false;
            }
            m[t[i]]--;
            if(m[t[i]] == 0){
                m.erase(t[i]);
            }
        }
        return m.empty();
    }
};

// Another Approach

class Solution {
public:
    bool isAnagram(string s, string t) {

        if(s.size() != t.size()) return false;

        int count[26] = {0};

        for(int i = 0; i < s.size(); i++){
            count[s[i] - 'a']++;
            count[t[i] - 'a']--;
        }

        for(int i = 0; i < 26; i++){
            if(count[i] != 0) return false;
        }

        return true;
    }
};