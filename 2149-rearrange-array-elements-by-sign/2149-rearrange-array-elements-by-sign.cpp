class Solution {
public:
    vector<int> rearrangeArray(vector<int>& nums) {
        //even positions positive number
        //Odd positions Negative number noice
        int n=nums.size();
        vector<int>ans(n,0);
        
        int pos=0;
        int neg=0;
        
        for(int i=0;i<n;++i){
            if(i%2==0){
                //get a positive number
                while(pos<n && (nums[pos]<0 || nums[pos]==INT_MAX)){
                    pos++;
                }
                ans[i]=nums[pos];
                nums[pos]=INT_MAX;
                pos++;
            }
            else{
                while(neg<n && (nums[neg]>0 || nums[neg]==INT_MAX)){
                    neg++;
                }
                ans[i]=nums[neg];
                nums[neg]=INT_MAX; //mark visited
                neg++;
            }
        }
        return ans;
        
    }
};