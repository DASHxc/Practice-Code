#include<vector>
#include<unordered_map>
#include<unordered_set>
#include<queue>
#include<string>
using namespace std;

//not space optimized solution
// int frogJump(int n, vector<int> &heights)
// {
//     if(n <= 1)
//         return 0; 
//     vector<int> dp(n,0);
//     dp[0] = 0;
//     dp[1] = abs(heights[1] - heights[0]);
//     for(int i=2;i<n;i++){
//         dp[i] = min((dp[i-1] + abs(heights[i] - heights[i-1])), (dp[i-2] + abs(heights[i] - heights[i-2])));
//     }
//     return dp[n-1];
// }


int frogJump(int n, vector<int> &heights)
{
    // Write your code here.
    if(n <= 1)
        return 0; 
    vector<int> dp(n,0);
    int a = 0;
    int b = abs(heights[1] - heights[0]);
    int ans;
    for(int i=2;i<n;i++){
        ans = min(b + abs(heights[i] - heights[i-1]), a + abs(heights[i] - heights[i-2]));
        a = b;
        b = ans;
    }
    return ans;
}

//simple start wiith a recursion solution. Gives TLE
// int util(int ind, vector<int>& ht){
//     if(ind == 0)
//         return 0;
//     int right = INT_MAX;
//     int left = util(ind-1,ht) + abs(ht[ind]-ht[ind-1]);
//     if(ind>1)
//         right = util(ind-2,ht) + abs(ht[ind] - ht[ind-2]);
//     return min(left,right);
// }
// int frogJump(int n, vector<int> &heights)
// {
//     return util(n-1,heights);
// }

//use memoization on recursion solution
// int util(int ind, vector<int>& ht,vector<int>& dp){
//     if(ind == 0)
//         return 0;
//     if(dp[ind] != -1)
//         return dp[ind];
//     int right = INT_MAX;
//     int left = util(ind-1,ht,dp) + abs(ht[ind]-ht[ind-1]);
//     if(ind>1)
//         right = util(ind-2,ht,dp) + abs(ht[ind] - ht[ind-2]);
//     return dp[ind] = min(left,right);
// }
// int frogJump(int n, vector<int> &heights)
// {
//     vector<int> dp(n,-1);
//     util(n-1,heights,dp);
//     return dp[n-1];
// }