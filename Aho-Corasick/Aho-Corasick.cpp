/*It is a kind of dictionary-matching algorithm that locates elements
of a finite set of strings (the "dictionary") within an input text.
It matches all strings simultaneously.*/

using namespace std; 
#include <bits/stdc++.h>

const int MAXSTATE = 6 * 50 + 10; 
// Max number of states in the matching machine.
// Should be equal to the sum of the length of all keywords.

const int MAXCHAR = 26; 
// Number of characters in the alphabet.
int out[MAXSTATE]; 
// Output for each state, as a bitwise mask.
int fail[MAXSTATE]; 
// failure function
int g[MAXSTATE][MAXCHAR]; 
// goto function, or -1 if fail.

int buildMachine(const vector<string> &words, char lowestChar = 'a', char highestChar = 'z')
{       
     memset(out, 0, sizeof out); //intializing out with 0s
     memset(fail, -1, sizeof fail);	//intializing fail with -1s
     memset(g, -1, sizeof g);	//intializing g with -1s
     int states = 1; // Initially, we just have the 0 state

     for (int i = 0; i < words.size(); i++)
     {               
          const string &keyword = words[i];
          int currentState = 0;
          for (int j = 0; j < keyword.size(); j++)
          {              
	       int c = keyword[j] - lowestChar;
               if (g[currentState][c] == -1)
               {     	
		    // Allocate a new node
            	    g[currentState][c] = states++;
		       
               }
               currentState = g[currentState][c];  
          }
          out[currentState] |= (1 << i); 
	  // There's a match of keywords[i] at node currentState.	
     }
     // State 0 should have an outgoing edge for all characters.
     for (int c = 0; c < MAXCHAR; c++)
     {    		
          if (g[0][c] == -1)
          {    				
               g[0][c] = 0;	
          }	
     }
     //building the failure function
     queue<int> q;	
     for (int c = 0; c <= highestChar - lowestChar; c++)
     {     
	  // Iterate over every possible input. All nodes s of depth 1 have fail[s] = 0
          if (g[0][c] != -1 && g[0][c] != 0)
          {       
               fail[g[0][c]] = 0;
               q.push(g[0][c]);	
          }
     }

     while (q.size())
     {                
	  int state = q.front();
          q.pop();
          for (int c = 0; c <= highestChar - lowestChar; c++)
          {    
               if (g[state][c] != -1)
               {      
		    int failure = fail[state];
		    int failure = fail[state];
                    while (g[failure][c] == -1)
                    {
                         failure = fail[failure];
                    }
                    failure = g[failure][c];
                    fail[g[state][c]] = failure;
                    out[g[state][c]] |= out[failure]; // Merge out values
                    q.push(g[state][c]);
               }
          }
     }
     return states;
}

int findNextState(int currentState, char nextInput, char lowestChar = 'a')
{    	
     int answer = currentState;
     int c = nextInput - lowestChar;
     while (g[answer][c] == -1)
     { 
          answer = fail[answer];
     }
     return g[answer][c];
}

int main()
{   	
     vector<string> keywords;
     cout<<"Enter the number of keywords you want to enter";
     int n;
     for (int i = 0; i < n; i++)
     {      
	  string temp;
	  cin >> temp;
	  keywords.push_back(temp);
     }	
     cout<<"Enter text";
     string text;
     cin>>text;
     buildMachine(keywords, 'a', 'z');
     int currentState = 0;
     for (int i = 0; i < text.size(); i++)
     {    
          currentState = findNextState(currentState, text[i], 'a');
          if (out[currentState] == 0)
	  {    
	       continue; // Nothing new, moving on to the next character.
	  }
          for (int j = 0; j < keywords.size(); j++)
          { 
               if (out[currentState] & (1 << j))
               { 
		    // Matched keywords[j]
                    cout << "Keyword " << keywords[j] << " appears from " << i - keywords[j].size() + 1 << " to " << i << endl;
               }
          }
     }
     return 0;
}

/*
Input 

keywords ={"he",she","hers",his"}
text = "ahishers"

Output

Keyword his appears from 1 to 3
Keyword he appears from 4 to 5
Keyword she appears from 3 to 5
Keyword hers appears from 4 to 7

*/
}
