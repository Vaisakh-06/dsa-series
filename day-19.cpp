//Day - 19
//Problem 1 - Maximum nesting depth of the parenthesis
//https://leetcode.com/problems/maximum-nesting-depth-of-the-parentheses/description/
//code:
class Solution {
public:
    int maxDepth(string s) {
        int i = 0;
        int count = 0;
        int greatestcount = 0;
        while(s[i] != '\0'){
            if(s[i] == '('){
                count++;
                greatestcount = max(greatestcount,count);
            }
            else if(s[i] == ')'){
                count--;
            }
            i++;
        }
        return greatestcount;      
    }
};

//TC = O(N)
//SC = O(1)
//Approach: To find max depth of parenthesis we initialise count and greatestcount to 0 and then we traverse the string till the last ch and we check if we encounter an '(' if we do then count is incremented by 1 and maxcount is also updated and if we encounter a closing bracket we decrement count by 1 and at the end the greatestcount is returned

//Problem 2 - Roman to Integer
//https://leetcode.com/problems/roman-to-integer/
//code:
class Solution {
public:
    int romanToInt(string s) {
        unordered_map<char,int> romantoint;
        romantoint['I'] = 1;
        romantoint['V'] = 5;
        romantoint['X'] = 10;
        romantoint['L'] = 50;
        romantoint['C'] = 100;
        romantoint['D'] = 500;
        romantoint['M'] = 1000;
        int sum = 0;
        int i = 0;
        while(i < s.size())
            if((s[i] == 'I' && s[i+1] == 'V' ) || (s[i] == 'I' && s[i+1] == 'X')){
                sum += romantoint[s[i+1]]-1;
                i+=2;
            }
            else if((s[i] == 'X' && s[i+1] == 'L' )|| (s[i] == 'X' && s[i+1] == 'C')){
                sum += romantoint[s[i+1]]-10;
                i+=2;
            }
            else if((s[i] == 'C' && s[i+1] == 'D' )|| (s[i] == 'C' && s[i+1] == 'M')){
                sum += romantoint[s[i+1]]-100;
                i+=2;
            }
            else{
                sum += romantoint[s[i]];
                i++;
            }
            return sum;
    }
};
//TC = O(N)
//SC = (1)
//Approach: we make an unordered which maps each roman to its integer value and then we traverse the string and check for the subtraction conditions mentioned in problem statement and if the conditions are not met the int value is directly added to sum and pointer is incremented by 1 else if condition is met we process two ch at a time and add result of their to sum so we increment pointer by 2 and at the end the sum is returned
