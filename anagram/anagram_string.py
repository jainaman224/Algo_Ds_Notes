def check_anagram(s1, s2):
    if( sorted(s1) != sorted(s2) ): #sort both the strings and check if they are same
        print("It is not an anagram")
    else:
        print("It is an anagram")

String1 = input("Enter input string 1 = ")
String2 = input("Enter input string 2 = ")
check_anagram(String1,String2)
