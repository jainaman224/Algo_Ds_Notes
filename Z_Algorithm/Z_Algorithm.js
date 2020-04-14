/*
Z algorithm is a linear time string matching algorithm which runs in complexity.
It is used to find all occurrence of a pattern in a string , which is common
string searching problem.
*/

const setZArray = combined => {

    // Initiate zArray and fill it with zeros.
    const zArray = Array.from({ length: combined.length }, () => 0);

    // Z box boundaries.
    let leftIndex = 0, rightIndex = 0, shift = 0;

    // Go through all characters of the zString.
    for (let i = 1; i < combined.length; i += 1) {

        if (i > rightIndex) {

            leftIndex = i;
            rightIndex = i;

            while (
                rightIndex < combined.length
                && combined[rightIndex - leftIndex] === combined[rightIndex]
            ) {

                // Expanding Z box right boundary.
                rightIndex += 1;
            }


            zArray[i] = rightIndex - leftIndex;
            rightIndex -= 1;

        }

        else {

            // Calculate corresponding Z box shift.
            shift = i - leftIndex;

            // Check if the value that has been already calculated before
            if (zArray[shift] < (rightIndex - i) + 1) {

                zArray[i] = zArray[shift];
            }
            else {

                // shift left boundary of Z box to current position.
                leftIndex = i;

                // And start comparing characters one by one as we normally do for the case
                while (
                    rightIndex < combined.length
                    && combined[rightIndex - leftIndex] === combined[rightIndex]
                ) {
                    rightIndex += 1;
                }

                zArray[i] = rightIndex - leftIndex;

                rightIndex -= 1;
            }
        }
    }

    // Return generated zArray.
    return zArray;
}


zAlgorithm = (text, word) => {

    const wordPositions = [];

    // Concatenate word and text. Word will be a prefix to a text.
    const zString = `${word}$${text}`;

    // Generate Z-array for concatenated string.
    const zArray = setZArray(zString);

    for (let i = 1; i < zArray.length; i += 1) {
        if (zArray[i] === word.length) {

            const wordPosition = i - word.length - 1;
            wordPositions.push(wordPosition);
        }
    }

    // Return the list of word positions.
    return wordPositions;
}


// I/O and O/P Examples:

// The postions are: [0,10,16]
console.log(zAlgorithm("omgawesomeomgsftomg", "omg"));

// The positions are: [3,12]
console.log(zAlgorithm("ohelloworldello", "llo"));
