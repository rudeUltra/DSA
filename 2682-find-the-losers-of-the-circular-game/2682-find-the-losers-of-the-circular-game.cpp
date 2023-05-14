class Solution {
public:
    vector<int> circularGameLosers(int n, int k) {
        //lets just go with the brute force approach hm
        vector<int>nums(n,0);
        for(int i=0;i<n;++i){
            nums[i]=i+1;
        }
        vector<int>visited(n,0);
        vector<int>ans;
        int i=1;
        int idx=0;
        while(i){
            if(visited[idx]==1){
                break;
            }
            visited[idx]=1;
            idx=(idx+(i*k))%n;
            i++;
        }
        for(int i=0;i<n;++i){
            if(visited[i]==0){
                //not visited
                ans.push_back(nums[i]);
            }
        }
        return ans;
    }
};