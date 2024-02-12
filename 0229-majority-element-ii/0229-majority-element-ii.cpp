class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        int el1=1e9+1;
        int el2=1e9+1;
        int count1=0;
        int count2=0;
        
        int n=nums.size();
        
        for(int i=0;i<n;++i){
            if(count1==0 && nums[i]!=el2){
                //Hm
                el1=nums[i];
                count1=1;
            }
            else if(count2==0 && nums[i]!=el1){
                el2=nums[i];
                count2=1;
            }
            else if(nums[i]==el1){
                count1++;
            }
            else if(nums[i]==el2){
                count2++;
            }
            else{
                count1--;
                count2--; //hm
            }
        }
        cout<<count1<<" "<<count2;
        //check now hm
        vector<int>ans;
        int count=0;
        for(int i=0;i<n;++i){
            if(nums[i]==el1){
                count++;
            }
        }
        if(count>n/3){
            ans.push_back(el1);
        }
        count=0;
        for(int i=0;i<n;++i){
            if(nums[i]==el2){
                count++;
            }
        }
        if(count>n/3){
            ans.push_back(el2);
        }
        return ans;
    }
};