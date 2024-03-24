/*

1095. Find in Mountain Array

(This problem is an interactive problem.)
You may recall that an array arr is a mountain array if and only if:
arr.length >= 3
There exists some i with 0 < i < arr.length - 1 such that:
arr[0] < arr[1] < ... < arr[i - 1] < arr[i]
arr[i] > arr[i + 1] > ... > arr[arr.length - 1]
Given a mountain array mountainArr, return the minimum index such that mountainArr.get(index) == target. If such an index does not exist, return -1.

You cannot access the mountain array directly. You may only access the array using a MountainArray interface:
MountainArray.get(k) returns the element of the array at index k (0-indexed).
MountainArray.length() returns the length of the array.
Submissions making more than 100 calls to MountainArray.get will be judged Wrong Answer. Also, any solutions that attempt to circumvent the judge will result in disqualification.

Example 1:
Input: array = [1,2,3,4,5,3,1], target = 3
Output: 2
Explanation: 3 exists in the array, at index=2 and index=5. Return the minimum index, which is 2.

Example 2:
Input: array = [0,1,2,4,2,1], target = 3
Output: -1
Explanation: 3 does not exist in the array, so we return -1.
 
Constraints:
3 <= mountain_arr.length() <= 104
0 <= target <= 109
0 <= mountain_arr.get(index) <= 109

https://leetcode.com/problems/find-in-mountain-array/
*/

/**
 * // This is the MountainArray's API interface.
 * // You should not implement it, or speculate about its implementation
 * class MountainArray {
 *   public:
 *     int get(int index);
 *     int length();
 * };
 */

class Solution {
public:
    int peakELe(MountainArray &mountainArr,vector<int> &dp){
        long long n = mountainArr.length();
        if(n==1)return 0;
        if(mountainArr.get(0)>mountainArr.get(1))return 0;
        if(mountainArr.get(n-1)>mountainArr.get(n-2))return n-1;

        long long low = 1;
        long long high = n-2;
        while(low<=high){
            long long mid = low +(high-low)/2;

            if(dp[mid] == -1)
                dp[mid] = mountainArr.get(mid);

            if(dp[mid-1] == -1)
                dp[mid-1] = mountainArr.get(mid-1);

            if(dp[mid+1] == -1)
                dp[mid+1] = mountainArr.get(mid+1);

            if(dp[mid]>dp[mid-1] && dp[mid]>dp[mid+1]){
                return mid;
            }
            else if(dp[mid]>dp[mid-1]){
                low = mid+1;
            }
            else{
                high = mid-1;
            }
        }
        return -1;
    }


    long long first_bs(MountainArray &mountainArr,long long high, long long target,vector<int> &dp){
        long long low = 0;
        while(low<=high){
            long long mid = low + (high-low)/2;

            if(dp[mid] == -1)
                dp[mid] = mountainArr.get(mid);

            if(dp[mid] == target){
                return mid;
            }
            else if(dp[mid] < target){
                low = mid+1;
            }
            else{
                high = mid-1;
            }

        }
        return -1;
    }


    long long last_bs(MountainArray &mountainArr,long long low, long long target,vector<int> &dp){
        long long high = mountainArr.length()-1;
        while(low<=high){
            long long mid = low + (high-low)/2;

            if(dp[mid] == -1)
                dp[mid] = mountainArr.get(mid);
            
            if(dp[mid] == target){
                return mid;
            }
            else if(dp[mid]<target){
                high = mid-1;
            }
            else{
                low = mid+1;
            }

        }
        return -1;
    }

    int findInMountainArray(long long target, MountainArray &mountainArr) {
        vector<int>dp(mountainArr.length(),-1);

        int PeakIdx = peakELe(mountainArr,dp);
        int idx = first_bs(mountainArr,PeakIdx,target,dp);
        if(idx == -1){
            int idx = last_bs(mountainArr,PeakIdx,target,dp);
            return idx;
        }
        return idx; 
    }
};