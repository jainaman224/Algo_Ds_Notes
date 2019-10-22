class Solution {
    public List<String> generateParenthesis(int n) {
        List<String> combinations = new ArrayList();
        generateAll(new char[2 * n], 0, combinations);
        return combinations;
    }

    public void generateAll(char[] current, int pos, List<String> result) {
        if (pos == current.length) {
            if (valid(current))
                result.add(new String(current));
        } else {
            current[pos] = '(';
            generateAll(current, pos+1, result);
            current[pos] = ')';
            generateAll(current, pos+1, result);
        }
    }

    public boolean valid(char[] current) {
        int balance = 0;
        for (char c: current) {
            if (c == '(') balance++;
            else balance--;
            if (balance < 0) return false;
        }
        return (balance == 0);
    }
}

def generateParenthesis(self, N):
    if N == 0: return ['']
    ans = []
    for c in xrange(N):
        for left in self.generateParenthesis(c):
            for right in self.generateParenthesis(N-1-c):
                ans.append('({}){}'.format(left, right))
    return ans
/*
input: n = 3
sample output:
[
  "((()))",
  "(()())",
  "(())()",
  "()(())",
  "()()()"
]
*/