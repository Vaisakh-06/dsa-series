//Day - 17

//Problem 1 - Isomorphic strings
//https://leetcode.com/problems/isomorphic-strings/description/
//code:
class Solution {
public:
    bool isIsomorphic(string s, string t) {
        unordered_map<char,char> s_to_t, t_to_s;
        
        for(int i = 0; i < s.size(); i++){
            char c1 = s[i];
            char c2 = t[i];

            if((s_to_t.count(c1) && s_to_t[c1] != c2)||
                 (t_to_s.count(c2) && t_to_s[c2] != c1)){
                    return false;
            }

            s_to_t[c1] = c2;
            t_to_s[c2] = c1;
        }

        return true;
    }
};

//TC = O(N)
//SC = O(1)
//Approach: We use two hash maps to track the mapping of characters between the two strings. As we iterate through both strings simultaneously, we maintain s_to_t to map characters from s to t and t_to_s to map characters from t to s. For each character pair (c1, c2) from s and t, we first check if c1 already exists in s_to_t and maps to a different character than c2, or if c2 exists in t_to_s and maps to a different character than c1. If either condition is met, we return false as the mapping is inconsistent. Otherwise, we establish a mapping from c1 to c2 in s_to_t and from c2 to c1 in t_to_s. If we complete the iteration without any conflicts, we return true, indicating that the two strings are isomorphic.

//Problem 2 - Remove outermost paranthesis
//https://leetcode.com/problems/remove-outermost-parentheses/description/
//code:
class Solution {
public:
    string removeOuterParentheses(string s){
        stack<char> st;
        string ans = "";
        for(char ch : s){
            if(ch == '('){
                if(!st.empty()) ans += ch;
                st.push(ch);
            }
            else if(ch == ')'){
                st.pop();
                if(!st.empty()) ans += ch;
            }
        }
        return ans;
        }
};
//TC = O(N)
//SC = O(N)
//Approach: To solve this problem we use a character stack and then we also initialise a string "ans" to empty string. Then we traverse the string using a character iterator then we check if the current ch is an opening bracket and if it is we check if stack is empty, if the stack is empty this means its the first opening bracket in the primitive decomposition and this is what we are trying to remove so we avoid adding it to ans but we do push it and if stack is not empty we add it to the stack and the ans as well. after this we continue checking the rest of the characters if we encounter a closing bracket we pop and then check if stack is empty if it is then we skip adding it to ans as it is the closing of the first opening bracket otherwise we go ahead and add it to the ans 
