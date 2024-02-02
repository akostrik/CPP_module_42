#pragma once
#include <iostream>

template <typename T> class Array {

private:
    T*              _arr;
    unsigned int    _len;

public:
    Array() : _arr(new T()),  _len(0) {};

    Array(unsigned int n) : _arr(new T[n]), _len(n) {};
    
    ~Array() { 
        delete [] _arr; 
    }

    Array(const Array& o) : _arr(new T[o.size()]), _len(o.size()) {
        for (unsigned int i = 0; i < _len; i++)
            _arr[i] = o._arr[i];
    };

    Array& operator=(const Array& o) {
        if (this != &o) {
            delete [] _arr;
            _arr = new T[o.size()];
            _len = o._len;
            for (unsigned int i =0; i < _len; i++)
                _arr[i] = o._arr[i];
        }
        return *this;
    }

    T& operator[](unsigned int i) const {
        if (i >= _len || i < 0)
            throw OutOfBoundsException();
        return _arr[i];
    }

    unsigned int size() const { 
        return _len; 
    }

    class OutOfBoundsException : public std::exception {
        public:
            virtual const char* what() const throw() { 
                return "Index is out of bounds";
            }
    };
};

template <typename T> std::ostream& operator<<(std::ostream& out, const Array<T>& arr) {
    for (unsigned int i(0); i < arr.size(); i++ )
        out << arr[i] << " ";
    return out;
}