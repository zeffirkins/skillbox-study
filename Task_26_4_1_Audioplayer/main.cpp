#include <iostream>
#include <vector>
#include <ctime>
#include <string>
using namespace std;

vector <class Track> Playlist;

class Track {
    public:
        string name;
        string date;
        int duration;
};

class Audioplayer {
    public:
       bool currentPlay = false;
       string nameTrack = "unknown";

       void addPlaylist () {
           Track newTrack;
           cout << "Please enter a name of the track:\n";
           cin >> newTrack.name;
           time_t t = time(nullptr);
           tm today = *localtime (&t);
           newTrack.date = to_string(today.tm_mon) + "/" + to_string(today.tm_mday);
           cout << "Please enter a duration of the track:\n";
           cin >> newTrack.duration;
           Playlist.push_back(newTrack);
       };

       void play () {
           cout << "Please enter a name of the track:\n";
           cin >> nameTrack;
           for (int i = 0; i < Playlist.size(); i++) {
               if (nameTrack == Playlist[i].name) {
                   cout <<"Play\n";
                   currentPlay = true;
               }
           }
           if (!currentPlay) cout << "There is no such kind of track\n";
       };

       void pause () {
           if (currentPlay) cout << "Playback paused\n";
       }

       void next () {
           int currentTrack;
           for (int i = 0; i < Playlist.size(); i++) {
               if (nameTrack == Playlist[i].name) currentTrack = i;
           }
           int newTrack = rand() % (Playlist.size()+1);
           while (newTrack == currentTrack) {
               newTrack = rand() % (Playlist.size()+1);
           }
           nameTrack = Playlist[newTrack].name;
           cout << "Now playing " << nameTrack << "\n";
       };

       void stop () {
           if (currentPlay) {
               currentPlay = false;
               cout << "Playback stopping\n";
           }
       }

};

int main () {
    Audioplayer player;
    string answer;
    cout << "\n---=== Audioplayer ===---\n";
    cout << "First add tracks to the playlist\n";
    cout << "Enter 'n' for stop adding\n";
    do  {
        player.addPlaylist();
        cout << "more(y/n)";
        cin >> answer;
    } while ( answer != "n");

    string action;
    while (action != "exit") {
        cout << "Enter 'play' for play track\n";
        cout << "Enter 'pause' to pause\n";
        cout << "Enter 'next' for change track\n";
        cout << "Enter 'stop' to stop playback\n";
        cout << "Enter 'exit' to exit the program\n";
        cin >> action;
        cout << "=>";

        if (action == "play")  player.play();
        else if (action == "pause") player.pause();
        else if (action == "next")  player.next();
        else if (action == "stop")  player.stop();
        else cout << "Incorrect input! Try again.\n";
    }
    cout << "Goodbye!\n";
}