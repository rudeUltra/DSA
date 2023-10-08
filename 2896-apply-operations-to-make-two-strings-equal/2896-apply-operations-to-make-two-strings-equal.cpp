class Solution {
public:
    
int dp[501][501];
int n,x;
vector<int> a;
int solve(int i,int cnt){
    if(i==a.size()){
        if(cnt==0){
            return 0;
        }
        return 1e9;
    }

    if(dp[i][cnt]!=-1){
        return dp[i][cnt];
    }

    int ans=1e9;
    // if distance between adjacent pos is less than x then only consider this
    if(i+1<a.size()){
        ans=min(ans,solve(i+2,cnt)+min(x,a[i+1]-a[i]));
    }

    // pairint the position which we left unpaired lastime
    // as explained below
    if(cnt>0){
        ans=min(ans,solve(i+1,cnt-1));
    }


    // there can be a case where we want to pair it up with some postion 
    //with cost x like in eg pair up (0,8 ) with cost x
    //and currently we are saying that we are leavig it unpair and pair it 
    //sometime later
    ans=min(ans,x+solve(i+1,cnt+1));

    return dp[i][cnt]= ans;

}

    int minOperations(string s, string t, int X) {
        memset(dp,-1,sizeof(dp));
        n=s.size();
        x=X;
        a.clear();
        for(int i=0;i<n;i++){
            if(s[i]!=t[i]){
                a.push_back(i);
            }
        }
        
        if(a.size()%2){
            return -1;
        }
        int ans= solve(0,0);
        return ans>=1e9?-1: ans;
        
    }
};