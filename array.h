#pragma once

#include "number.h"

class Array {
private:
    number* data;
    int size;
public:
    Array();
    Array(int n, number val = 0);
    Array(const Array& other);
    ~Array();

    void resize(int newSize);
    void setElement(int index, number val);
    number getElement(int index) const;

    void input();
    void output() const;

    number average() const;
    number deviation() const;

    void sortAsc();
    void sortDesc();


    bool isEmpty() const { return size == 0 || data == nullptr; }
    int getSize() const { return size; }
};
