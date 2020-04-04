/*Given a 10*10 grid(character array) with '+' or '-' as its cell values.
Also, a word list is given that needs to be placed accurately in the grid.
Cells marked with '-' are to be filled with word list*/

#include<iostream>
using namespace std;
char crossWord[10][10];

bool isValidHorizontal(int row, int col, string word)
{

    if(10 - col < word.length())
		return false;

    for (int i = 0, j = col; i < word.length(); ++i, j++)
	{
		if (crossWord[row][j] != '-' && crossWord[row][j] != word[i])
		{
			return false;
		}
	}

	return true;
}

bool isValidVertical(int row, int col, string word)
{

	if(10 - row < word.length())
		return false;

	for (int i = row, j = 0; j < word.length(); ++i, j++)
	{
		if (crossWord[i][col] != '-' && crossWord[i][col] != word[j])
		{
            return false;
		}
	}

	return true;
}

void setHorizontal(int row, int col, string word, bool state[])
{

	for (int i = 0, j = col; i < word.size(); ++i, j++)
	{
		if (crossWord[row][j] != '+')
		{

			if(crossWord[row][j] == word[i])
				state[i] = false;
			else
				state[i] = true;
			crossWord[row][j] = word[i];
		}

	}
}

void setVertical(int row, int col, string word, bool state[])
{

	for (int i = 0, j = row; i < word.size(); ++i, j++)
	{
		if (crossWord[j][col] != '+')
		{
			if(crossWord[j][col] == word[i])
				state[i] = false;
			else
				state[i] = true;
			crossWord[j][col] = word[i];
		}

	}
}

void resetHorizontal(int row, int col, bool state[], int size)
{

	for (int i = 0, j = col; i < size; ++i, j++)
	{
		if(state[i] == true)
			crossWord[row][j] = '-';
	}
	return;
}

void resetVertical(int row, int col, bool state[], int size)
{

	for (int i = 0, j = row; i < size; ++i, j++)
	{
		if(state[i] == true)
			crossWord[j][col] = '-';
	}
	return;
}

void set_value(bool helper[], int len )
{

	for(int i = 0; i < len; i++)
	{
		helper[i] = false;
	}
}


bool crossWordHelper(string input[], int size, int index)
{

	if(index == size){
		for(int i = 0; i < 10; i++)
		{
			for(int j = 0; j < 10; j++)
			{
				cout << crossWord[i][j] ;
			}
			cout << endl;
		}
		return true;
	}

	for(int i = 0; i < 10; i++)
	{
		for(int j = 0; j < 10; j++)
		{

			if(crossWord[i][j] == '-' || crossWord[i][j] == input[index][0])
			{
				int length = input[index].size();
				bool state[length];
				set_value(state, length);

				if(isValidHorizontal(i, j, input[index]))
				{
					setHorizontal(i, j, input[index], state);
					if(crossWordHelper(input, size, index+1))
					{
						return true;
					}
					resetHorizontal(i, j, state, length);
				}

				if(isValidVertical(i, j, input[index]))
				{
					setVertical(i, j, input[index], state);
					if(crossWordHelper(input, size, index+1))
					{
						return true;
					}
					resetVertical(i, j, state, length);
				}

			}
		}
	}
	return false;
}

void solveCrossWord(string input[], int size)
{
	bool res = crossWordHelper(input, size, 0);
	return;
}

int main()
{
	string ss;
	for(int i = 0; i < 10; i++)
	{
		cin >> ss;
		for(int j = 0; j < ss.size(); j++)
		{
			crossWord[i][j] =  ss[j];
		}
	}

	char s[200];
	cin >> s;

	string input[10];
	char ch;
	string word = "";
	int a = 0;

	for (int i = 0; s[i] != '\0'; ++i)
	{
		if(s[i] == ';')
		{
			input[a++] = word;
			word = "";
		}
		else
		{
			word += s[i];
		}
	}
	input[a++] = word;
	solveCrossWord(input, a);

    return 0;
}

/*Sample Input :
+-++++++++
+-++++++++
+-------++
+-++++++++
+-++++++++
+------+++
+-+++-++++
+++++-++++
+++++-++++
++++++++++
AGRA;NORWAY;ENGLAND;GWALIOR

Output:
+E++++++++
+N++++++++
+GWALIOR++
+L++++++++
+A++++++++
+NORWAY+++
+D+++G++++
+++++R++++
+++++A++++
++++++++++
*/
