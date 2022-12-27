#pragma

#include <fstream>
#include <cstring>
#include "..\..\..\src\CString.h"

#define CalcMemLoc_test

namespace CMLoc{

    void CMLoc(const char* PATH, size_t size)
    {
        //std::ios::app
        std::ofstream file(PATH, std::ios::app);

        if (file.is_open())
        {
            file << "test CalcMemLoc()\n";
            file << "\tour size is: " << size << "\n";
            file << "\tCS::CalcMemLoc(size) = " << CS::CalcMemLoc(size) << "\n\n";

            file.close();
            return;
        }
    }
};  //CMloc