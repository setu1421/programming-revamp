// https://www.youtube.com/watch?v=2cRS9dNa780
string Solution::fractionToDecimal(int A, int B)
{
    // Corner case
    if(A == 0) return "0";

    string output = "";
    // If any number is negative, then add negative sign
    if(A < 0 ^ B < 0)
    {
        output = "-";
    }

	// long long is needed for A = INT_MIN and B = -1 as output will be INT_MAX + 1
    long long a = abs((long long) A);
    long long b = abs((long long) B);

    long long r = (a % b);
    output += to_string(a / b);
    // if remainder is 0, then return the output
    if(r == 0)
    {
        return output;
    } else
    {
        // add "." for decimal
        output += ".";
        unordered_map<long long, int>mp;
        // add to the output untill remainder becomes 0
        while(r != 0)
        {
            // if we found the same remainder again, that means repeat is present.
            // Insert "(" at the repeat start and enclose by ")"
            if(mp.find(r) != mp.end())
            {
                output.insert(mp[r], "(");
                output += ")";
                break;
            } else
            {
                // save the index position to add "(" for the remainder
                mp[r] = output.length();
                r = r * 10;
                output += to_string(r / b);
                r = r % b;
            }
        }
    }

    return output;
}