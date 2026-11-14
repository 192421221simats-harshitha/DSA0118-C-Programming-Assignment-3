
#include <iostream>
#include <cstring>
using namespace std;

class Text {
    char* data;

public:
    // Constructor
    Text(const char* str = "") {
        data = new char[strlen(str) + 1];
        strcpy(data, str);
    }

    // Copy constructor - deep copy
    Text(const Text& other) {
        data = new char[strlen(other.data) + 1];
        strcpy(data, other.data);
        cout << "Copy constructor called\n";
    }

    // Copy assignment operator
    Text& operator=(const Text& other) {
        if (this != &other) {
            char* temp = new char[strlen(other.data) + 1];
            strcpy(temp, other.data);

            delete[] data;
            data = temp;
        }
        return *this;
    }

    // Concatenation operator
    Text operator+(const Text& other) const {
        char* temp = new char[
            strlen(data) + strlen(other.data) + 1
        ];

        strcpy(temp, data);
        strcat(temp, other.data);

        Text result(temp);
        delete[] temp;

        return result;
    }

    // Equality operator
    bool operator==(const Text& other) const {
        return strcmp(data, other.data) == 0;
    }

    // Not equal operator
    bool operator!=(const Text& other) const {
        return !(*this == other);
    }

    // Stream output operator
    friend ostream& operator<<(ostream& out, const Text& t) {
        out << t.data;
        return out;
    }

    // Destructor
    ~Text() {
        delete[] data;
    }
};

int main() {
    Text t1("Hello ");
    Text t2("World");

    cout << "Text 1: " << t1 << '\n';
    cout << "Text 2: " << t2 << '\n';

    // Concatenation
    Text t3 = t1 + t2;
    cout << "Combined Text: " << t3 << '\n';

    // Copy constructor
    Text t4 = t1;
    cout << "Copied Text: " << t4 << '\n';

    // Copy assignment
    Text t5;
    t5 = t2;
    cout << "Assigned Text: " << t5 << '\n';

    // Comparison
    cout << boolalpha;
    cout << "Equal: " << (t1 == t2) << '\n';
    cout << "Not Equal: " << (t1 != t2) << '\n';

    // Self assignment
    t1 = t1;
    cout << "After Self Assignment: " << t1 << '\n';

    // Empty text
    Text empty;
    cout << "Empty Text: [" << empty << "]\n";

    return 0;
}
