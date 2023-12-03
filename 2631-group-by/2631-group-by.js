/**
 * @param {Function} fn
 * @return {Object}
 */
Array.prototype.groupBy = function(fn) {
    const ans={};
    
    for(let val of this){
        const key=fn(val);
        
        if(ans[key]){
            ans[key].push(val)
        }
        else{
            ans[key]=[val];
        }
    }
    return ans;
};

/**
 * [1,2,3].groupBy(String) // {"1":[1],"2":[2],"3":[3]}
 */