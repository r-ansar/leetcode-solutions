class Solution {
public:
    int characterReplacement(string s, int k) {
        int left=0;
        int freq[26]={0};
        int maxf=0;
        int result=0;
        for(int right=0;right<s.size();right++){
            freq[s[right]-'A']++;
            maxf=max(maxf,freq[s[right]-'A']);
            while((right-left+1)-maxf>k){
                freq[s[left]-'A']--;              //We donot calculate maxf each time because it will matter only when it increases
                left++;                           //because windowSize-maxf=k or so maxf+k=windowSize only when we get a higher 
            }                                     //maxf, result can be bigger
            result=max(result,right-left+1);
        }
        return result;
    }
};
