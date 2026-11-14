
#include <iostream>
#include <cmath>
#include <stdexcept>
using namespace std;

class Complex {
    double real;
    double imag;

public:
    // Default constructor
    Complex() : real(0), imag(0) {}

    // Constructor with real part
    Complex(double r) : real(r), imag(0) {}

    // Constructor with real and imaginary parts
    Complex(double r, double i) : real(r), imag(i) {}

    // Addition operator
    Complex operator+(const Complex& c) const {
        return Complex(real + c.real, imag + c.imag);
    }

    // Subtraction operator
    Complex operator-(const Complex& c) const {
        return Complex(real - c.real, imag - c.imag);
    }

    // Multiplication operator
    Complex operator*(const Complex& c) const {
        return Complex(
            real * c.real - imag * c.imag,
            real * c.imag + imag * c.real
        );
    }

    // Division operator
    Complex operator/(const Complex& c) const {
        double denominator = c.real * c.real +
                             c.imag * c.imag;

        if (denominator == 0) {
            throw runtime_error("Division by zero impedance");
        }

        return Complex(
            (real * c.real + imag * c.imag) / denominator,
            (imag * c.real - real * c.imag) / denominator
        );
    }

    // Equality operator
    bool operator==(const Complex& c) const {
        return real == c.real && imag == c.imag;
    }

    // Magnitude
    double magnitude() const {
        return sqrt(real * real + imag * imag);
    }

    // Stream output operator
    friend ostream& operator<<(ostream& out, const Complex& c) {
        out << c.real;

        if (c.imag >= 0)
            out << " + " << c.imag << "j";
        else
            out << " - " << -c.imag << "j";

        return out;
    }
};

int main() {
    try {
        // Series impedance
        Complex resistor(10, 0);
        Complex inductor(0, 5);
        Complex capacitor(0, -2);

        Complex series = resistor + inductor + capacitor;

        cout << "Series Impedance: " << series << '\n';
        cout << "Series Magnitude: "
             << series.magnitude() << '\n';

        // Parallel impedance
        Complex z1(10, 0);
        Complex z2(0, 5);

        Complex parallel = (z1 * z2) / (z1 + z2);

        cout << "\nParallel Impedance: " << parallel << '\n';
        cout << "Parallel Magnitude: "
             << parallel.magnitude() << '\n';

        // Division by zero test
        Complex zero(0, 0);
        Complex result = z1 / zero;

        cout << result << '\n';
    }
    catch (const runtime_error& e) {
        cout << "\nError: " << e.what() << '\n';
    }

    return 0;
}
