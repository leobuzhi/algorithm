/*
Given a pattern and a string str, find if str follows the same pattern.
Here follow means a full match, such that there is a bijection between a letter in pattern and a non-empty word in str.
Examples:
pattern = "abba", str = "dog cat cat dog" should return true.
pattern = "abba", str = "dog cat cat fish" should return false.
pattern = "aaaa", str = "dog cat cat dog" should return false.
pattern = "abba", str = "dog dog dog dog" should return false.
Notes:
You may assume pattern contains only lowercase letters, and str contains lowercase letters separated by a single space.
*/

//my Solution
class Solution {
public:
    bool wordPattern(string pattern, string str) {
        if (pattern == "" || str == "")
            return false;
        vector<string> vs;
        for (int i = 0, j = 0; i != str.length(); i++)
        {
            if (str[i] == ' ')
            {
                vs.push_back(str.substr(j, i - j));
                j = i + 1;
            }
            if (i == str.length() - 1)
            {
                vs.push_back(str.substr(j, i - j + 1));
            }
        }
        if (pattern.length() != vs.size())
            return false;
        unordered_map<string, string>  umcs1;
        unordered_map<string, string>  umcs2;
        for (int i = 0; i != pattern.length(); i++)
        {
            string s = pattern.substr(i, 1);
            if (umcs1[s] == ""&&umcs2[vs[i]] == "")
            {
                umcs1[s] = vs[i];
                umcs2[vs[i]] = s;
            }
            else{
                if (umcs1[s] != vs[i])
                    return false;
            }
        }
        return true;
    }
};


//better Solution
class Solution {
public:
    bool wordPattern(string pattern, string str) {
        map<char, int> p2i;
        map<string, int> w2i;
        istringstream in(str);
        int i = 0, n = pattern.size();
        for (string word; in >> word; ++i) {
            if (i == n || p2i[pattern[i]] != w2i[word])
                return false;
            p2i[pattern[i]] = w2i[word] = i + 1;
        }
        return i == n;
    }
};

//better Solution
class Solution {
public:
    bool wordPattern(string pattern, string str) {
        int p2i[26] {};
        unordered_map<string, int> w2i;
        istringstream in(str);
        int i = 0, n = pattern.size();
        for (string word; in >> word; ++i) {
            if (i==n||p2i[pattern[i] - 'a'] != w2i[word])
                return false;
            p2i[pattern[i] - 'a'] = w2i[word] = i + 1;
        }
        return i == n;
    }
};
