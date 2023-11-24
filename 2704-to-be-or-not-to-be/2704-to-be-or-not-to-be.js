/**
 * @param {string} val
 * @return {Object}
 */
// var expect = function(val) {
//     let current = val;

//     return {
//         toBe(val) {
//             if(current === val) {
//                 return true
//             } else {
//                 throw new Error('Not Equal')
//             }
//         },

//         notToBe(val) {
//             if(current !== val) {
//                 return true
//             } else {
//                 throw new Error('Equal')
//             }
//         }
//     }
// };

var expect = function(val) {
    let current = val;

    return {
        toBe: function(val) {
            if (current === val) {
                return true;
            } else {
                throw new Error('Not Equal');
            }
        },

        notToBe: function(val) {
            if (current !== val) {
                return true;
            } else {
                throw new Error('Equal');
            }
        }
    };
};


/**
 * expect(5).toBe(5); // true
 * expect(5).notToBe(5); // throws "Equal"
 */