
#include <iostream>
#include <vector>
#include <string>
#include <stdexcept>
using namespace std;

class Time {
    int hours, minutes, seconds;

public:
    Time(int h = 0, int m = 0, int s = 0)
        : hours(h), minutes(m), seconds(s) {}

    // Prefix increment
    Time& operator++() {
        seconds++;

        if (seconds == 60) {
            seconds = 0;
            minutes++;
        }

        if (minutes == 60) {
            minutes = 0;
            hours++;
        }

        return *this;
    }

    // Postfix increment
    Time operator++(int) {
        Time old = *this;
        ++(*this);
        return old;
    }

    // Equality operator
    bool operator==(const Time& t) const {
        return hours == t.hours &&
               minutes == t.minutes &&
               seconds == t.seconds;
    }

    // Less-than operator
    bool operator<(const Time& t) const {
        if (hours != t.hours)
            return hours < t.hours;

        if (minutes != t.minutes)
            return minutes < t.minutes;

        return seconds < t.seconds;
    }

    void display() const {
        cout << (hours < 10 ? "0" : "") << hours << ":"
             << (minutes < 10 ? "0" : "") << minutes << ":"
             << (seconds < 10 ? "0" : "") << seconds;
    }
};

class Playlist {
    vector<string> tracks;

public:
    Playlist(vector<string> t) : tracks(t) {}

    // Non-const subscript operator
    string& operator[](int index) {
        if (index < 0 || index >= (int)tracks.size())
            throw out_of_range("Invalid playlist index");

        return tracks[index];
    }

    // Const subscript operator
    const string& operator[](int index) const {
        if (index < 0 || index >= (int)tracks.size())
            throw out_of_range("Invalid playlist index");

        return tracks[index];
    }

    int size() const {
        return (int)tracks.size();
    }
};

int main() {
    Time t(0, 59, 59);

    Time a = t++;
    Time b = ++t;

    cout << "Postfix value: ";
    a.display();

    cout << "\nPrefix value: ";
    b.display();

    cout << "\nCurrent time: ";
    t.display();

    cout << "\nTime comparison: "
         << boolalpha << (a < b) << '\n';

    cout << "Time equality: " << (a == b) << '\n';

    // Playlist demonstration
    Playlist songs({"Song One", "Song Two", "Song Three"});

    cout << "\nPlaylist:\n";

    for (int i = 0; i < songs.size(); i++) {
        cout << songs[i] << '\n';
    }

    // Modify a track using non-const operator[]
    songs[1] = "Updated Song";
    cout << "Updated track: " << songs[1] << '\n';

    // Invalid index test
    try {
        cout << songs[3];
    }
    catch (const out_of_range& e) {
        cout << e.what() << '\n';
    }

    return 0;
}
