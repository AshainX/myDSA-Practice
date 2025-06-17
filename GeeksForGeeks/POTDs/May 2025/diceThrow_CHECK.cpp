class Solution {
  public:
    int noOfWays(int m, int n, int x) {
        // code here
    vector<int> dp(x + 1, 0);
    dp[0] = 1;

    // Iterate through each dice (i) from 1 to n (number of dice)
    for (int i = 1; i <= n; i++) {

        // Iterate backwards through all possible sums (j) from x to 1
        // to ensure that the results from previous dice
        // counts are not overwritten
        for (int j = x; j >= 1; j--) {

            // Reset dp[j] before calculating its
          	// new value for the current dice
            dp[j] = 0;

            // Loop through all possible outcomes of the dice (k) 
          	// from 1 to m (faces of the dice)
            // If j - k is a valid sum (non-negative), update dp[j]
            for (int k = 1; k <= m && j - k >= 0; k++) {
                dp[j] += dp[j - k];
            }
        }

        // After each dice iteration, set dp[0] to 0 
      	// since there are no ways to achieve sum 0
        dp[0] = 0;
    }

    // Return the number of ways to get 
  	// sum x using n dice
    return dp[x];
}
    
};