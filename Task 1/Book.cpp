
#include <iostream>
#include <stdexcept>
#include <string>
using namespace std;

class Book {
    string title;
    int copies;

    static int valid(int n) {
        if (n < 0)
            throw invalid_argument("Copies cannot be negative");
        return n;
    }

public:
    // Default constructor
    Book() : Book("", 0) {}

    // Parameterized constructor
    explicit Book(string t) : Book(t, 1) {}

    // Overloaded constructor
    Book(string t, int n) : title(t), copies(valid(n)) {}

    // Display book details
    void display() const {
        cout << "Title: "
             << (title.empty() ? "Not assigned" : title)
             << ", Copies: " << copies << '\n';
    }
};

int main() {

    Book empty;
    Book donated("C++ Basics");
    Book full("Object Oriented Programming", 5);

    empty.display();
    donated.display();
    full.display();

    try {
        Book invalid("Invalid Book", -2);
    }
    catch (const invalid_argument& e) {
        cout << e.what() << '\n';
    }

    return 0;
}
