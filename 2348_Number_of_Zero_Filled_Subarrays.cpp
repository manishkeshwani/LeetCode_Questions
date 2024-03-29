/*

2348. Number of Zero-Filled Subarrays
Given an integer array nums, return the number of subarrays filled with 0.
A subarray is a contiguous non-empty sequence of elements within an array.

Example 1:
Input: nums = [1,3,0,0,2,0,0,4]
Output: 6
Explanation: 
There are 4 occurrences of [0] as a subarray.
There are 2 occurrences of [0,0] as a subarray.
There is no occurrence of a subarray with a size more than 2 filled with 0. Therefore, we return 6.

Example 2:
Input: nums = [0,0,0,2,0,0]
Output: 9
Explanation:
There are 5 occurrences of [0] as a subarray.
There are 3 occurrences of [0,0] as a subarray.
There is 1 occurrence of [0,0,0] as a subarray.
There is no occurrence of a subarray with a size more than 3 filled with 0. Therefore, we return 9.


https://leetcode.com/problems/number-of-zero-filled-subarrays/
*/

class Solution {
public:
    long long zeroFilledSubarray(vector<int>& nums) {

        long long ans=0;
        int cnt=0;
        for(int i = 0 ; i<nums.size() ; i++){
            int val = nums[i];
            if(val == 0){
                cnt++;
                ans+=cnt;
            }
            else{
                cnt=0;
                continue;
            }
        }
        return ans;
        
    }
};