#include <cstddef>
#include <string>

void shufle(std::string& str, size_t pos1, size_t pos2)
{
    size_t gap = pos2 - pos1;
    size_t del = gap / 2;
    size_t cent = gap % 2;

    if (gap < 5) return;

    if (cent)
    {
        //val + pos1
        size_t val = del + cent + pos1;

        for (; pos1 != val;)
        {
            const char tmp = str[pos1];
            str[pos1] = str[pos2];
            str[pos2] = tmp;

            ++pos1;
            --pos2;
        }
        return;
    }

    for (; pos1 <= del;)
    {
        const char tmp = str[pos1];
        str[pos1] = str[pos2];
        str[pos2] = tmp;

        ++pos1;
        --pos2;
    }
}

void clearSpace(std::string& str)
{
    auto it = str.begin();
    for (; it != str.end(); ++it)
    {
        if (*it == ' ')
        {
            if (it == (str.end() - 1))  
            {
                str.erase(it);
                --it;
                continue;
            }

            if (*(it + 1) == ' ')
            {
                str.erase(it);
                --it;
                continue;
            }
        }
    }
}

std::string spinWords(const std::string& str)
{
    std::string newStr = str;
    clearSpace(newStr);

    size_t pos1 = -1;
    size_t pos2 = 0;
    size_t end = 0;


    for (size_t indexStr = 0, endStr = str.size(); ; ++indexStr)
    {
        //pos1 == indexStr == 0
        if (pos1 == -1)
        {
            pos1 = indexStr;
            pos2 = indexStr;
        }

        if (str[indexStr] != ' ') pos2 = indexStr;
        if (str[indexStr] == ' ') end = indexStr;

        if (end)
        {
            //it2
            shufle(newStr, pos1, pos2);

            pos1 = -1;
            pos2 = 0;
            end = 0;
        }


        if (pos2 == str.size() - 1)
        {
            //it2
            shufle(newStr, pos1, pos2);

            break;
        }
    }
    return newStr;
}