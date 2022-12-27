#include <string>
#include <cstddef>

bool first = true;

void shufle(std::string& dStr, const std::string& sStr)
{
    if(!first) dStr += ' ';
    first = false;

    if (sStr.size() < 5)
    {
        dStr += sStr;
        return;
    }

    for (auto it = sStr.rbegin(), end = sStr.rend(); it != end; ++it)
    {
        dStr += *it;
    }
}

std::string spinWords(const std::string& str)
{
    std::string newStr;

    size_t pos1 = -1;
    size_t pos2 = 0;
    size_t end = 0;

    for (size_t indexStr = 0, endStr = str.size(); indexStr < endStr; ++indexStr)
    {
        if (pos1 == -1 && str[indexStr] != ' ') pos1 = indexStr;
        if (str[indexStr] != ' ') pos2 = indexStr;
        if (str[indexStr] == ' ') end = indexStr;

        if (end)
        {
            //it2
            if(pos1 != -1) shufle(newStr, str.substr(pos1, pos2 - pos1 + 1));

            pos1 = -1;
            pos2 = 0;
            end = 0;
        }


        if (pos2 == str.size() - 1)
        {
            //it2
            shufle(newStr, str.substr(pos1, pos2 - pos1 + 1));

            break;
        }
    }
	first = true;
    return newStr;
}