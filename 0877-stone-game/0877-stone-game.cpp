class Solution {
public:
    
    // Alex's turn adds piles and Lee's turn deducts piles
    // Game result = max piles count of Alex - max piles count of Lee
    // dp vector tracks the game result in range l to h
    int dp[501][501]={};
    
    int takeStone(bool alex, int l, int h, vector<int>& piles)
    {
        // base cases
        if(l>h) return 0;
      
        
        // return precalculated result
        if(dp[l][h]!=-1) return dp[l][h];
        
        // alex's turn, alex can take either piles[l] or piles[h] so we add them with the recursion call as
        // piles[l]+takeStone(l+1,h) or piles[h]+takeStone(l,h-1) and get the max value betweeen them 
        // for getting the game result as alex always tries to maximize his pile count
        if(alex)    
            dp[l][h] = max(piles[l]+takeStone(!alex,l+1,h,piles),piles[h]+takeStone(!alex,l,h-1,piles));
        
        // lee's turn, choice for lee is same as alex, only differece is that lee wants to maximize his
        // game result by minimizing alex's result and so we return the min value between those two choices
        // also to get game result we deduct piles[l] or piles[h] with recursion calls
        else
            dp[l][h] = min(takeStone(!alex,l+1,h,piles),takeStone(!alex,l,h-1,piles));

        return dp[l][h];
    }
    
    bool stoneGame(vector<int>& piles) {
        
        int n = piles.size();
        memset(dp,-1,sizeof(dp));
        
        // alex turn = true, lee turn = false
        // Game result = max piles count of Alex - max piles count of Lee
        // If result > 0 then Alex wins
        int score=takeStone(true,0,n-1,piles);
        cout<<score;
        int sum=0;
        for(int i=0;i<n;++i){
            sum+=piles[i];
        }
        
        if(score>sum/2){
            return true;
        }
        
        return false;
    }
};