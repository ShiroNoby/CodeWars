#pragma

#include <fstream>
#include <cstring>
#include "..\..\..\src\CString.h"

#define CSCMP

namespace CSComp{
    
    void compare(const char* PATH)
    {
        //std::ios::app
        std::ofstream file(PATH, std::ios::app);
        
        auto script = [&file](CS::String &str1, CS::String &str2)
        {
            if (file.is_open())
            {
                file << "\nstr1[" << str1.data() << "] str2["  << str2.data() << "]\n";
                file << "\tstr1 < str2 "   << ( str1 < str2 )  << "\n";
                file << "\tstr1 > str2 "   << ( str1 > str2 )  << "\n";
                file << "\tstr1 == str2 "  << ( str1 == str2 )  << "\n";
                file << "\tstr1 <= str2 "  << ( str1 <= str2 )  << "\n";
                file << "\tstr1 >= str2 "  << ( str1 >= str2 )  << "\n";
            }
        };

        {
            CS::String str1("");
            CS::String str2("");        
            script(str1, str2);
        }

        {
            CS::String str1("1");
            CS::String str2("");
            script(str1, str2);
        }

        {
            CS::String str1("");
            CS::String str2("1");
            script(str1, str2);
        }

        {
            CS::String str1("1");
            CS::String str2("1");
            script(str1, str2);
        }

        {
            CS::String str1("11");
            CS::String str2("1");
            script(str1, str2);
        }

        {
            CS::String str1("1");
            CS::String str2("11");
            script(str1, str2);
        }
        
        file.close();
    }
}; // CSTRLn