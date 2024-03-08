/**
 * @param {Function} fn
 * @return {Function}
 */
var once = function(fn) {
    var called=0;
    return function(...args){
        //already have the fn noice
        if(called===0){
            called++;
            return fn(...args);
        }
        return undefined;
    }
};

/**
 * let fn = (a,b,c) => (a + b + c)
 * let onceFn = once(fn)
 *
 * onceFn(1,2,3); // 6
 * onceFn(2,3,6); // returns undefined without calling fn
 */