/*
    Copyright (C) 2023 Sumandeep Banerjee, sumandeep.banerjee@gmail.com

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
 * File:   KaratsubaMult.cpp
 * Author: sumandeep
 *
 * Created on 26 January, 2023
 */

#include <iostream>
#include <stdexcept>
#include <vector>

using namespace std;
int g_cCompares = 0;

vector<int> FindMaxByKnockout(const int begin, const int end, const vector<int> &aNumbers) {

    if (begin == end) { // base case
        vector<int> compared;
        compared.push_back(aNumbers[begin]);
        return compared;
    }

    vector<int> compared1 = FindMaxByKnockout(begin, begin + (end - begin) / 2, aNumbers);
    vector<int> compared2 = FindMaxByKnockout(1 + begin + (end - begin) / 2, end, aNumbers);
    g_cCompares++;
    if (compared1[0] > compared2[0]) {
        compared1.push_back(compared2[0]);
        return compared1;
    } else {
        compared2.push_back(compared1[0]);
        return compared2;
    }
}

int FindSecondMax(const vector<int> &aNumbers) {
    int length = aNumbers.size();
    if (length < 2) {
        throw std::invalid_argument("list must be atleast length2");
    }

    vector<int> compared = FindMaxByKnockout(0, length - 1, aNumbers);
    vector<int> compared2 = FindMaxByKnockout(1, compared.size() - 1, compared);

    return compared2[0];
}

int main(int argc, char *argv[]) {
    vector<int> a{1, 3, 5, 2, 4, 6, 8, 7};
    vector<int> b{1};

    // cout << "max: " << FindMaxByKnockout(0, a.size() - 1, a)[0] << endl;
    cout << "2nd max: " << FindSecondMax(a) << endl;
    cout << "comparisons: " << g_cCompares << endl;

    return 0;
}
