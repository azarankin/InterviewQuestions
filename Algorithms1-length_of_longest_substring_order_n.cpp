#include"pch"


int lengthOfLongestSubstring(const string& s)
{
    vector<int> charLastPoses(sizeof(char), -1);
    int maxLength = 0;
    int sectorLength = 0;
    int sectorStart = 0;

    for (int i = 0;i < s.size(); ++i)
    {
        int& charLastPos = charLastPoses[s[i]];

        if (sectorStart <= charLastPos)
        {
            sectorStart = charLastPos + 1;
            sectorLength = i - sectorStart;
        }

        charLastPos = i;

        ++sectorLength;

        maxLength = max(maxLength, sectorLength);
    }

    return maxLength;
}

