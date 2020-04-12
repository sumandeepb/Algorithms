/*
    Copyright (C) 2018 Sumandeep Banerjee, sumandeep.banerjee@gmail.com

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
 * StringPermutations.cpp: Program to generate all permutations of an input string
 */

#include <cstdlib>
#include <iostream>
#include <vector>
#include <string>

using namespace std;

void getPermsWDups(string &prefix, vector<string> &perms, int count[])
{
    bool flag = false;
    for (int i = 0; i < 256; i++)
    {
        if (count[i] > 0)
        {
            count[i]--;
            string newPrefix = prefix + string(1, (char)i);
            getPermsWDups(newPrefix, perms, count);
            count[i]++;
            flag = true;
        }
    }

    if (false == flag)
    {
        perms.push_back(prefix);
    }
}

void getPermutations(string &str, vector<string> &perms)
{
    int count[256] = {
        0,
    };

    for (int i = 0; i < str.length(); i++)
    {
        count[(unsigned char)str[i]]++;
    }

    string prefix("");
    getPermsWDups(prefix, perms, count);
}

int main(int argc, char *argv[])
{
    string str(argv[1]);
    vector<string> perms;

    getPermutations(str, perms);
    cout << "Number of permutations for " << str << " are " << perms.size() << endl;
    for (int j = 0; j < perms.size(); j++)
    {
        cout << perms[j] << ", ";
    }
    cout << endl;

    return 0;
}