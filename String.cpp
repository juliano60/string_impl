#include "String.hpp"
#include <cstring>

namespace tutorial {

    String::String():
        sz_{0},
        p_{&ch_[0]},
        space_{0}
    {
        ch_[0] = 0;
    }

    String::String(const char* s):
        sz_{std::strlen(s)},
        p_{sz_<=max_size ? &ch_[0]: new char[sz_+1]},
        space_{0}
    {
        std::strcpy(p_, s);
    }

    String::String(char ch, size_t n):
        sz_{n},
        p_{sz_<=max_size ? &ch_[0]: new char[sz_+1]},
        space_{0}
    {
        for (std::size_t i = 0; i !=n; ++i) {
            p_[i] = ch;
        }
        p_[sz_] = 0;
    }

    String::~String() {
        if (sz_>max_size) {
            delete[] p_;
        }
    }

    const char* String::c_str() const {
        return p_;
    }

    char* String::c_str() {
        return p_;
    }

    String::String(const String& s):
        sz_{s.sz_},
        p_{sz_<=max_size ? &ch_[0] : new char[sz_+1]},
        space_{0}
    {
        copy_from(s);
    }

    String& String::operator=(const String& s) {
        if (&s == this) return *this;

        char *p = sz_>max_size ? p_: 0;
        
        copy_from(s);

        delete[] p;

        return *this;
    }

    void String::copy_from(const String& s) {
        if(s.sz_<=max_size) {
            p_ = &ch_[0];
            std::strcpy(p_, s.ch_);
        }
        else {
            char* p = new char[s.sz_+1];
            std::strcpy(p, s.p_);
            p_ = p;
            space_ = 0;
        }
        sz_ = s.sz_;
    }

    String::String(String&& s)
    {
        move_from(s);
    }

    String& String::operator=(String&& s) {
        if (&s == this) return *this;

        char* p = sz_<=max_size? 0: p_;
        move_from(s);

        delete[] p;

        return *this;
    } 

    void String::move_from(String& s) {
        if (s.sz_<=max_size) {
            p_ = &ch_[0];
            std::strcpy(p_, s.ch_);
            sz_ = s.sz_;
        }
        else {
            p_ = s.p_;
            sz_ = s.sz_;
            space_ = s.space_;

            s.p_ = s.ch_;
            s.sz_ = 0;
            s.ch_[0] = 0;
        }
    }

    String& String::operator+=(char ch) {
        if (sz_==max_size) {
            size_type n = sz_*2 + 1;
            p_ = new char[n];
            std::strcpy(p_, ch_);
            space_ = n - sz_ - 2;
        }
        else if (sz_ > max_size) {
            if (space_==0) {
                size_type n = sz_*2 + 1; 
                char *p = new char[n];
                std::strcpy(p, p_);
                delete[] p_; 

                p_ = p;
                space_ = n - sz_ - 2;
            }
            else {
                --space_;
            }
        }

        p_[sz_] = ch;
        p_[++sz_] = 0;

        return *this;
    }

    String& operator+=(String& a, const String& b) {
        for (auto x: b) {
            a+=x;
        }

        return a;
    }

    String operator+(const String& a, const String& b) {
        String c{a};

        for (auto x: b) {
            c+=x;
        }

        return c;
    }

    char* begin(String& a) {
        return a.c_str();
    }

    const char* begin(const String& a) {
        return a.c_str();
    }

    char* end(String& a) {
        return a.c_str()+a.size();
    }

    const char* end(const String& a) {
        return a.c_str()+a.size();
    }

    String::size_type String::size() const {
        return sz_;
    }

    std::ostream& operator<<(std::ostream& out, const String& s) {
        out << "[" << s.sz_ << ","
            << s.c_str() << "]";

        return out;
    }

}
