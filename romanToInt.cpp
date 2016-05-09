/*Given a roman numeral, convert it to an integer.
Input is guaranteed to be within the range from 1 to 3999.*/

// Solution 
class Solution {
public:
    int romanToInt(string s) {
        int len=s.length();
        int sum=0;
        for(int i=0;i!=len;i++)
        {
            if(i>0)
                sum+=getNum(s[i-1],s[i]);
            else
                sum+=getNum(s[i]);
        }
        return sum;
    }
    int getNum(char c1,char c2)
    {
        switch(c2)
        {
               case 'I':return 1;
            case 'V':
                if(c1=='I')
                    return 3;
                return 5;
            case 'X':
                if(c1=='I')
                    return 8;
                return 10;
            case 'L':
                if(c1=='X')
                    return 30;
                return 50;
            case 'C':
                if(c1=='X')
                    return 80;
                return 100;
            case 'D':
                if(c1=='C')
                    return 300;
                return 500;
            case 'M':
                if(c1=='C')
                    return 800;
                return 1000;
        }
    }
    int getNum(char c)
    {
        switch(c)
        {
               case 'I':return 1;
            case 'V':return 5;
            case 'X':return 10;
            case 'L':return 50;
            case 'C':return 100;
            case 'D':return 500;
            case 'M':return 1000;
        }
    }
};
