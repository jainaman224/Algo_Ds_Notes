const rabinKarp = (pat, str) => {
    let p = 31
    let m = 1000000007
    let S = pat.length
    let T = str.length

    let p_pow = [] // precomputing powers of p mod m 
    p_pow.push(1) // p^0 = 1
    for (let i = 1; i < Math.max(S, T); i++) {
        p_pow.push((p_pow[i - 1] * p) % m);
    }

    let h = [] // length-wise hash i.e h[i] = hash of the prefix with i characters
    h.push(0); // h[0] = 0   
    for (let i = 0; i < T; i++) {
        h.push((h[i] + (str[i].charCodeAt(0) - 97 + 1) * p_pow[i]) % m);
    }

    let h_s = 0; // hash value of the pattern
    for (let i = 0; i < S; i++)
        h_s = (h_s + (pat[i].charCodeAt(0) - 97 + 1) * p_pow[i]) % m;

    let occurs = []; // desired array storing the indices of given string where pattern occurs
    for (let i = 0; i + S - 1 < T; i++) {
        // slide a window of length S of the pattern
        let cur_h = (h[i + S] - h[i] + m) % m;
        // if current_hash matches with the hash of out pattern, then a match is found at this index
        if (cur_h == h_s * p_pow[i] % m)
            occurs.push(i);
    }

    return occurs;
}

// Calling the function
let str = "girlscriptsummerofcodewithgirlsandboys"
let pat = "girl"

let ids = rabinKarp(pat, str) // desired array storing the indices of given string where pattern occurs
console.log("Pattern found at indexes: ", ids)

// Output
// Pattern found at indexes:  [ 0, 26 ]
