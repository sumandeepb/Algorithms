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
 * File:   FindUnimodalMax.cpp
 * Author: sumandeep
 *
 * Created on 11 April, 2020, 1:26 PM
 */

#include <iostream>
#include <vector>

using namespace std;

int findUnimodalMax(const vector<int> &data, int low, int high)
{
    int mid = (low + high) / 2;
    cout << "low " << low << ", mid" << mid << ", high " << high << endl;

    if (low == high)
    {
        cout << "1\n";
        return data[low];
    }

    if (data[mid] > data[mid - 1] && data[mid] > data[mid + 1])
    {
        return data[mid];
    }
    else if (data[mid + 1] > data[mid - 1])
    {
        return findUnimodalMax(data, mid + 1, high);
    }
    else
    {
        return findUnimodalMax(data, low, mid);
    }
}

int main(int argc, char *argv[])
{
    //vector<int> a{8, 10, 9, 7, 6, 5, 3, 1};
    vector<int> a{1, 3, 5, 6, 7, 9, 10, 8};

    int max = findUnimodalMax(a, 0, a.size() - 1);
    cout << "Result is " << max << endl;

    return 0;
}
