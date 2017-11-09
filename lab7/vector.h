#ifndef VECTOR_H
#define VECTOR_H 


#include <cstring>
#include <iostream>

template <typename T>
class Vector {
    private:
        T* value;
        size_t _capacity;
        size_t _size;

        void array_realloc();
        void shift_left();

    public:
        Vector(): _size(0), _capacity(0), value(nullptr) {};
        Vector(const Vector& rhs);
        Vector(Vector&& rhs);
        ~Vector();
        
        const bool   is_empty() const;
        const size_t size()     const;
        const size_t capacity() const;
        
        void push_back(const T elem);
        void clear();

        const void print() const;
        const T    pop_back();
 
        const Vector&  operator[](size_t n) const;
        Vector&  operator[](size_t n);

        Vector& operator=  (const Vector& rhs);
        Vector& operator+= (const Vector& rhs);

        template <typename  U>
        friend Vector<U> operator+ (Vector<U> rhs, Vector<U> &lhs);
        template <typename  U>
        friend bool operator == (const Vector<U> &rhs, const Vector<U> &lhs);
        template <typename  U>
        friend bool operator != (const Vector<U> &rhs, const Vector<U> &lhs);
        template <typename  U>
        friend bool operator >  (const Vector<U> &rhs, const Vector<U> &lhs);
        template <typename  U>
        friend bool operator >= (const Vector<U> &rhs, const Vector<U> &lhs);
        template <typename  U>
        friend bool operator <  (const Vector<U> &rhs, const Vector<U> &lhs);
        template <typename  U>
        friend bool operator <= (const Vector<U> &rhs, const Vector<U> &lhs);
};



template <typename  T>
Vector<T>::~Vector() {
    if (_capacity != 0 ) {
        delete[] value;
    }
} 

template <typename  T>
Vector<T>::Vector(const Vector& rhs):
    _capacity(rhs._capacity),
    _size(rhs._size)
{
    this->value = new T[_capacity];
    memcpy(this->value, rhs.value, sizeof(T)*(rhs._size)); 
}

template <typename  T>
Vector<T>::Vector(Vector&& rhs): 
    value(nullptr), 
    _capacity(0), 
    _size(0)  
{   
   value     = rhs.value;  
   _size     = rhs._size;
   _capacity = rhs._capacity;  
  
    rhs.value     = nullptr;  
    rhs._size     = 0;
    rhs._capacity = 0;  
}  

template <typename  T>
void Vector<T>::clear() {
    delete[] value;
    _capacity = 0;
    _size = 0;
}

template <typename  T>
const bool Vector<T>::is_empty() const {
    if (this->_size == 0) {
        return true; 
    }
    return false;
} 

template <typename  T>
const size_t Vector<T>::size() const {
    return this->_size;
} 

template <typename  T>
const void Vector<T>::print() const {
    for (int i = 0; i < this->_size; ++i) {
        std::cout << value[i] << " ";
    }
    std::cout << std::endl;
} 

template <typename  T>
const T Vector<T>::pop_back() {
    if (this->is_empty()) {
        throw std::length_error("You'r vector is empty");
    }
    T temp = this->value[_size-1];
    shift_left();
    return temp;
} 

template <typename  T>
const size_t Vector<T>::capacity() const {
    return this->_capacity;
} 

template <typename  T>
void Vector<T>::shift_left(){
   T* temp = value;
   value = new T[_capacity];
   memcpy(value, temp, sizeof(T)*(--_size));
   delete[] temp;
}

template <typename  T>
void Vector<T>::array_realloc() {
    if (_capacity == 0) {
        _capacity =  1;
    }
    _capacity *= 2;
    T* temp = value;
    value = new T[_capacity];
    memcpy(value, temp, sizeof(T)*_size);
    delete[] temp;
} 

template <typename  T>
void Vector<T>::push_back(const T elem) {
    if(_size ==_capacity) {
        array_realloc();
    }
    value[_size++] = elem;
} 

template <typename  U>
bool operator == (const Vector<U>& lhs, const Vector<U>& rhs) {
    if (lhs._size == rhs._size) {
        for (int i = 0; i < rhs._size; ++i) {
            if(lhs.value[i] != rhs.value[i]) 
                return 0;                
        }
        return 1;
    }
    return 0;
}

template <typename  U>
bool operator != (const Vector<U>& lhs, const Vector<U>& rhs) {
    if (lhs._size == rhs._size) {
        for (int i = 0; i < rhs._size; ++i) {
            if(lhs.value[i] != rhs.value[i]) 
                return 1;                
        }
        return 0;
    }
    return 1;
}

template <typename  U>
bool operator  > (const Vector<U>& lhs, const Vector<U>& rhs) {
    if (lhs._size > rhs._size) {
        return 1;
    }
    return 0;
}
 
template <typename  U> 
bool operator >= (const Vector<U>& lhs, const Vector<U>& rhs) {
    if (lhs._size >= rhs._size) {
        return 1;
    }
    return 0;
}
 
template <typename  U>
bool operator  < (const Vector<U>& lhs, const Vector<U>& rhs) {
    if (lhs._size < rhs._size) {
        return 1;
    } 
    return 0;
}


template <typename  U>
Vector<U> operator+ (Vector<U> rhs, Vector<U> &lhs) {
   return lhs += rhs;
}

template <typename  U> 
bool operator <= (const Vector<U>& lhs, const Vector<U>& rhs) {
    if (lhs._size <= rhs._size) {
        return 1;
    }
    return 0;
}

template <typename  T>
Vector<T>& Vector<T>::operator+= (const Vector<T>& rhs) {
    size_t len = this->_size + rhs._size;
    T* temp = new T[len]; 
    for (int i = 0; i < this->_size; ++i) {
        temp[i] = this->value[i];
    }
    for (int k = this->_size, j = 0; k < len; ++k, ++j) {
        temp[k] = rhs.value[j];
    }
    delete[] this->value;
    this->value = temp;
    this->_size = len;
    this->_capacity = len;

    return *this;
}

template <typename  T>
Vector<T>& Vector<T>::operator=(const Vector& rhs){
    if(this == &rhs) {
        throw std::invalid_argument("invalid_argument");
    }
    _capacity = rhs._capacity;
    _size     = rhs._size;
    if (this->_capacity != 0) {
        delete[] value;
    }
    this->value = new T[_capacity];
    memcpy(this->value, rhs.value, _size*sizeof(T));

    return *this;
}

template <typename  T>
const Vector<T>&  Vector<T>::operator[](size_t i) const {
    if(i < 0 || i >= (this->_size-1)) {
        throw std::out_of_range("out of range");
    }
    return value[i];
}

template <typename  T>
Vector<T>&  Vector<T>::operator[](size_t i) {
    if(i < 0 || i >= (this->_size-1)) {
        throw std::out_of_range("out of range");
    }
    return value[i];
}

#endif
