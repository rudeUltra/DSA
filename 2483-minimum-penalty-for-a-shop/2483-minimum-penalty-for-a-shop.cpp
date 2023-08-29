class Solution {
public:
    int bestClosingTime(string customers) {
        int sum=0;
        int n=customers.size();
        int ans=0;
        int idx=0;
        for(int i=0;i<n;++i){
            if(customers[i]=='Y'){
                sum++;
            }
            else{
                sum--;
            }
            if(sum>ans){
                ans=sum;
                idx=i+1;
            }
        }
        
//         if(sum==ans){
//             idx=n;
//         }
        
        return idx;
    }
};