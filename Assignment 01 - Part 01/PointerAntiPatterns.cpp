#include <iostream>
#include <string>

void antiPatternOne() {
    int* ptr1 = new int[100];
    for (int i = 0; i < 100; ++i) {
        ptr1[i] = i;
    }

    int* ptr2 = ptr1;
    delete[] ptr1;

    std::cout << "Anti-Pattern One: After deleting ptr1, accessing ptr2:\n";
    for (int i = 0; i < 10; ++i) {
        std::cout << ptr2[i] << " "; // Undefined behavior
    }
    std::cout << "\n";
}

void antiPatternTwo() {
    int* ptr1 = new int[100];
    for (int i = 0; i < 100; ++i) {
        ptr1[i] = i;
    }

    int* ptr2 = ptr1;
    delete ptr1; // Using delete instead of delete[] - potential memory corruption

    std::cout << "Anti-Pattern Two: Address of ptr2: " << ptr2 << "\n";
    std::cout << "First ten elements after deletion:\n";
    for (int i = 0; i < 10; ++i) {
        std::cout << ptr2[i] << " "; // Undefined behavior
    }
    std::cout << "\n";
}

std::string* returnLocalStringPointer() {
    std::string* str = new std::string("abcdefghijkl");
    return str; // Returning a pointer to a string
}

void useReturnedString() {
    std::string* returnedStr = returnLocalStringPointer();
    std::cout << "String returned from the function: " << *returnedStr << "\n";
    delete returnedStr; // Prevent memory leak by freeing the allocated memory
}

int main() {
    antiPatternOne();
    antiPatternTwo();
    useReturnedString();
    return 0;
}
