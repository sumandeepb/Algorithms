/*
    Copyright (C) 2020 Sumandeep Banerjee, sumandeep.banerjee@gmail.com

    This program is free software: you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published by
    the Free Software Foundation, either version 3 of the License, or
    (at your option) any later version.

    This program is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.

    You should have received a copy of the GNU General Public License
    along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */

/* 
 * File:   FindUnimodalMax.cpp
 * Author: sumandeepb
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
