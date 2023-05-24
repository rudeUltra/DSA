class Solution {
public:
    long long maxScore(vector<int>& nums1, vector<int>& nums2, int k) {
        vector<pair<int,int>>a;
        
        int n=nums1.size();
        
        
        //sorting is based on the first element like heap xD
        for(int i=0;i<n;++i){
            a.push_back({nums2[i],nums1[i]});
        }
        
        //sort on descending order plox
        sort(a.begin(),a.end(),greater<pair<int,int>>()); //sort in descending order
        
        long long sum=0;
        long long ans=-1;
        
        priority_queue<int,vector<int>,greater<int>>pq;
        
        for(int i=0;i<k;++i){
            sum=sum+a[i].second;
            pq.push(a[i].second);
        }
        
        ans=sum*a[k-1].first;
        
        for(int i=k;i<n;++i){
            int temp=pq.top();
            pq.pop();
            
            sum=sum+a[i].second-(temp); //trying to maximize sum by removing the min element hm smoort
            pq.push(a[i].second); //for future purposes wink wink
            
            long long temp1=sum*a[i].first;
            if(ans<temp1){
                ans=temp1;
            }
        }
        
        return ans;
    }
};