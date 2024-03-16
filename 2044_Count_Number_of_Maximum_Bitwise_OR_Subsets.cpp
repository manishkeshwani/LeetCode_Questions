/*

2044. Count Number of Maximum Bitwise-OR Subsets
Given an integer array nums, find the maximum possible bitwise OR of a subset of nums and return the number of different non-empty subsets with the maximum bitwise OR.
An array a is a subset of an array b if a can be obtained from b by deleting some (possibly zero) elements of b. Two subsets are considered different if the indices of the elements chosen are different.
The bitwise OR of an array a is equal to a[0] OR a[1] OR ... OR a[a.length - 1] (0-indexed).

Example 1:
Input: nums = [3,1]
Output: 2
Explanation: The maximum possible bitwise OR of a subset is 3. There are 2 subsets with a bitwise OR of 3:
- [3]
- [3,1]

Example 2:
Input: nums = [2,2,2]
Output: 7
Explanation: All non-empty subsets of [2,2,2] have a bitwise OR of 2. There are 23 - 1 = 7 total subsets.


https://leetcode.com/problems/count-number-of-maximum-bitwise-or-subsets/
*/

class Solution {

    private:
    int backtrack(vector<int>& nums,int idx,int n,int xr,int max_xr){
        if(idx>=n){
            if(xr==max_xr)
                return 1;
            else return 0;
        }

        int l = backtrack(nums,idx+1,n,xr|nums[idx],max_xr);
        int r = backtrack(nums,idx+1,n,xr,max_xr);

        return l+r;
    }
public:
    int countMaxOrSubsets(vector<int>& nums) {
        int xr = 0 ;
        int max_xr = INT_MIN;
        int n = nums.size();
        for(int i = 0 ;i<n; i++){
            xr |= nums[i];
            max_xr = max(xr,max_xr);
        }

        return backtrack(nums,0,n,0,max_xr);        
    }
};