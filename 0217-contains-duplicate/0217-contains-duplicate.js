/**
 * @param {number[]} nums
 * @return {boolean}
 */
var containsDuplicate = function(nums) {
    var n=nums.length;
    
    const mp=new Map();
    
    for(let i=0;i<n;++i){
        if(mp.has(nums[i])){
            return true;
        }
        mp.set(nums[i],1);
    }
    return false;
};