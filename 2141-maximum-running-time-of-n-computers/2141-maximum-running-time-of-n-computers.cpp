class Solution {
public:
    bool isPossible(int n,vector<int>&batteries,long long mid)
    {
        //here average is taken such that the battery time greater than time is added as equal to time. So that it does not contribute to average.
        long long time=0;
        for(int i=0;i<batteries.size();++i)
        {
            if(batteries[i]<mid)
            {
                time+=batteries[i];
            }
            else
            {
                time+=mid;
            }
        }
        return ((time/n)>=mid);
    }
    long long maxRunTime(int n, vector<int>& batteries) {
        long long l=1;
        long long h=1e14;
        long long ans=0;
        while(l<=h)
        {
            long long mid=l+((h-l)>>1);
            if(isPossible(n,batteries,mid))
            {
                ans=mid;
                l=mid+1;
            }
            else
            {
                h=mid-1;
            }
        }
        return ans;
    }
};