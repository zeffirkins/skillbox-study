#include <iostream>
using namespace std;

enum piano_key {
    DO = 1 << 0,
    RE = 1 << 1,
    MI = 1 << 2,
    FA = 1 << 3,
    SOL = 1 << 4,
    LA = 1 << 5,
    SI = 1 << 6
};

void playMusic (int note) {
    int sound = 1 << note;

    if (sound & DO) cout << "DO ";
    else if (sound & RE) cout << "RE ";
    else if (sound & MI) cout << "MI ";
    else if (sound & FA) cout << "FA ";
    else if (sound & SOL) cout << "SOL ";
    else if (sound & LA) cout << "LA ";
    else if (sound & SI) cout << "SI ";
}

int main() {
    const int combNotes = 12;
    string combination;
    string melody;

    for (int i = 1; i <= combNotes; ++i) {
        cout << "Input " << i << " combination of notes from " << combNotes << ": ";
        getline(cin, combination);
        melody += combination;
    }

    int i = 0;
    while ((i < melody.length())) {
        playMusic(melody[i] - '1');
        i++;
        if ((melody[i] - '0') < 1 || (melody[i] - '0') > 7)
            cout << "* ";
    }
}