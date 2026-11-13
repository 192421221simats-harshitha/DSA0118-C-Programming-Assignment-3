
#include <iostream>
#include <iomanip>
using namespace std;

class Money {
    long long paise;

public:
    // Parameterized constructor
    Money(long long rupees = 0, int p = 0)
        : paise(rupees * 100 + p) {}

    // Overload + operator
    Money operator+(const Money& other) const {
        Money result;
        result.paise = paise + other.paise;
        return result;
    }

    // Overload - operator
    Money operator-(const Money& other) const {
        Money result;
        result.paise = paise - other.paise;
        return result;
    }

    // Overload += operator
    Money& operator+=(const Money& other) {
        paise += other.paise;
        return *this;
    }

    // Overload == operator
    bool operator==(const Money& other) const {
        return paise == other.paise;
    }

    // Overload < operator
    bool operator<(const Money& other) const {
        return paise < other.paise;
    }

    // Overload << operator
    friend ostream& operator<<(ostream& out, const Money& m) {
        long long amount = m.paise;
        if (amount < 0) {
            out << "-Rs " << -amount / 100 << "."
                << setw(2) << setfill('0') << -amount % 100;
        } else {
            out << "Rs " << amount / 100 << "."
                << setw(2) << setfill('0') << amount % 100;
        }
        return out;
    }

    // Overload >> operator
    friend istream& operator>>(istream& in, Money& m) {
        long long rupees;
        int p;
        if (in >> rupees >> p) {
            m.paise = rupees * 100 + p;
        }
        return in;
    }
};

int main() {
    Money a(120, 75);
    Money b(79, 25);

    Money c = a + b;

    cout << "Addition: " << c << '\n';

    Money d = a - b;
    cout << "Subtraction: " << d << '\n';

    a += b;
    cout << "After += : " << a << '\n';

    cout << boolalpha;
    cout << "Equal: " << (a == c) << '\n';
    cout << "Less: " << (b < c) << '\n';

    Money x(0, 75);
    Money y(0, 50);
    cout << "Paise carry test: " << x + y << '\n';

    return 0;
}
