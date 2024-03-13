/*

977. Squares of a Sorted Array
Given an integer array nums sorted in non-decreasing order, return an array of the squares of each number sorted in non-decreasing order.

Example 1:

Input: nums = [-4,-1,0,3,10]
Output: [0,1,9,16,100]
Explanation: After squaring, the array becomes [16,1,0,9,100].
After sorting, it becomes [0,1,9,16,100].

https://leetcode.com/problems/squares-of-a-sorted-array/
*/

class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {
        int n = nums.size();
        vector<int>res(n);
        
        int left = 0;
        int right = n-1;
        int idx = right;
        while(left<=right){
            if(abs(nums[left]) >= abs(nums[right])){
                res[idx--]=nums[left] * nums[left];
                left++;
            }
            else{
                res[idx--]=nums[right] * nums[right];
                right--;
            }
        }

        return res;      
    }
};