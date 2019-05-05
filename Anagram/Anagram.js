function check_anagram (s1, s2) {
    let l1 = s1.length;
    let l2 = s2.length;

    // Check if length of both the strings are same
    if(l1 !== l2){
        console.log('Invalid Input');
        return
    }

    // sort the strings by splitting it to an array then apply the sort method and join the array
    let str1 = s1.split('').sort().join('');
    let str2 = s2.split('').sort().join('');

    // Check if both the strings are equal
    if(str1 === str2){
        console.log("It is an Anagrams");
    }
    else{
        console.log("It is not an Anagrams");
    }
}

check_anagram("debit card","bad credit")
