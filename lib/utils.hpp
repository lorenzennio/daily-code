#pragma once
#include <iostream>
#include <vector>

// Wrapper for printing a vector
template <typename T>
struct PrintableVector {
    const std::vector<T>& vec;
};

// Overload operator<< for the wrapper
template <typename T>
std::ostream& operator<<(std::ostream& os, const PrintableVector<T>& pv) {
    os << "[";
    for (size_t i = 0; i < pv.vec.size(); ++i) {
        os << pv.vec[i];
        if (i + 1 < pv.vec.size()) os << ", ";
    }
    os << "]";
    return os;
}

// Helper function to create the wrapper
template <typename T>
PrintableVector<T> print_vector(const std::vector<T>& vec) {
    return PrintableVector<T>{vec};
}