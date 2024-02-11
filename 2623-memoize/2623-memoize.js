/**
 * @param {Function} fn
 * @return {Function}
 */
function memoize(fn) {
    const cache={}; //objeCT NOice
    
    return function(...args) {
        let key=JSON.stringify(args);
        
        if(key in cache){
            return cache[key]; //MeMoization boi
        }
        //Json is the string version of an Object NOice hm.
        //.json converts JSON into an object hM.
        
        let temp=fn(...args);
        cache[key]=temp;
        
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