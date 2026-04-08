// Statement

// You are given a string s consisting of the following characters: '(', ')', '{', '}', '[' and ']'.
// The input string s is valid if and only if:
// Every open bracket is closed by the same type of close bracket.
// Open brackets are closed in the correct order.
// Every close bracket has a corresponding open bracket of the same type.
// Return true if s is a valid string, and false otherwise.

class Solution {
public:
    bool isValid(string s) {
        unordered_map<char,char> m={{')','('},{']','['},{'}','{'}};
        stack<char> st;
        for(char c:s){
            if(m.find(c)==m.end()){
                st.push(c);
            }
            else{
                if(st.empty()||st.top()!=m[c]){
                    return false;
                }
                st.pop();
            }
        }
        return st.empty();
    }
};
