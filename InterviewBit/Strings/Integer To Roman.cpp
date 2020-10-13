string addToString(string ans, int count, char c)
{
    for(int i = 0; i < count; i++)
    {
        ans += c;
    }
    
    return ans;
}

string Solution::intToRoman(int A) {
    string ans = "";
    
    while(A > 0)
    {
        if(A >= 1000)
        {
            int count = A / 1000;
            ans = addToString(ans, count, 'M');
            A = A % 1000;
        } else if(A >= 900)
        {
            ans += "CM";
            A = A % 900;
        } else if(A >= 500)
        {
            int count = A / 500;
            ans = addToString(ans, count, 'D');
            A = A % 500;
        } else if(A >= 400)
        {
            ans += "CD";
            A = A % 400;
        } else if(A >= 100)
        {
            int count = A / 100;
            ans = addToString(ans, count, 'C');
            A = A % 100;
        } else if(A >= 90)
        {
            ans += "XC";
            A = A % 90;
        } else if(A >= 50)
        {
            ans += "L";
            A = A % 50;
        } else if(A >= 40)
        {
            ans += "XL";
            A = A % 40;
        } else if(A >= 10)
        {
            int count = A / 10;
            ans = addToString(ans, count, 'X');
            A = A % 10;
        } else if(A == 9)
        {
            ans += "IX";
            A = A % 9;
        } else if(A >= 5)
        {
            ans += "V";
            A = A % 5;
        } else if(A == 4)
        {
            ans += "IV";
            A = A % 4;
        } else if(A >= 1)
        {
            ans = addToString(ans, A, 'I');
            A = 0;
        }
    }
    return ans;
}


// Another Approach:
class Solution {
public:
    string intToRoman(int num) {
        // 1000, 2000, 3000
        string M[] = {"", "M", "MM", "MMM"};
        // 100, 200, 300, .. 900
        string C[] = {"", "C", "CC", "CCC", "CD", "D", "DC", "DCC", "DCCC", "CM"};
        // 10, 20, ... 90
        string X[] = {"", "X", "XX", "XXX", "XL", "L", "LX", "LXX", "LXXX", "XC"};
        // 1, 2, ... 9
        string I[] = {"", "I", "II", "III", "IV", "V", "VI", "VII", "VIII", "IX"};
        return M[num/1000] + C[(num%1000)/100] + X[(num%100)/10] + I[num%10];
    }
};