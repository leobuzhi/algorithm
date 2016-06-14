/*
Write a function that takes a string as input and reverse only the vowels of a string.
Example 1:
Given s = "hello", return "holle".
Example 2:
Given s = "leetcode", return "leotcede".
*/

//my Solution
class Solution {
public:
    string reverseVowels(string s) {
        stack<char> sc;
        for(char x:s)
            if(x=='a'||x=='e'||x=='i'||x=='o'||x=='u'
             ||x=='A'||x=='E'||x=='I'||x=='O'||x=='U')
                sc.push(x);
        for(int i=0;i!=s.length();i++)
        {
            if(s[i]=='a'||s[i]=='e'||s[i]=='i'||s[i]=='o'||s[i]=='u'
             ||s[i]=='A'||s[i]=='E'||s[i]=='I'||s[i]=='O'||s[i]=='U')
            {
                s[i]=sc.top();
                sc.pop();
            }
        }
        return s;
    }
};


//other Solution
class Solution {
public:
    string reverseVowels(string s) {
        int dict[256] = {0};
        dict['a'] = 1, dict['A'] = 1;
        dict['e'] = 1, dict['E'] = 1;
        dict['i'] = 1, dict['I'] = 1;
        dict['o'] = 1, dict['O'] = 1;
        dict['u'] = 1, dict['U'] = 1;
        int start = 0, end = (int)s.size() - 1;
        while(start < end){
            while(start < end && dict[s[start]] == 0) start++;
            while(start < end && dict[s[end]] == 0) end--;
            swap(s[start],s[end]);
            start++;end--;
        }
        return s;
    }
};
