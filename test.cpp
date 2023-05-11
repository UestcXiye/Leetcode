#include <iostream>
#include <unordered_set>
#include <set>
#include <vector>
#include <cmath>
#include <string>
#include <algorithm>
using namespace std;

int main()
{
    int initialEnergy = 5;
    int initialExperience = 3;
    vector<int> energy = {1, 4, 3, 2};
    vector<int> experience = {2, 6, 3, 1};

    int ans = 0;
    int totalEnergy = 0;
    for (int i = 0; i < energy.size(); i++)
        totalEnergy += energy[i];
    int neededEnergy = totalEnergy - initialEnergy + 1;
    ans += neededEnergy > 0 ? neededEnergy : 0;
    int currentExperience = initialExperience;
    int neededExperience = 0;
    for (int i = 0; i < experience.size(); i++)
    {
        if (currentExperience <= experience[i])
        {
            neededExperience += experience[i] - currentExperience + 1;
            currentExperience += neededExperience + experience[i];
        }
        else
            currentExperience += experience[i];
    }
    cout << neededEnergy << " " <<

        system("pause");
    return 0;
}
