// Statement

// Given a string s, return true if it is a palindrome, otherwise return false.
// A palindrome is a string that reads the same forward and backward. It is also case-insensitive and ignores all non-alphanumeric characters.
// Note: Alphanumeric characters consist of letters (A-Z, a-z) and numbers (0-9).

class Solution {
public:
    bool isPalindrome(string s) {
        for(int i=0;i<s.size();i++){
            if(!isalnum(s[i])){
                s.erase(i,1);
                i--;
            }
            else{
                s[i] = tolower(s[i]);
            }
        }
        int left=0;
        int right=s.size()-1;
        while(left<right){
            if(s[left]!=s[right]){
                return false;
            }
            left++;
            right--;
        }
        return true;
    }
};

//Or

class Solution {
public:
    bool isPalindrome(string s) {
        int left = 0;
        int right = s.size() - 1;

        while(left < right){
            // skip non-alphanumeric
            while(left < right && !isalnum(s[left])) left++;
            while(left < right && !isalnum(s[right])) right--;

            // compare lowercase
            if(tolower(s[left]) != tolower(s[right])){
                return false;
            }

            left++;
            right--;
        }

        return true;
    }
};
