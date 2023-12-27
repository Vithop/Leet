/**
 * @param {string} s
 * @return {number}
 */
var calculate = function(s) {
    if (s == null || s.length === 0) return null;
    
    const rgx = /[*/+-]|\d+/g
    const rgx2 = /[*/+-]/g
    const stack = []
    let op = "+"
    const m = {
        "-": (x) => stack.push(-x),
        "+": (x) => stack.push(x),
        "*": (x) => stack.push( stack.pop() * x),
        "/": (x) => stack.push(Math.trunc( stack.pop() / x )),
    }

    let capture;
    while((capture = rgx.exec(s)) !== null){
        const t = capture[0]
        if (rgx2.test(t) ){
            op = t
        } else {
            m[op](Number(t))
        }
    }
   
    const sum = (acc, crnt) => acc + crnt
    return stack.reduce(sum)
};
