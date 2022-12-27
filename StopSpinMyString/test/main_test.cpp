#include <string>
#include <iostream>
#include "../src/spinWordsv2.h"

int main()
{
    std::string str1 = "hey fellow warriors";
    std::string str2 = "hey wollef sroirraw";

    std::string str3 = "hey   ";
    std::string str4 = "hey";

    std::string str5 = "hey ";
    std::string str6 = "hey";

    std::string str7 = "warriors";
    std::string str8 = "sroirraw";

    std::string str9 = "wars republic";
    std::string str10 = "wars cilbuper";

    if (spinWords(str1) == str2) 	std::cout << "#1true" << std::endl;
    std::cout << spinWords(str1) << std::endl;

    if (spinWords(str3) == str4) 	std::cout << "#2true" << std::endl;
    std::cout << spinWords(str3) << std::endl;

    if (spinWords(str5) == str6) 	std::cout << "#3true" << std::endl;
    std::cout << spinWords(str5) << std::endl;

    if (spinWords(str7) == str8) 	std::cout << "#4true" << std::endl;
    std::cout << spinWords(str7) << std::endl;

    if (spinWords(str9) == str10) 	std::cout << "#5true" << std::endl;
    std::cout << spinWords(str9) << std::endl;

    return 0;
}
