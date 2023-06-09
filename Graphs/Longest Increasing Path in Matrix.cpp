#include<vector>
#include<unordered_map>
using namespace std;
class Solution {
public:
    int r[4] = {-1,0,1,0};
    int c[4] = {0,1,0,-1};
    bool isValid(int r,int c,int n,int m){
        if(r < 0 || c<0 || r>=n || c>=m)
            return false;
        return true;
    }
    int DFS(vector<vector<int>>& matrix,vector<vector<int>>& dp,int row,int col,int n,int m){
        if(!isValid(row,col,n,m))
            return 0;
        if(dp[row][col] != -1)
            return dp[row][col];
        int ans = 0;
        for(int i=0;i<4;i++){
            int nRow = row + r[i];
            int nCol = col + c[i];
            if(isValid(nRow,nCol,n,m) && matrix[row][col] < matrix[nRow][nCol])
                ans = max(ans, DFS(matrix,dp,nRow,nCol,n,m));
        }
        dp[row][col] = ans + 1;
        return ans+1;
    }
    int longestIncreasingPath(vector<vector<int>>& matrix) {
        int n = matrix.size();
        int m = matrix[0].size();
        vector<vector<int>> dp(n,vector<int>(m,-1));
        int maxCnt = 1;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(dp[i][j] == -1){
                    maxCnt = max(maxCnt,DFS(matrix,dp,i,j,n,m));
                }
            }
        }
        return maxCnt;
    }
};