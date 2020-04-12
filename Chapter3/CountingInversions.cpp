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
 * File:   CountingInversions.cpp
 * Author: sumandeep
 *
 * Created on 12 April, 2020, 6:41 PM
 */

#include <iostream>
#include <vector>

using namespace std;

int MergeAndCountSplitInv(vector<int> &data, int low, int high)
{
    vector<int>::const_iterator first = data.begin() + low;
    vector<int>::const_iterator last = data.begin() + high + 1;
    vector<int> buffer(first, last);
    int mid = (buffer.size() - 1) / 2;

    cout << "M> low " << low << ", mid " << mid << ", high " << high << endl;
    for (int i = 0; i < buffer.size(); i++)
    {
        cout << buffer[i] << ", ";
    }
    cout << endl;

    int i = 0;       // goes from 0 to mid
    int j = mid + 1; // goes from mid + 1 to buffer.size() - 1
    int splitInv = 0;
    for (int k = low; k <= high; k++)
    {
        cout << "k = " << k << ", ";
        if ((j > (buffer.size() - 1) || buffer[i] < buffer[j]) && i <= mid)
        {
            data[k] = buffer[i];
            cout << "pick from i " << i << ":" << buffer[i];
            i++;
        }
        else if ((i > mid || buffer[i] >= buffer[j]) && j <= (buffer.size() - 1))
        {
            data[k] = buffer[j];
            cout << "pick from j " << j << ":" << buffer[j];
            j++;
            splitInv += mid - i + 1;
        }
        cout << endl;
    }

    return splitInv;
}

int SortAndCountInv(vector<int> &data, int low, int high)
{
    int n = high - low + 1;
    int mid = (low + high) / 2;
    cout << "S> low " << low << ", mid " << mid << ", high " << high << endl;

    if (n <= 1)
    {
        return 0;
    }

    int leftInv = SortAndCountInv(data, low, mid);
    int rightInv = SortAndCountInv(data, mid + 1, high);
    int splitInv = MergeAndCountSplitInv(data, low, high);

    return leftInv + rightInv + splitInv;
}

int main(int argc, char *argv[])
{
    vector<int> a{1, 3, 5, 2, 4, 6};
    //vector<int> a{1, 2, 3, 4, 5, 6, 7, 8};
    //vector<int> a{8, 7, 6, 5, 4, 3, 2, 1};

    int max = SortAndCountInv(a, 0, a.size() - 1);
    cout << "Result is " << max << endl;
    for (int i = 0; i < a.size(); i++)
    {
        cout << a[i] << ", ";
    }

    cout << endl;

    return 0;
}
