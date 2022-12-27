#pragma

#include <fstream>
#include <cstring>
#include "..\..\..\src\CString.h"

#define CStrlen_test

namespace CSTRLn{
    
    void CSTRLn(const char* PATH, const char* test)
    {
        //std::ios::app
        std::ofstream file(PATH, std::ios::app);

        if (file.is_open())
        {
            file << "test CString() & std::strlen()\n";
            file << "\tour data is: [" << test << "]\n";
            file << "\tstd::strlen( data ) = " << std::strlen(test) << "\n";
            file << "\tCStrlen( data ) = " << CS::CStrlen(test) << "\n\n";

            file.close();
            return;
        }
    }
}; // CSTRLn