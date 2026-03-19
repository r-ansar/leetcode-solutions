// Statement

// Design an algorithm to encode a list of strings to a string. The encoded string is then sent over the network and is decoded back to the original list of strings.

class Solution {
public:

    string encode(vector<string>& strs) {
        string encoded="";
        for(auto a:strs){
            encoded=encoded+a+((char)257);
        }
        return encoded;
    }

    vector<string> decode(string s) {
        vector<string> decoded;
        string v="";
        for(char a:s){
            if(a!=((char)257)){
                v=v+a;
            }
            else{
                decoded.push_back(v);
                v="";
            }
        }
        return decoded;
    }
};

//Or

class Solution {
public:

    // Encode a vector of strings to a single string
    string encode(vector<string>& strs) {
        string encoded = "";

        for(int i = 0; i < strs.size(); i++){
            int len = strs[i].size();

            // Convert length to string manually (without using to_string)
            string lenStr = "";
            while(len > 0){
                char c = (len % 10) + '0'; // Get last digit and convert to char
                lenStr = c + lenStr;       // Prepend digit to build length string
                len /= 10;                 // Remove last digit
            }
            if(lenStr == "") lenStr = "0"; // Handle empty string (length 0)

            // Append length + '#' + actual string
            encoded += lenStr + '#' + strs[i];
        }

        return encoded;
    }

    // Decode a single string to a vector of strings
    vector<string> decode(string s) {
        vector<string> decoded;
        int i = 0;

        while(i < s.size()){
            int len = 0;

            // Read length manually until '#' character
            while(s[i] != '#'){
                len = len * 10 + (s[i] - '0'); // Convert char digit to int and accumulate
                i++;
            }

            i++; // Skip '#' character

            // Read the next 'len' characters as the actual string
            string word = "";
            for(int j = 0; j < len; j++){
                word += s[i];
                i++;
            }

            decoded.push_back(word); // Add to result vector
        }

        return decoded;
    }
};

//Or

class Solution {
public:

    string encode(vector<string>& strs) {
        string encoded = "";
        for(int i = 0; i < strs.size(); i++){
            encoded += to_string(strs[i].size()) + '#' + strs[i];
        }
        return encoded;
    }

    vector<string> decode(string s) {
        vector<string> decoded;
        int i = 0;

        while(i < s.size()){
            int j = i;

            // find '#'
            while(s[j] != '#'){
                j++;
            }

            int len = stoi(s.substr(i, j - i)); // length
            string word = s.substr(j + 1, len);

            decoded.push_back(word);

            i = j + 1 + len; // move to next
        }

        return decoded;
    }
};
