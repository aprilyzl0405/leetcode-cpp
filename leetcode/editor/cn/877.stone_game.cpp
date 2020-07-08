//Alex and Lee play a game with piles of stones. There are an even number of pil
//es arranged in a row, and each pile has a positive integer number of stones pile
//s[i]. 
//
// The objective of the game is to end with the most stones. The total number of
// stones is odd, so there are no ties. 
//
// Alex and Lee take turns, with Alex starting first. Each turn, a player takes 
//the entire pile of stones from either the beginning or the end of the row. This 
//continues until there are no more piles left, at which point the person with the
// most stones wins. 
//
// Assuming Alex and Lee play optimally, return True if and only if Alex wins th
//e game. 
//
// 
//
// Example 1: 
//
// 
//Input: [5,3,4,5]
//Output: true
//Explanation: 
//Alex starts first, and can only take the first 5 or the last 5.
//Say he takes the first 5, so that the row becomes [3, 4, 5].
//If Lee takes 3, then the board is [4, 5], and Alex takes 5 to win with 10 poin
//ts.
//If Lee takes the last 5, then the board is [3, 4], and Alex takes 4 to win wit
//h 9 points.
//This demonstrated that taking the first 5 was a winning move for Alex, so we r
//eturn true.
// 
//
// 
//
// Note: 
//
// 
// 2 <= piles.length <= 500 
// piles.length is even. 
// 1 <= piles[i] <= 500 
// sum(piles) is odd. 
// Related Topics 极小化极大 数学 动态规划

#include "assert.h"
#include <iostream>
#include "vector"

using namespace std;

//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    struct Pair{
        int fir;
        int sec;
    };
    bool stoneGame(vector<int>& piles) {
        int n = piles.size();

        vector<vector<Pair>> dp(n, vector<Pair>(n));
        // base case
        for (int i = 0; i < n; i ++) {
            dp[i][i].fir = piles[i];
            dp[i][i].sec = 0;
        }

        for (int l = 1; l < n; l ++) {
            for (int i = 0; i < n - l; i ++) {
                int j = i + l;

                // fir
                int left = piles[i] + dp[i + 1][j].sec;
                int right = piles[j] + dp[i][j - 1].sec;

                // sec
                if (left > right) {
                    dp[i][j].fir = left;
                    dp[i][j].sec = dp[i + 1][j].fir;
                } else {
                    dp[i][j].fir = right;
                    dp[i][j].sec = dp[i][j - 1].fir;
                }
            }
        }

        return dp[0][n-1].fir > dp[0][n-1].sec;
    }
};
//leetcode submit region end(Prohibit modification and deletion)


int main()
{
    Solution solution;

    vector<int>nums1{5,3,4,5};
    assert(solution.stoneGame(nums1) == true);

    //solution.XXX
    return 0;
}