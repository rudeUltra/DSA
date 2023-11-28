/**
 * @param {number[]} nums
 * @param {Function} fn
 * @param {number} init
 * @return {number}
 */
var reduce = function(nums, fn, init) {
    var prev=init;
    
    nums.forEach(function(number){
        prev=fn(prev,number);
        
    });
    
    return prev;
};