//Day - 18
//Problem 1 - Valid Anagram
//https://leetcode.com/problems/valid-anagram/
//code:

class Solution {
public:
    bool isAnagram(string s, string t){
        if(s.length() != t.length()) return false;

        unordered_map<char,int> s_to_t, t_to_s;

        for(int i = 0; i < s.length(); i++){
            char c1 = s[i];
            char c2 = t[i];

            if(s_to_t.count(c1)){
                s_to_t[c1]++;
            }
            else{
                s_to_t[c1] = 1;
            }

            if(t_to_s.count(c2)){
                t_to_s[c2]++;
            }
            else{
                t_to_s[c2] = 1;
            }
        }
        if(s_to_t == t_to_s){
            return true;
        }
        else{
            return false;
        }
        
    }
};
//Approach: to check if the strings are anagram we have two conditions 1. The size of strings should be same 2. the frequency of each character in the two strings must be same using this logic we cna use two unordered maps and map each character and its frequency and then check if the two unordered maps are same if they are this means they are anagram otherwise they arent.

//Problem 2
//https://leetcode.com/problems/longest-common-prefix/
//code:
class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        string prefix = strs[0];

        for(int i = 0; i < strs.size();i++){
            while(strs[i].find(prefix) != 0){

                prefix = prefix.substr(0,prefix.length()-1);
                if(prefix.empty()) return "";
            }
        }
        return prefix;
    }
};
//Approach: to find the longest common prefix we start by assumming the first string present in array of strings to be the longestprefix then we travers the whole array of strings starting from the 1st position since 0 is assumed to be the longest and then we use a while loop and check if the current string starts with the substring "prefix" if it does the function will return 0 and then the while loop ends otherwise we trim down the "prefix" string 1 letter at a time from the end by using substr function and then again check the while condition and if it doesnt meet the while condition it keeps on trimming till "prefix" becomes empty in this case there is no common prefix so we return "" otherwise we find out the longest common prefix.
  
