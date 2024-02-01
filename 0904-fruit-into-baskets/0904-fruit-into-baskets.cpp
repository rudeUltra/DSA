class Solution {
public:
    int totalFruit(vector<int>& fruits) {
        unordered_map<int,int> mp; // initializing a unordered_map
        int maxcount = 0; // Global max
        int count = 0;   // local max
        int j = 0,i = 0;
        for(;i<fruits.size();i++){
            mp[fruits[i]]++; // adding fruit into bucket 
            // count =i-j;
            while(mp.size()>2){  //Checking for number of fruits not greater than 2
                mp[fruits[j]]--;  // removing fruit 
                if(mp[fruits[j]] == 0){
                    mp.erase(fruits[j]);
                }
                j++;
            }
            count =i-j+1;
            maxcount = max(maxcount,count);
        }
        count =i-j;
        return  max(maxcount,count);
    }
};