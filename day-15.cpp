//day-15
//Problem 1 - K-th element of two Arrays
//https://www.geeksforgeeks.org/problems/k-th-element-of-two-sorted-array1317/1?utm_source=youtube&utm_medium=collab_striver_ytdescription&utm_campaign=k-th-element-of-two-sorted-array
//code:
class Solution {
  public:
    int kthElement(vector<int>& a, vector<int>& b, int k) {
        int i = 0;
        int j = 0;
        vector<int> c;
        while(i < a.size() && j < b.size()){
            if(a[i] < b[j]){
                c.push_back(a[i++]);
            }
            else{
                c.push_back(b[j++]);
            }
        }
        while(i < a.size()){
            c.push_back(a[i++]);
        }
        while(j < b.size()){
            c.push_back(b[j++]);
        }
        return c[k-1];
    }

//Problem 2 - Search a 2D matrix
//https://leetcode.com/problems/search-a-2d-matrix/description/
//code:
class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int left = 0;
        int m = matrix.size();
        int n = matrix[0].size();
        int right = (m*n)-1;

        while(left <= right){
            int mid = (left+right)/2;
            int row = mid/n;
            int col = mid%n;
            if(matrix[row][col] == target){
                return true;
            }
            else if(matrix[rol][col] > target){
                right = mid-1;
            }
            else{
                left = mid+1;
            }
        }
        return false;
    }
};
//Problem 3 - Search a 2D matrix II 
//https://leetcode.com/problems/search-a-2d-matrix-ii/description/
//code:
class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int m = matrix.size();
        int n = matrix[0].size();
        int r = 0;
        int c = n-1;
        while(r < m && c >= 0){
            if(matrix[r][c] == target){
                return true;
            }
            else if(matrix[r][c] > target){
                c -=1;
            }
            else{
                r += 1;
            }
        }
        return false;
    }
};
