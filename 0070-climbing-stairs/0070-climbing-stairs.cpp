/////////////// I Bow To Lord Krishna Ans Lord Hanuman ////////
class Solution {
public:
    int recurssion(int n, vector<int>& memo) {
        if (n == 1) return 1;
        if (n == 2) return 2;
        if (memo[n] != -1) return memo[n];
       
        return memo[n] =recurssion(n - 1, memo) + recurssion(n - 2, memo);
    }
    
    int climbStairs(int n) {
        vector<int> memo(n + 1, -1); 
        return recurssion(n, memo);
    }
};