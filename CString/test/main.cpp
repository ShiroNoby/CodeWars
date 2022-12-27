#pragma

#include <fstream>
#include <cstring>
#include "group\test_PCH.h"

const char* PATH = "../Test_resoult/CStrlen_test.txt";

//void test1(const char* PATH)
//{
//    //std::ios::app
//    std::ofstream file( PATH, std::ios::app);
//
//    if( file.is_open() ) 
//    {
//        
//        file << "test CString() & std::strlen()\n";
//
//        const char* data = "testiruem functiu na vozmojnie problems";
//
//        file << "\tour data is: " << data << "\n";
//        file << "\tstd::strlen( data ) = " << std::strlen(data) << "\n";
//        file << "\tCStrlen( data ) = " << CS::CStrlen(data) << "\n\n";
//
//        file.close();
//        return;
//    }
//}


int main()
{
    {
        std::ofstream file(PATH);
        if (file.is_open())
        {
            file << "test\n\n";
            file.close();
        }
    }


#ifdef CStrlen_test 

    CSTRLn::CSTRLn(PATH, "");
    CSTRLn::CSTRLn(PATH, " ");
    CSTRLn::CSTRLn(PATH, "!");
    CSTRLn::CSTRLn(PATH, "hello");

#endif //CStrlen_test


#ifdef CalcMemLoc_test

    CMLoc::CMLoc(PATH, 0);          //0
    CMLoc::CMLoc(PATH, SBlock / 2); // <block
    CMLoc::CMLoc(PATH, SBlock);     // == block
    CMLoc::CMLoc(PATH, SBlock + 5); // > block

#endif //CalcMemLoc_test


#ifdef ExpBufSize

    BF_CTR_SZ::BFCTRSZ(PATH,0);             //0
    BF_CTR_SZ::BFCTRSZ(PATH, SBlock / 2);   // <block
    BF_CTR_SZ::BFCTRSZ(PATH, SBlock);       // == block
    BF_CTR_SZ::BFCTRSZ(PATH, SBlock + 5);   // > block

#endif //ExpBufSize

#ifdef CSCMP

    CSComp::compare(PATH);

#endif //CSCMP
    
    return 0;
}