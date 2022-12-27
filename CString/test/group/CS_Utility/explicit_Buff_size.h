#pragma

#include <fstream>
#include <cstring>
#include "..\..\..\src\CString.h"

#define ExpBufSize

namespace BF_CTR_SZ{
    
    void BFCTRSZ(const char* PATH, size_t size)
    {
        //std::ios::app
        std::ofstream file(PATH, std::ios::app);

        if (file.is_open())
        {
            file << "test explicit Buff(size_t)\n";
            file << "\tour size is: [" << size << "]\n";
            
            CS::Buff tmp(size);
            
            file << "\tBuff size = " << tmp.size() << "\n";
            file << "\tVuff.m_data = [" << tmp.data() << "]\n\n";

            file.close();
            return;
        }
    }
    
}; //BF_CTR_SZ