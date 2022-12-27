#ifndef C_STRING
#define C_STRING

#include <cstddef>

#define SBlock 10

namespace CS{

    class Buff;
    class String;

    inline size_t CStrlen(const char* data );

    inline size_t CalcMemLoc(size_t size);

    //////////////////////////////////////////
    // функция сравнения левой строки с правой
    // LStr > RStr     return -1
    // LStr < RStr     return 1
    // LStr == RStr    return 0
    //
    // /param LStr - left string
    //        RStr - right string
    //          
    // /return -1 0 1
    //////////////////////////////////////////
    inline int comp(const String& LStr, const String& RStr);

	
    class Buff{

    public:

        explicit Buff( size_t size = SBlock );
        explicit Buff( const Buff& );
        Buff( Buff&& ) noexcept;

        ~Buff();

        Buff& operator=(const Buff&);            
        Buff& operator=(Buff&&) noexcept;
        
        char& operator[] (size_t);
        const char& operator[] (size_t) const;

        void swap(Buff&);        
        
        //////////////////////////////////////////
        // создает новый буффер и переносит в него старые данные
        // старый буффер после этой операции считается непригодным
        //
        // /param   size - размер нового буффера
        // /return  char sequence length in buffer
        //////////////////////////////////////////
        size_t resize(size_t size);
                
        //////////////////////////////////////////
        // при условии, что места в буффере хватает
        // добавляет в него определенное кол-во символов
        // при недостатке места вызывает resize
        //
        // /param   char sequence, which add to buffer
        //          count char, which add to buffer,
        //          count = 0, is count = CStrlen( data )
        //
        // /return  char sequence length in buffer
        //////////////////////////////////////////
        size_t append(const char*, size_t count = 0);

    public:
        
        size_t size() const;

        const char* data() const; 
        
        size_t m_size;
        char *m_data;		
    };
	
	
    class String{

    public:
		
        explicit String( const char* );
        explicit String(size_t);
        String( const String& );	
        String( String&& ) noexcept;
        String();
		
        String& operator= ( const char* );
        String& operator= ( const String& );
        String& operator= ( String&& ) noexcept;
       
        String& operator+= ( char );
        String& operator+= ( const char* );
        String& operator+= ( const String& );
        
        char& operator[]( size_t );
        const char& operator[]( size_t ) const;
        
        void swap( String& );
        size_t append( const char*, size_t count = 0 );
                       
        const char* data() const;        
        const char* c_str() const;  
        
        size_t length() const; 
        size_t size() const;    
                
    private:

        Buff m_buffer;
        size_t m_length;
    };
	
    String operator+( const String &str1, const String &str2 );
    String operator+( const String &str1, const char* str2 );
    String operator+( const char *str1  , const String &str2 );
    
    bool operator<(const String &str1, const String &str2);
    bool operator>(const String &str1, const String &str2);
    bool operator==(const String &str1, const String &str2);
    bool operator!=(const String &str1, const String &str2);
    bool operator<=(const String &str1, const String &str2);
    bool operator>=(const String &str1, const String &str2);
	
}; //CS

#endif // C_STRING

//////////////////////////////////////////
// 
//////////////////////////////////////////