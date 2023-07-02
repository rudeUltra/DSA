class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        int left=0;
        int n=numbers.size();
        int right=n-1;
        vector<int> temp;
        while(left<right){
            if(numbers[left]+numbers[right]==target){
                temp.push_back(left+1);
                temp.push_back(right+1);
                return temp;
            }
            else if(numbers[left]+numbers[right]>target){
                right=right-1;
            }
            else{
                left=left+1;
            }
        }
        return temp;
    }
};