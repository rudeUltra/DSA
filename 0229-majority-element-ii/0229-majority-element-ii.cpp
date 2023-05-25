class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        int n=nums.size();
        int count1=0;
        int count2=0;
        int e1=-1;
        int e2=-1; //candidates 
        for(int i=0;i<n;++i){
            if(nums[i]==e1){
                count1++;
            }
            else if(nums[i]==e2){
                count2++;
            }
            else if(count1==0){
                e1=nums[i];
                count1=1;
            }
            else if(count2==0){
                e2=nums[i];
                count2=1; //new candidate has to taken
            }
            else{
                count1--;
                count2--; //cancelling
            }
        }
        //checking if the candidates are correct or not
        count1=0;
        count2=0;
        vector<int>ans;
        for(int i=0;i<n;++i){
            if(nums[i]==e1){
                count1++;
            }
            else if(nums[i]==e2){
                count2++;
            }
        }
        if(count1>n/3){
            ans.push_back(e1);
        }
        if(count2>n/3){
            ans.push_back(e2);
        }
        return ans;
    }
};