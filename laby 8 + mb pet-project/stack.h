#pragma once

#include <iostream>
#include <vector>

template <typename T>
class stack {
   public:
    stack() {
        m_st = new T[1000];
        m_sz = 0;
    }
    stack(const std::vector<T>& v) {
        m_st = new T[1000];
        m_sz = 0;

        for (const auto& x : v) {
            m_st[m_sz++] = x;
        }
    }

    ~stack() {
        delete[] m_st;

        m_sz = 0;
    }

    T top() const {
        if (empty()) {
            std::cerr << "Error: Stack is empty.";

            exit(0);
        }

        return m_st[m_sz - 1];
    }
    int size() const {
        return m_sz;
    }
    bool empty() const {
        return (m_sz == 0);
    }

    T& operator[] (const int& i) {
        return m_st[i];
    }
    T operator[] (const int& i) const {
        return m_st[i];
    }

    void operator<< (const T& x) {
        m_st[m_sz++] = x;

        return;
    }
    void operator>> (int) {
        if (m_sz == 0) {
            std::cerr << "Error: Stack is empty.";
        
            exit(0);
        }

        m_st[--m_sz];

        return;
    }
    
    stack& operator= (const stack& st) {
        if (*this == st) return *this;
    
        if (m_st) {
            delete[] m_st;
        }

        m_st = new T[1000];

        for (int i = 0; i < st.size(); ++i) {
            m_st[m_sz++] = st[i];
        }

        return *this;
    }
    
    bool operator< (const stack& st) {
        if (m_sz < st.size()) {
            return true;
        }
        if (m_sz > st.size()) {
            return 0;
        }

        int i = 0;
        while (i < m_sz && m_st[i] == st[i]) {
            ++i;
        }

        if (i == m_sz || m_st[i] > st[i]) {
            return false;
        }

        return true;
    }
    bool operator> (const stack& st) {
        if (m_sz > st.size()) {
            return true;
        }
        if (m_sz < st.size()) {
            return 0;
        }

        int i = 0;
        while (i < m_sz && m_st[i] == st[i]) {
            ++i;
        }

        if (i == m_sz || m_st[i] < st[i]) {
            return false;
        }

        return true;
    }
    bool operator== (const stack& st) {
        if (m_sz != st.size()) return false;

        int i = 0;
        while (i < m_sz && m_st[i] == st[i]) {
            ++i;
        }

        if (i != m_sz) {
            return false;
        }
    
        return true;
    }
    bool operator<= (const stack& st) {
        return (*this < st || *this == st);
    }
    bool operator>= (const stack& st) {
        return (*this > st || *this == st);
    }

   private:
    T* m_st = nullptr;
    int m_sz;
};