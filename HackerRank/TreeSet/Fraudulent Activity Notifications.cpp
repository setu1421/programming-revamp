#include <bits/stdc++.h>
using namespace std;

// fixed size sliding window:
// use 1 treeset:
// odd: 1,2,3
// -> new < median && removed >= median : largestSmaller
// -> new < median && removed < median: median
// -> new > median && removed <= median : smallestLarger
// -> new > median && removed > median: median
// even: [0]1,2,3,4[5]
// -> new < median && removed >= median : largestSmaller(median), median
// -> new < median && removed < median: median
// -> new > median && removed <= median : smallestLarger, median
// -> new > median && removed > median: median
// => no matter it's odd or even count in the sliding widow:
//   case 1: new < median && removed >= median : largestSmaller(median), median
//   case 2: new > median && removed <= median : smallestLarger, median

class Expenditure
{
public:
    int value;
    int seq;

    Expenditure(int v, int s)
    {
        value = v;
        seq = s;
    }

    bool operator < (const Expenditure &other) const
    {
        if(this->value == other.value)
        {
            return this->seq < other.seq;
        }

        return this->value < other.value;
    }

    bool operator <= (const Expenditure &other) const
    {
        if(this->value == other.value)
        {
            return this->seq <= other.seq;
        }

        return this->value <= other.value;
    }
};

int main()
{
    int n, k, num, notice_count = 0;
    float median_value;
    cin>>n>>k;

    set<Expenditure>window;
    vector<int>arr;

    Expenditure median(-1, -1);

    for(int i = 0; i < n; i++)
    {
        cin>>num;
        arr.push_back(num);

        Expenditure newEntry(num, i);
        window.insert(newEntry);

        if(i == 0)
        {
            median = newEntry;
            median_value = median.value;
        }

        // Insert all the elements of the window first and calculate the median
        if(i < k)
        {
            if((window.size() % 2 == 0) && newEntry < median)
            {
                median = *(--window.lower_bound(median));
            } else if(window.size() % 2 != 0 && median < newEntry)
            {
                median = *(window.upper_bound(median));
            }
        } else
        {
            if(newEntry.value >= 2.0 * median_value)
            {
                notice_count++;
            }

            Expenditure removed(arr[i-k], i-k);
            window.erase(removed);

            // Update the median
            if(median < newEntry && removed <= median)
            {
                median = *(window.upper_bound(median));
            } else if(newEntry < median && median <= removed)
            {
                median = *(--window.lower_bound(median));
            }
        }

        // Update the median value based on window size even or odd
        if(i >= k - 1)
        {
            if(window.size() % 2 == 0)
            {
                median_value = (median.value + (*(window.upper_bound(median))).value)/2.0;
            } else
            {
                median_value = median.value;
            }
        }
    }

    cout<<notice_count<<endl;
}

//Alternate Solution:
