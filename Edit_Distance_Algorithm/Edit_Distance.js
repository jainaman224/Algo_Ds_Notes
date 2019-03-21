

function Edit_Distance(first_str, second_str, m , n) {

    // If first string is empty, the only option is to insert all characters of second string into first 
    if( m == 0) 
        return n; 

    // If second string is empty, remove all characters of first string.
    if (n == 0) 
        return m; 

    // If last characters of two strings are same, nothing much to do.
    if( first_str[m-1] == second_str[n-1] )
        return Edit_Distance(first_str, second_str, m-1, n-1);

    // If last characters are not same, consider all three operations on last character of first string, recursively 
    // compute minimum cost for all three operations and take minimum of three values. 
    return 1 + Math.min(Edit_Distance(first_str, second_str, m, n-1),       // Insert 
            Edit_Distance(first_str, second_str, m-1, n),          // Remove 
            Edit_Distance(first_str, second_str, m-1, n-1)         // Replace 
            );

} 

// input strings
a = "kanchan"
b = "thareja"

console.log(Edit_Distance(a, b, a.length(), b.length())) 

// OUTPUT 
//   6

