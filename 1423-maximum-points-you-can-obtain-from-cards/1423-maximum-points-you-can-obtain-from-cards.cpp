class Solution {
public:
    int maxScore(vector<int>& cardPoints, int k) {
        int n=cardPoints.size();
        int sum=0;
        int l=0;
        int r=n-k;
        for(int i=r;i<n;++i){
            sum=sum+cardPoints[i];
        }
        int ans=sum;
        
        while(r<n){
            sum=sum+(cardPoints[l])-cardPoints[r];
            ans=max(ans,sum);
            l++;
            r++;
        }
        return ans;
    }
};