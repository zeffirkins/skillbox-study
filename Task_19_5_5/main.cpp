#include <iostream>
#include <fstream>
#include <string>
#include <vector>
using namespace std;

void show_spinner (vector<int>spinner){
    for (int i = 0; i < spinner.size(); i++) {
        if (spinner[i] != 0) cout << spinner[i] << " ";
    }
    cout << "\n";
}

string show_answer(int sector_now){
    string answer;
    string path = "C:\\Skillbox\\game\\answers\\answer" + to_string(sector_now) + ".txt";
    ifstream file;
    file.open(path);
    file >> answer;
    file.close();
    return answer;
}

void show_questions(int sector_now){
    string question;
    string path = "C:\\Skillbox\\game\\questions\\question" + to_string(sector_now) + ".txt";
    ifstream file;
    file.open(path);

    char buff[100];

    while(!file.eof()) {
        file.read(buff, sizeof(buff)-1);
        buff[file.gcount()]=0;
        std::cout<<buff;
    }

    file >> question;
    file.close();
    cout << question;
}

int select_sector(int sector_now, int offset, vector <int> spinner) {
    if (offset > 13) {
        offset %= 13;
    }
    if (sector_now + offset <= 13) {
        sector_now += offset;
        while (spinner[sector_now - 1] == 0) {
            sector_now += 1;
        }
    } else {
        sector_now = sector_now + offset - 13;
        while (spinner[sector_now - 1] == 0) {
            sector_now += 1;
        }
    }
    return sector_now;
}

int main() {
    vector <int> spinner = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13};
    int sector_now = 1;
    int offset = 0, players = 0, viewers = 0;
    string answer, right_answer;

    for (int i = 0; i < spinner.size() && players < 6 && viewers < 6; i++) {
        show_spinner(spinner);
        cout << "Spin spinner to find out the next sector with a question(input offset):";
        cin >> offset;

        sector_now = select_sector(sector_now, offset, spinner);

        cout << "Playing sector " << sector_now << "\n";
        show_questions(sector_now);

        cout << "\nOne minute to think started!\n";
        cout << "Stop! Your answer: ";
        cin >> answer;
        right_answer = show_answer(sector_now);

        if (answer == right_answer) {
            cout << "\nCorrect! Score goes to experts.\n";
            players++;
        }else {
            cout << "Incorrect! Score goes to viewers.\n";
            viewers++;
            cout << "Correct answer:" << show_answer(sector_now) << "\n";
        }
        cout << "Current score: players " << players << " : " << viewers << " viewers.\n";
        spinner[sector_now - 1] = 0;
    }

    if (players == 6) {
        cout << "Congratulations! Experts win with a score " << players << " : " << viewers << "\n";
    }else {
        cout << "Congratulations! TV viewers win with a score " << viewers << " : " << players << "\n";
    }
    cout << "Thanks to all. The game is over.\n";
}