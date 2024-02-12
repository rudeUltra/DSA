class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int count=0;
        int majority_element=INT_MAX;
        int n=nums.size();
        
        for(int i=0;i<n;++i){
            //O(1) space NOice
            //Guarantee HM. Noice
            if(count==0){
                count=1;
                majority_element=nums[i];
            }
            else if(nums[i]==majority_element){
                count++;
            }
            else{
                count--;
            }
        }
        //Basically cancelling out logiC
        return majority_element;
    }
};