/**
 *   Rabin Karp algorithm
 * ---------------------------------
 * This is a pattern matching algorithm. It has O(n + m) in best 
 * and average case and O(n * m) in worst case.
 * 
 */

// Importing required libraries
import 'dart:io';

// Function to search for the pattern in the text
void search(String pattern, String text, int prime){
    // Initializations
    const int d = 256;
    int m = pattern.length;
    int n = text.length;
    int p = 0, t = 0, h = 1;
    // Hash value calculation for pattern
    for(int i = 0; i < m - 1; i ++){
        h = (h * d) % prime;
    }
    // Hash value calculation for first substring in the text
    for(int i = 0; i < m; i ++){
        p = (d * p + pattern.codeUnitAt(i)) % prime;
        t = (d * t + text.codeUnitAt(i)) % prime;
    }

    int j;
    // Checking for matches in the text
    for(int i = 0; i <= n - m; i ++){
        if(p == t){
            for(j = 0; j < m; j ++){
                if(text.codeUnitAt(i + j) != pattern.codeUnitAt(j)){
                    break;
                }
            }
            // Match found
            if(j == m){
                print("The pattern iS found at index ${i}");
            }
        }
        if(i < n - m){
            t = (d * (t - text.codeUnitAt(i) * h) + text.codeUnitAt(i + m)) % prime;
            if(t < 0){
                t = (t + prime);
            }
        }
    }
}
// Driver method of the program
void main(){
    // Input of the pattern
    print("Enter pattern:");
    var input = stdin.readLineSync();
    String pattern = input;
    // Input of the text
    print("Enter text:");
    input = stdin.readLineSync();
    String text = input;
    // Chosen prime number
    int q = 101;
    // Calling search on pattern and text
    search(pattern,text,q);
}
/**
 *   Sample Input and Output
 * ---------------------------------
 * Enter pattern:
 * GIRL
 * Enter text:
 * GIRLSCRIPT
 * The pattern is found at index 0
 */
