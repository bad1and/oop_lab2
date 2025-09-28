#include "array.h"
#include <cmath>
#include <algorithm>
#include <ncurses.h>

Array::Array() : data(nullptr), size(0) {}

Array::Array(int n, number val) {
    if (n > 0) {
        size = n;
        data = new number[size];
        for (int i = 0; i < size; i++) data[i] = val;
    } else {
        size = 0;
        data = nullptr;
    }
}

Array::Array(const Array& other) {
    size = other.size;
    if (size > 0) {
        data = new number[size];
        for (int i = 0; i < size; i++) data[i] = other.data[i];
    } else {
        data = nullptr;
    }
}

Array::~Array() {
    delete[] data;
}

void Array::resize(int newSize) {
    if (newSize <= 0) return;
    number* newData = new number[newSize];
    int m = (newSize < size) ? newSize : size;
    for (int i = 0; i < m; i++) newData[i] = data[i];
    delete[] data;
    data = newData;
    size = newSize;
}

void Array::setElement(int index, number val) {
    if (index >= 0 && index < size) {
        data[index] = val;
    }
}

number Array::getElement(int index) const {
    if (index >= 0 && index < size) {
        return data[index];
    }
    return number();
}

void Array::input() {
    echo();
    int newSize;
    char extra[100];

    printw("Введите размер массива: ");
    if (scanw("%d%99s", &newSize, extra) != 1 || newSize <= 0) {
        size = 0;
        delete[] data;
        data = nullptr;
        printw("Ошибка: нужно ввести одно целое положительное число!\n");
        getch();
        noecho();
        return;
    }

    delete[] data;
    size = newSize;
    data = new number[size];

    printw("Введите элементы массива (Re Im):\n");
    for (int i = 0; i < size; i++) {
        double re, im;
        if (scanw("%lf %lf", &re, &im) == 2) {
            data[i] = number(re, im);
        } else {
            data[i] = number();
        }
    }
    noecho();
}

void Array::output() const {
    if (isEmpty()) {
        printw("Массив пуст!\n");
        return;
    }

    printw("Массив: ");
    for (int i = 0; i < size; i++) {
        data[i].print();
        printw(" ");
    }
    printw("\n");
}

number Array::average() const {
    if (isEmpty()) return number();
    double sumRe = 0, sumIm = 0;
    for (int i = 0; i < size; i++) {
        sumRe += data[i].real();
        sumIm += data[i].imag();
    }
    return number(sumRe / size, sumIm / size);
}

number Array::deviation() const {
    if (isEmpty()) return number();
    number avg = average();
    double sum = 0;
    for (int i = 0; i < size; i++) {
        double dRe = data[i].real() - avg.real();
        double dIm = data[i].imag() - avg.imag();
        sum += dRe * dRe + dIm * dIm;
    }
    return number(std::sqrt(sum / size), 0);
}

void Array::sortAsc() {
    if (!isEmpty()) {
        std::sort(data, data + size, [](const number& a, const number& b) {
            return a.abs() < b.abs();
        });
    }
}

void Array::sortDesc() {
    if (!isEmpty()) {
        std::sort(data, data + size, [](const number& a, const number& b) {
            return a.abs() > b.abs();
        });
    }
}
