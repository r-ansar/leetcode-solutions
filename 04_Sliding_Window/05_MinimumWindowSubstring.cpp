// Statement

// Given two strings s and t, return the shortest substring of s such that every character in t, including duplicates, is present in the substring. If such a substring does not exist, return an empty string "".

// You may assume that the correct output is always unique.

class Solution {
public:
    string minWindow(string s, string t) {
        unordered_map<char, int> need;

        for (char c : t) {
            need[c]++;
        }

        int have = 0;
        int needCount = need.size();

        unordered_map<char, int> window;

        int left = 0;
        int minLen = INT_MAX;
        int start = 0;

        for (int right = 0; right < s.size(); right++) {
            char c = s[right];
            window[c]++;

            if (need.find(c) != need.end() && window[c] == need[c]) {
                have++;
            }

            while (have == needCount) {
                if (right - left + 1 < minLen) {
                    minLen = right - left + 1;
                    start = left;
                }

                char l = s[left];
                window[l]--;

                if (need.find(l) != need.end() && window[l] < need[l]) {
                    have--;
                }

                left++;
            }
        }

        if (minLen == INT_MAX) return "";
        return s.substr(start, minLen);
    }
};

// Or

class Solution {
public:
    string minWindow(string s, string t) {
        if(s.size()<t.size()){
            return "";
        }
        unordered_map<char,int> m;
        unordered_map<char,int> m2;
        int withComp=0 , toComp=0;
        int left=0;
        int result=s.size()-1;
        int resleft=1,resright=0;
        string res="";
        for(char c:t){
            m[c]++;
        }
        withComp=m.size();
        for(int right=0;right<s.size();right++){
            if(m.find(s[right])!=m.end()){
                m2[s[right]]++;
                if(m2[s[right]]==m[s[right]]){
                    toComp++;
                }
                if(toComp==withComp){
                    while(toComp==withComp){
                        if(m2.find(s[left])!=m2.end()){
                            m2[s[left]]--;
                            if(m2[s[left]]<m[s[left]]){
                                toComp--;
                            }
                        }
                        left++;
                    }
                    if(right-(left-1)<=result){
                        result=right-(left-1);
                        resleft=left-1;
                        resright=right;
                    }
                }
            }
        }
        for(int i=resleft;i<=resright;i++){
            res+=s[i];
        }
        return res;
    }
};
