class Solution {
public:
    
    /*time and space complexity
    n===>size of cuts array
    time:(n^2)
    if there are cuts at every unit distance then the depth of recursion is at max n
    and the every time n calls are called so (n*n)
    
    space:(n^2) //because we are maintaining a matrix of nxn
    */
    
     //taking size 103 instead of 100 because i have added two element of my own in the cuts array
    int dp[103][103];
    
    Solution()
    {
        //initializing dp table with -1
        memset(dp,-1,sizeof(dp));
    }
    
    
    //do not forget to pass vect as reference(&) if you remove this
    //it will result into tle
    int solve(int start,int end,vector<int> &vect)
    {
        // printf("%d %d\n",start,end);
        //base case
        if(end-start == 1)
            return 0;
        //if already know the ans return it
        if(dp[start][end]!=-1)
            return dp[start][end];
        
        //calculating length of the stick
        //it is the stick between two cuts: the starting and the ending cut
        int len = vect[end]-vect[start];
        int ans = INT_MAX;
        
        //traversing all the cuts
        //it starts from just next to start
        //because we cannot cut the cuts smaller than  the starting index
        for(int i=start+1;i<end;i++)
        {
            // recursively solving for  
            //left part   +   right part
            int temp = solve(start,i,vect) + solve(i,end,vect);
            
            //maintaining the minimum after every call
            ans = min(ans,temp);
        }
        
       return dp[start][end] = len+ans;
    }
    
    
    int minCost(int n, vector<int>& cuts) {
        //sort the cuts
        sort(cuts.begin(),cuts.end());
        
        //creating new vector
        vector<int> vect;
        
        //pushing 0
        vect.push_back(0);
        //pushing the cuts vector
        for(int a:cuts)
        {
            vect.push_back(a);
        }
        //pushing n
        vect.push_back(n);
        
        
        return solve(0,vect.size()-1,vect);
        
        
        
    }
};