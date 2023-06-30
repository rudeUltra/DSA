class Solution {
public:
    bool check(int i,int j,vector<vector<int>>&v,int r,int c)
    {   
        if(i<0 || i>=r || j<0 || j>=c || v[i][j]==1 || v[i][j]==2)
            return 0;
        if(i==r-1)
            return 1;
        v[i][j]=2;
        bool a=check(i+1,j,v,r,c);
        bool b=check(i,j+1,v,r,c);
        bool c1=check(i-1,j,v,r,c);
        bool d=check(i,j-1,v,r,c);
        return a||b||c1||d;
    }
    bool solve(vector<vector<int>>&v,vector<vector<int>>&w,int m)
    {
        for(int i=0;i<m;i++)
            v[w[i][0]-1][w[i][1]-1]=1;
        int r=v.size(),c=v[0].size();
        for(int i=0;i<c;i++)
        {   
            if(v[0][i]==0 && check(0,i,v,r,c))
                return 1;
        }
        return 0;
    }
    int latestDayToCross(int r, int c, vector<vector<int>>&w) {
        int n=w.size();
        int l=0,h=n-1;
        int ans=0;
        while(l<=h)
        {   
            vector<vector<int>>v(r,vector<int>(c,0));
            int m=(l+h)/2;
            if(solve(v,w,m))
            {
                ans=m;
                l=m+1;
            }
            else
                h=m-1;
        }
        return ans;
    }
};