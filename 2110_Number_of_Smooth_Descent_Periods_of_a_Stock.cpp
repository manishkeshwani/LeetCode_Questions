/*
2110. Number of Smooth Descent Periods of a Stock
You are given an integer array prices representing the daily price history of a stock, where prices[i] is the stock price on the ith day.
A smooth descent period of a stock consists of one or more contiguous days such that the price on each day is lower than the price on the preceding day by exactly 1. The first day of the period is exempted from this rule.
Return the number of smooth descent periods.

Example 1:
Input: prices = [3,2,1,4]
Output: 7
Explanation: There are 7 smooth descent periods:
[3], [2], [1], [4], [3,2], [2,1], and [3,2,1]
Note that a period with one day is a smooth descent period by the definition.

Example 2:
Input: prices = [8,6,7,7]
Output: 4
Explanation: There are 4 smooth descent periods: [8], [6], [7], and [7]
Note that [8,6] is not a smooth descent period as 8 - 6 ≠ 1.


https://leetcode.com/problems/number-of-smooth-descent-periods-of-a-stock/
*/


class Solution {

public:
    long long getDescentPeriods(vector<int>& prices) {

        long long key = 1;
        long long val = 0;
        long long n = prices.size();
        long long ans = 0;

        for(long long i=1 ; i<n ; i++){
            long long d = prices[i-1]-prices[i];
            if(d != key){
                val = 0;
            }
            else{
                val++;
            } 
            if(val>=1)ans+=val;
        }
        //adding individual elements
        return ans+n;
        
    }
};