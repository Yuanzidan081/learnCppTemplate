#include <vector>
#include <algorithm>
#include <iostream>
#include "addValue.hpp"
using namespace std;



int main()
{
    // addValue Test
    {
        vector<int> src{ 1, 2, 3, 4, 5 };
        vector<int> dest(5);
        // Add 10 to each element in the vector
        transform(src.begin(), src.end(), dest.begin(), addValue<10, int>);
        for_each(dest.begin(), dest.end(), [](int value) { cout << value << " "; });
        cout << endl;
    }
    
    // addValue2 Test
    {
        vector<int> src{ 1, 2, 3, 4, 5 };
        vector<int> dest(5);
        transform(src.begin(), src.end(), dest.begin(), addValue2<10>);
        for_each(dest.begin(), dest.end(), [](int value) { cout << value << " "; });
        cout << endl;
    }

    // addValue3 Test
    {
        vector<int> src{ 1, 2, 3, 4, 5 };
        vector<int> dest(5);
        transform(src.begin(), src.end(), dest.begin(), addValue3<int, 10>);
        for_each(dest.begin(), dest.end(), [](int value) { cout << value << " "; });
        cout << endl;
    }

    return 0;
}