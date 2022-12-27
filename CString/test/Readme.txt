CS_Utility
    inline size_t CStrlen(const char* data);
    inline size_t CalcMemLoc(size_t size);
    inline int comp(const String& LStr, const String& RStr);
    
CS_Buff
    class buff
        ctor
            explicit Buff( size_t size = SBlock );
            explicit Buff( const Buff& );
            Buff( Buff&& );
        dtor
            ~Buff();
        operator=
            Buff& operator=(const Buff&);            
            Buff& operator=(Buff&&);
        operator[]
            char& operator[] (size_t);
            const char& operator[] (size_t) const;
        swap
            void swap(Buff&);
        resize
            size_t resize(size_t size);
        append
            size_t append(const char*, size_t count);
        size
            size_t size() const;
        data
            const char* data() const; 

  
CS_String
    class String
        ctor
            explicit String( const char* );	
            explicit String( size_t );
            String( const String& );	
            String( String&& );		
            String();
            
        operator=
            String& operator= ( const char* );
            String& operator= ( const String& );
            String& operator= ( String&& );	
            
        operator+=
            String& operator+= ( char );
            String& operator+= ( const char* );
            String& operator+= ( const String& );
            
        operator[]
            char& operator[]( size_t );
            const char& operator[]( size_t ) const;
            
        swap
            void swap( String& );
            
        append
            size_t append( const char*, size_t count );
            
        data              
            const char* data() const;        
            const char* c_str() const;  
            
        length
            size_t length() const;
            
        size
            size_t size() const;
            
CS_Ex
operator+
    String operator+( const String &str1, const String &str2 );
    String operator+( const String &str1, const char* str2 );
    String operator+( const char *str1  , const String &str2 );
    
compare
    bool operator<(const String &str1, const String &str2);
    bool operator>(const String &str1, const String &str2);
    bool operator==(const String &str1, const String &str2);
    bool operator!=(const String &str1, const String &str2);
    bool operator<=(const String &str1, const String &str2);
    bool operator>=(const String &str1, const String &str2);