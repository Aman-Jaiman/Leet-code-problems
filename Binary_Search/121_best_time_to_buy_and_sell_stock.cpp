/*
LeetCode 121. Best Time to Buy and Sell Stock

You are given an array prices where prices[i] is the price of a given stock on the i-th day.

You want to maximize your profit by choosing a single day to buy one stock 
and choosing a different day in the future to sell that stock.

Return the maximum profit you can achieve from this transaction. 
If you cannot achieve any profit, return 0.

Example 1:
Input: prices = [7,1,5,3,6,4]
Output: 5
Explanation: Buy on day 2 (price = 1) and sell on day 5 (price = 6), profit = 6-1 = 5.

Example 2:
Input: prices = [7,6,4,3,1]
Output: 0
Explanation: In this case, no transactions are done and the max profit = 0.

Constraints:
- 1 <= prices.length <= 10^5
- 0 <= prices[i] <= 10^4
*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int minPrice = prices[0];  // minimum price seen so far
        int profit = 0;            // maximum profit
        
        for(int i = 0; i < prices.size(); i++) {
            if(prices[i] < minPrice) {
                minPrice = prices[i];  // update buying point
            }
            profit = max(profit, prices[i] - minPrice); // check profit
        }
        return profit;
    }
};

// Driver code (for testing in VS Code)
int main() {
    Solution sol;
    vector<int> prices = {7,1,5,3,6,4};
    cout << "Max Profit: " << sol.maxProfit(prices) << endl;
    return 0;
}
