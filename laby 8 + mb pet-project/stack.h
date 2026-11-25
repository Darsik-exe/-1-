#pragma once

#include <iostream>
#include <vector>
#include <algorithm>

template <typename T>
class stack {
   public:
    stack() {
        m_st = new T[1];
        m_sz = 0;
    }

    stack(const std::vector<T>& v) {
        m_st = new T[1];
        m_sz = 0;

        add_size(v.size());

        for (const auto& x : v) {
            m_st[m_sz++] = x;
        }
    }

    ~stack() {
        delete[] m_st;

        m_sz = 0;
    }

    const T& top() const {
        if (empty()) {
            std::cerr << "Error: Stack is empty.";

            exit(0);
        }

        return m_st[m_sz - 1];
    }

    const int& size() const {
        return m_sz;
    }
    
    bool empty() const {
        return (m_sz == 0);
    }

    T& operator[] (const int& i) const {
        if (i >= m_sz) {
            std::cerr << "Error: The index is greater than the stack size.";
        
            exit(0);
        }

        return m_st[i];
    }

    void operator<< (const T& x) {
        add_size(m_sz + 1);
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
        if (this == &st) {
            return *this;
        }
    
        if (m_st) {
            delete[] m_st;
        }

        m_st = new T[1];
        m_sz = 0;
        add_size(st.size());

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
        if (m_sz != st.size()) 
            return false;

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
    int m_max_sz = 1;

    void add_size(const int& n) {
        if (n <= m_max_sz) return;

        int new_sz = m_max_sz;
        while (new_sz <= n) new_sz *= 2;

        T* nw_st = new T[new_sz];
        for (int i = 0; i < m_sz; ++i) 
            nw_st[i] = m_st[i];

        std::swap(nw_st, m_st);
        delete[] nw_st;

        return;
    }
};