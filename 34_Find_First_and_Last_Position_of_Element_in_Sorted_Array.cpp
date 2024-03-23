/*

34. Find First and Last Position of Element in Sorted Array

Given an array of integers nums sorted in non-decreasing order, find the starting and ending position of a given target value.
If target is not found in the array, return [-1, -1].
You must write an algorithm with O(log n) runtime complexity.
 
Example 1:
Input: nums = [5,7,7,8,8,10], target = 8
Output: [3,4]

Example 2:
Input: nums = [5,7,7,8,8,10], target = 6
Output: [-1,-1]

Example 3:
Input: nums = [], target = 0
Output: [-1,-1]
 
Constraints:
0 <= nums.length <= 105
-109 <= nums[i] <= 109
nums is a non-decreasing array.
-109 <= target <= 109


https://leetcode.com/problems/find-first-and-last-position-of-element-in-sorted-array/
*/

class Solution {
public:

    int firstOccurence(vector<int>& arr, int n, int k){
        int low = 0;
        int high = n-1;
        int ans = -1;
        while(low<=high){
            int mid = low +(high-low)/2;

            if(arr[mid] == k ){
                ans = mid;
                high = mid-1;
            }
            else if(arr[mid]<k) low = mid+1;
            else high = mid-1;
        }
        return ans;
    }

    int lastOccurence(vector<int>& arr, int n, int k){
        int low = 0;
        int high = n-1;
        int ans = -1;
        while(low<=high){
            int mid = low +(high-low)/2;

            if(arr[mid] == k ){
                ans = mid;
                low = mid+1;
            }
            else if(arr[mid]<k) low = mid+1;
            else high = mid-1;
        }
        return ans;
    }

    vector<int> searchRange(vector<int>& nums, int target) {
        int n = nums.size();
        int first = firstOccurence(nums,n,target);
        if(first == -1)return {-1,-1};
        int last = lastOccurence(nums,n,target);
        return{first,last};   
    }
};