#include <iostream>

class Vector {
private:
    static const int MAX_SIZE = 100;
    int size;
    int* elements;

public:
    Vector() : size(0), elements(new int[MAX_SIZE]) {}

    Vector(int sz) : size(sz), elements(new int[sz]) {
        std::cout << "Nhap " << size << " phan tu cho vector:\n";
        for (int i = 0; i < size; ++i) {
            std::cout << "Phan tu thu " << i + 1 << ": ";
            std::cin >> elements[i];
        }
    }

    ~Vector() {
        delete[] elements;
    }

    void display() const {
        std::cout << "Cac phan tu cua vector:\n";
        for (int i = 0; i < size; ++i) {
            std::cout << "vec[" << i << "] = " << elements[i] << std::endl;
        }
    }
};

int main() {
    int size;
    std::cout << "Nhap kich thuoc cua vector: ";
    std::cin >> size;

    Vector vec(size);

    vec.display();

    return 0;
}
