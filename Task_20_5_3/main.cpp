#include <iostream>
#include <fstream>
using namespace std;

int main() {
    cout << "Good morning! Great day for fishing.\n";
    cout << "What fish do you want to catch?";

    string fish;
    int sum_fish = 0;
    cin >> fish;

    ifstream file_river("C:\\Skillbox\\river.txt");
    ofstream file_basket("C:\\Skillbox\\basket.txt", ios::app);

    if(!file_river.is_open()){
        cerr << "Error! file river.txt not open or not found.\n";
        exit(0);
    }

    if(!file_basket.is_open()){
        cerr << "Error! file river.txt not open.\n";
        exit(0);
    }

    string fish_river;
    while(!file_river.eof()){
        file_river >> fish_river;
        if(fish_river == fish){
            ++sum_fish;
            file_basket << fish_river <<"\n";
        }
    }
    file_river.close();
    file_basket.close();

    if(sum_fish){
        cout << "Congratulations! You caught today " << sum_fish << " " << fish << "\n";
    }else{
        cout << "Sorry, but today you didn't catch " << fish << " today." << "\n";
    }
}