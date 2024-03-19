/**
 * @param {number[]} nums
 * @param {number} target
 * @return {number[]}
 */
var twoSum = function(nums, target) {
    var n=nums.length;
    const cache=new Map();
 
    const ans=[];
    for(let i=0;i<n;++i){
        
        if(cache.has(target-nums[i])){
            ans.push(cache.get(target-nums[i]));
            ans.push(i);
            return ans;
        }
       cache.set(nums[i],i);
    
    }

  return ans;
};