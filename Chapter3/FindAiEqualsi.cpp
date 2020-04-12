/*
    Copyright 2020 Sumandeep Banerjee (sumandeep.banerjee@gmail.com)

    Licensed under the Apache License, Version 2.0 (the "License");
    you may not use this file except in compliance with the License.
    You may obtain a copy of the License at

        http://www.apache.org/licenses/LICENSE-2.0

    Unless required by applicable law or agreed to in writing, software
    distributed under the License is distributed on an "AS IS" BASIS,
    WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
    See the License for the specific language governing permissions and
    limitations under the License.
*/

/* 
 * File:   FindAiEqualsi.cpp
 * Author: sumandeep
 *
 * Created on 12 April, 2020, 3:39 AM
 */

#include <iostream>
#include <vector>

using namespace std;

int findAiEqualsi(const vector<int> &data, int low, int high)
{
    int mid = (low + high) / 2;
    cout << "low " << low << ", mid" << mid << ", high " << high << endl;

    if (data[mid] == mid)
    {
        return mid;
    } else if (low == high)
    {
        return -1;
    }
    else if (data[mid] > mid)
    {
        if (low == mid)
        {
            return -1;
        }
        return findAiEqualsi(data, low, mid);
    }
    else if (data[mid] < mid)
    {
        if (mid == high)
        {
            return -1;
        }
        return findAiEqualsi(data, mid + 1, high);
    }
}

int main(int argc, char *argv[])
{
    //vector<int> a{-18, -16, -14, -12, -10, -8, -6, -4, -2};
    //vector<int> a{2, 4, 6, 8, 10, 12, 14, 16, 18};
    //vector<int> a{-5, -3, -1, 1, 3, 5, 7, 9};
    vector<int> a{-3, -1, 1, 3, 5, 7, 9, 11};
    //vector<int> a{-1, 1, 3, 5, 7, 9, 11, 13, 15};

    int max = findAiEqualsi(a, 0, a.size() - 1);
    cout << "Result is " << max << endl;

    return 0;
}
