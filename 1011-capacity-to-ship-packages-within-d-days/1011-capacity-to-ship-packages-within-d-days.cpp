class Solution {
public:
    
    bool valid(vector<int>weights,int mid,int days){
        int n=weights.size();
        int count=1;
        int sum=0;
        for(int i=0;i<n;++i){
            if(weights[i]>mid){
                return false;
            }
            sum=sum+weights[i];
            if(sum>mid){
                count++;
                sum=weights[i];
            }
            
        }
        if(sum>mid){
            count++;
        }
       
        return count<=days;
    }
    int shipWithinDays(vector<int>& weights, int days) {
        int low=1;
        int high=1e9+1;
        
        //optimisation lower the range of answers !
        
        while(low<=high){
            int mid=low+(high-low)/2;
            
            if(valid(weights,mid,days)){
                high=mid-1;
            }
            else{
                low=mid+1;
            }
        }
        return low;
    }
};
//3
//2