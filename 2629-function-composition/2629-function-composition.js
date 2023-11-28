/**
 * @param {Function[]} functions
 * @return {Function}
 */
var compose = function (functions) {
  return function (x) {
    let init = x;
    let res = 0;
    for (let i = functions.length - 1; i >= 0; i--) {
      let cl = functions[i];
      if(i === functions.length - 1){
        res = cl(init);
      }else{
        res = cl(res);
      }

    }
    return functions.length ? res  : init;
  };
};

/**
 * const fn = compose([x => x + 1, x => 2 * x])
 * fn(4) // 9
 */