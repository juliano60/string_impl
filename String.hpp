#ifndef STRING_HPP
#define STRING_HPP

#include <cstddef>
#include <iostream>

namespace tutorial {

    constexpr int max_size = 15;

    class String {
    public:
        friend std::ostream& operator<<(std::ostream& out, const String& s);
        using size_type = std::size_t;

        String();
        String(const char* s);
        String(char ch, size_t n);

        String(const String& s);
        String& operator=(const String& s);

        String(String&& s);
        String& operator=(String&& s);

        ~String();

        const char* c_str() const;
        char* c_str();

        String& operator+=(char ch);
        size_type size() const;

    private:
        void copy_from(const String& s);
        void move_from(String& s);

    private:
        char ch_[max_size+1]; //allow for NUL terminator
        size_type sz_;
        char* p_;
        size_type space_; 
    }; 

    String& operator+=(String& a, const String& b);
    String operator+(const String& a, const String& b);

    char* begin(String& a);
    const char* begin(const String& a);
    char* end(String& a);
    const char* end(const String& a);

}

#endif
