/**
 * @param {Function} fn
 * @return {Function}
 */
function memoize(fn) {
    const cache={};
    
    return function(...args) {
       
        let key=JSON.stringify(args);
        if(key in cache){
            return cache[key];
        }
        let ans=fn(...args);
        cache[key]=ans;
        
        return cache[key];
    }
}


/** 
 * let callCount = 0;
 * const memoizedFn = memoize(function (a, b) {
 *	 callCount += 1;
 *   return a + b;
 * })
 * memoizedFn(2, 3) // 5
 * memoizedFn(2, 3) // 5
 * console.log(callCount) // 1 
 */