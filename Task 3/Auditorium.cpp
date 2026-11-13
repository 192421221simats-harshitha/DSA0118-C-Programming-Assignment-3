
#include <iostream>
#include <string>
using namespace std;

class Auditorium {
    string eventName;
    int rows;
    int seats;
    char** seatMap;

public:
    // Dynamic constructor
    Auditorium(string name, int r, int s)
        : eventName(name), rows(r), seats(s), seatMap(nullptr) {

        if (rows > 0 && seats > 0) {
            seatMap = new char*[rows];

            for (int i = 0; i < rows; i++) {
                seatMap[i] = new char[seats];

                for (int j = 0; j < seats; j++) {
                    seatMap[i][j] = 'O';
                }
            }
        }

        cout << "Event created: " << eventName << '\n';
    }

    // Book a seat
    void bookSeat(int r, int s) {
        if (r < 0 || r >= rows || s < 0 || s >= seats) {
            cout << "Invalid seat position\n";
        }
        else if (seatMap[r][s] == 'X') {
            cout << "Seat already booked\n";
        }
        else {
            seatMap[r][s] = 'X';
            cout << "Seat booked successfully\n";
        }
    }

    // Cancel a seat
    void cancelSeat(int r, int s) {
        if (r < 0 || r >= rows || s < 0 || s >= seats) {
            cout << "Invalid seat position\n";
        }
        else if (seatMap[r][s] == 'O') {
            cout << "Seat is not booked\n";
        }
        else {
            seatMap[r][s] = 'O';
            cout << "Booking cancelled successfully\n";
        }
    }

    // Display seat map
    void display() const {
        cout << "\nSeat Map of " << eventName << ":\n";

        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < seats; j++) {
                cout << seatMap[i][j] << " ";
            }
            cout << '\n';
        }
    }

    // Destructor
    ~Auditorium() {
        int booked = 0;

        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < seats; j++) {
                if (seatMap[i][j] == 'X') {
                    booked++;
                }
            }
            delete[] seatMap[i];
        }

        delete[] seatMap;

        cout << "Event closed: " << eventName
             << " | Booked seats: " << booked << '\n';
    }
};

int main() {
    // Stack object
    Auditorium event1("College Fest", 2, 3);
    event1.bookSeat(0, 1);
    event1.bookSeat(1, 2);
    event1.display();

    // Heap object
    Auditorium* event2 = new Auditorium("Music Show", 2, 2);
    event2->bookSeat(0, 0);
    event2->display();
    delete event2;

    // Block-scope object
    {
        Auditorium event3("Workshop", 1, 3);
        event3.bookSeat(0, 2);
        event3.cancelSeat(0, 2);
        event3.display();
    }

    cout << "\nProgram ended\n";

    return 0;
}
