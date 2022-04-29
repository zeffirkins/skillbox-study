#include <iostream>
#include <fstream>
#include <cstdlib>
#include <string>
#include <vector>
#include <deque>
#include <ctime>
#include <unistd.h>
using namespace std;


const int  FIELD_SIZE = 20;
enum Return{
    RESUME_GAME,
    OK_GAME,
    EXIT_GAME
};

struct Player{
    int x;
    int y;
    char prev;
    string name;
    int health;
    int armor;
    int damage;
    bool alive = true;
};

void AddMessage(deque<string> &message, const string text){
    static unsigned long int number=0;
    ++number;
    if(message.size() >= 10){
        message.pop_front();
        message.push_back(to_string(number)+": " + text);
    }else{
        message.push_back(to_string(number)+": " + text);
    }
}
string PrintMessage(const deque<string> &message){
    string ret("--------------------Message--------------------\n");
    for(int i = 0; i < message.size(); ++i){
        ret+= message[i] + " \n";
    }
    return ret+"---[w][a][s][d] to move, [m] back to the menu--\n";
}

void InitGameBox(char gamebox[][FIELD_SIZE]){
    for(int i = 0; i < FIELD_SIZE; ++i){
        for(int j = 0; j < FIELD_SIZE; ++j){

            gamebox[i][j] = '.';

        }
    }
}

void PrintGameBox(const char gamebox[][FIELD_SIZE], deque<string> &message){
    system("cls");
    for(int n = 0; n < FIELD_SIZE; ++n){
        cout<<n;
        if(n/10 == 0){
            cout<<" ";
        }

    }
    cout<<"\n";
    for(int i = 0; i < FIELD_SIZE; ++i){
        for(int j = 0; j <FIELD_SIZE; ++j){
            cout<<gamebox[i][j]<<" ";
        }
        cout<<i<<"\n";
    }
    cout<<PrintMessage(message);
}

bool OutOfTheArray(Player &enemy, const int x, const int y){
    if((enemy.x < 0 || enemy.x >= FIELD_SIZE) && enemy.x != x){
        enemy.x = x;
        enemy.y = y;
        return true;
    }else if((enemy.y < 0 || enemy.y >= FIELD_SIZE) && enemy.y !=y){
        enemy.x = x;
        enemy.y = y;
        return true;
    }
    return false;
}

bool ThisObstacle(const char gamebox[][FIELD_SIZE], Player &Enemy, const int x, const int y){
    if(Enemy.x != x){
        Enemy.x = x;
        --Enemy.y;
        if(gamebox[Enemy.x][Enemy.y] == 'F' || gamebox[Enemy.x][Enemy.y] == 'E' || gamebox[Enemy.x][Enemy.y] == 'W'|| gamebox[Enemy.x][Enemy.y] == 'A' || gamebox[Enemy.x][Enemy.y] == 'P'){
            Enemy.y = y;
            ++Enemy.y;
        }
        if(gamebox[Enemy.x][Enemy.y] == 'F' || gamebox[Enemy.x][Enemy.y] == 'E' || gamebox[Enemy.x][Enemy.y] == 'W' || gamebox[Enemy.x][Enemy.y] == 'A' || gamebox[Enemy.x][Enemy.y] == 'P'){
            Enemy.y = y;
        }
    }else if(Enemy.y != y){
        Enemy.y = y;
        --Enemy.x;
        if(gamebox[Enemy.x][Enemy.y] == 'F' || gamebox[Enemy.x][Enemy.y] == 'E' || gamebox[Enemy.x][Enemy.y] == 'W' || gamebox[Enemy.x][Enemy.y] == 'A' || gamebox[Enemy.x][Enemy.y] == 'P'){
            Enemy.x = x;
            ++Enemy.x;
        }
        if(gamebox[Enemy.x][Enemy.y] == 'F' || gamebox[Enemy.x][Enemy.y] == 'E' || gamebox[Enemy.x][Enemy.y] == 'W' || gamebox[Enemy.x][Enemy.y] == 'A' || gamebox[Enemy.x][Enemy.y] == 'P'){
            Enemy.x = x;
            return false;
        }
    }
    return true;
}


void DrawingACharacter(char gamebox[][FIELD_SIZE], Player &enemy, const char Draw, const int x, const int y){

    if(Draw == 'F'){
        gamebox[x][y] = Draw;
    }else{
        gamebox[x][y] = enemy.prev;
        enemy.prev = gamebox[enemy.x][enemy.y];
        gamebox[enemy.x][enemy.y] = Draw;
    }
}

bool DealDamage(char gamebox[][FIELD_SIZE], const Player &Enemy, Player &player){
    player.armor -= Enemy.damage;
    if(player.armor < 0){
        player.health += player.armor;
        player.armor = 0;
    }
    if(player.health <= 0){
        gamebox[player.x][player.y] = 'X';
        player.alive = false;

        return true;
    }
    return false;
}

void EngineGame(Player &Enemy, Player &player, char gamebox[][FIELD_SIZE], deque<string> &message){

    if(!player.alive){
        gamebox[player.x][player.y] = 'X';
        return;
    }

    int x = Enemy.x;
    int y = Enemy.y;

    if(Enemy.x > player.x && Enemy.y < player.y ){
        (rand()%2)? --Enemy.x : ++Enemy.y;
    }else if(Enemy.x < player.x && Enemy.y > player.y ){
        (rand()%2)? ++Enemy.x : --Enemy.y;
    }else if((Enemy.x > player.x ) || (Enemy.y > player.y )){
        (rand()%2)? --Enemy.x : --Enemy.y;
    }else if((Enemy.x < player.x ) || (Enemy.y < player.y )){
        (rand()%2)? ++Enemy.x : ++Enemy.y;
    }else{
        (rand()%2)? ++Enemy.x : --Enemy.y;
    }

    if(OutOfTheArray(Enemy, x, y)){
        DrawingACharacter(gamebox, Enemy, 'F', x , y);
        return;
    }

    switch(gamebox[Enemy.x][Enemy.y]){
        case 'E':
        case 'A':
        case 'W':
        case 'F':
            if(ThisObstacle(gamebox, Enemy, x, y)){
                if(OutOfTheArray(Enemy, x, y)){
                    DrawingACharacter(gamebox, Enemy, 'F', x, y);
                }else{
                    DrawingACharacter(gamebox, Enemy, 'E', x, y);
                }
            }else{
                DrawingACharacter(gamebox, Enemy, 'F', x, y);
            }
            break;
        case '.':
            DrawingACharacter(gamebox, Enemy, 'E', x, y);
            break;
        case 'P':
            if(DealDamage(gamebox, Enemy, player)){
                DrawingACharacter(gamebox, Enemy, 'E', x, y);
                AddMessage(message, Enemy.name+" VS "+ player.name + " Demon`s WIN!");
            }else{
                if(ThisObstacle(gamebox, Enemy, x, y)){
                    if(OutOfTheArray(Enemy, x, y)){
                        DrawingACharacter(gamebox, Enemy, 'F', x, y);
                    }else{
                        DrawingACharacter(gamebox, Enemy, 'A', x, y);
                    }
                }else{
                    DrawingACharacter(gamebox, Enemy, 'F', x, y);
                }
                AddMessage(message, Enemy.name+" DAMAGE "+ player.name + " Health: "+to_string(player.health)+" Armor: "+to_string(player.armor));
            }
            break;
        case 'X':
            DrawingACharacter(gamebox, Enemy, 'E', x, y);
            break;
        default:
            DrawingACharacter(gamebox, Enemy, '?', x, y);
            break;
    }
}


void InitEnemy(vector<Player> &enemy){

    for(int i = 0; i < enemy.size(); ++i){

        enemy[i].x = rand()%FIELD_SIZE;
        enemy[i].y = rand()%FIELD_SIZE;
        enemy[i].prev = '.';
        enemy[i].name = "Enemy #" + to_string(i);
        enemy[i].health = rand()%101+50;
        enemy[i].armor = rand()%51;
        enemy[i].damage = rand()%16+15;
        enemy[i].alive = true;
    }
}

void Logo(const string &logo){
    system("cls");
    int count=0;
    for(int i = 0; i < FIELD_SIZE; ++i){
        if(i >= (FIELD_SIZE/2 - logo.length()/2) && i <= (FIELD_SIZE/2 + logo.length()/2)){
            cout<<logo[count];
            cout.flush();
            sleep(1);
            ++count;
        }else{
            cout<<" ";
        }
    }
    cout<<"\n";
}

string GameMenu(Return ret){
    system("cls");
    string answer;
    cout<<"MENU\n";
    cout<<"i - Status Knight\n";
    cout<<"e - Edit Knight\n";
    cout<<((ret == OK_GAME)? "p - Play DungeonKnight\n" : "p - Resume DungeonKnight\n");
    cout<<"l - Load game\n";
    cout<<"s - Save game\n";
    cout<<"q - Exit game\n";
    cout.flush();
    cout<<":>";
    cin>>answer;
    return answer;
}

void StatusKnight(const Player &player){
    system("cls");
    cout<<"[P]\n";
    cout<<"Name:\t"<<player.name<<"\n";
    cout<<"Health:\t"<<player.health<<"\n";
    cout<<"Armor:\t"<<player.armor<<"\n";
    cout<<"Damage:\t"<<player.damage<<"\n";
    cout<<"Alive:\t"<<((player.alive)? "Alive" : "Dead")<<"\n";
    cout.flush();
}

void EditKnight(Player &player){
    system("cls");
    cout<<"[P]\n";
    cout<<"Name:\t"<<player.name<<"\n";
    cout<<"Health:\t"<<player.health<<"\n";
    cout<<"Armor:\t"<<player.armor<<"\n";
    cout<<"Damage:\t"<<player.damage<<"\n";
    cout<<"Alive:\t"<<((player.alive)? "Alive" : "Dead")<<"\n";
    cout.flush();
    string answer;
    cout<<"Enter the name: ";
    cin>>answer;
    player.name = answer;
    cout<<"Enter the health: ";
    cin>>answer;
    player.health = stoi(answer);
    cout<<"Enter the armor: ";
    cin>>answer;
    player.armor = stoi(answer);
    cout<<"Enter the damage: ";
    cin>>answer;
    player.damage = stoi(answer);
    cout<<"Enter the alive [yes] ot [no]: ";
    cin>>answer;
    player.alive = (answer=="yes")? true: false;
}

int SearchEnemy(int x, int y, vector<Player> &enemy){
    int i = 0;
    for(; i < enemy.size(); ++i){
        if(enemy[i].x == x && enemy[i].y == y){
            return i;
        }
    }
    return -1;
}

void CheckingStepPlayer(char gamebox[][FIELD_SIZE], Player &player, vector<Player> &enemy, int x, int y, char turn, deque<string> &message){


    if(OutOfTheArray(player, x, y)){
        DrawingACharacter(gamebox, player, 'F', x , y);
        return;
    }
    switch(gamebox[player.x][player.y]){
        case 'E':
        case 'F':
        case 'A':
        {
            int i = SearchEnemy(player.x, player.y, enemy);
            if(i < 0){
                exit(666);
            }
            if(DealDamage(gamebox, player, enemy[i])){
                DrawingACharacter(gamebox, player, 'P', x, y);
                AddMessage(message, player.name+" VS "+ enemy[i].name + " Player WIN!");
            }else{
                switch(turn){
                    case 'w':
                        ++player.x;
                        break;
                    case 's':
                        --player.x;
                        break;
                    case 'a':
                        ++player.y;
                        break;
                    case 'd':
                        --player.y;
                        break;
                }
                DrawingACharacter(gamebox, player, 'P', x, y);
                AddMessage(message, player.name+" DAMAGE "+ enemy[i].name + " Health: "+to_string(enemy[i].health)+" Armor: "+to_string(enemy[i].armor));
            }
            break;
        }
        case 'X':
            DrawingACharacter(gamebox, player, 'P', x , y);
            break;
        case 'W':
            DrawingACharacter(gamebox, player, 'F', x , y);
            break;
        case '.':
            DrawingACharacter(gamebox, player, 'P', x , y);
            break;
        default:
            DrawingACharacter(gamebox, player, '?', x , y);
            break;
    }
}

Return PlayGameKnight(char gamebox[][FIELD_SIZE], vector<Player> &enemy, Player &player, Return ret, deque<string> &message){
    if(ret != RESUME_GAME){
        InitGameBox(gamebox);
        InitEnemy(enemy);
    }else{
        for(int i = 0; i < enemy.size(); ++i){
            gamebox[enemy[i].x][enemy[i].y] = (enemy[i].alive)? 'E':'X';
        }
    }

    gamebox[player.x][player.y]= 'P';

    string answer;

    while(true){
        for(int x = 0; x < enemy.size() && ret != RESUME_GAME; ++x){
            EngineGame(enemy[x], player, gamebox, message);
            AddMessage(message, "The Demon's move x:"+to_string(enemy[x].x)+" y:"+to_string(enemy[x].y)+" "+enemy[x].name+" Health: "+to_string(enemy[x].health)+" Armor: "+to_string(enemy[x].armor));

            sleep(2);
        }
        if(ret == RESUME_GAME){

        }
        ret = OK_GAME;
        int x = player.x;
        int y = player.y;
        AddMessage(message, "Player's turn "+player.name+" Health: "+to_string(player.health)+" Armor: "+to_string(player.armor));
        PrintGameBox(gamebox, message);
        cin>>answer;
        AddMessage(message,">> "+answer);
        switch(answer[0]){

            case 'w':
                --player.x;
                CheckingStepPlayer(gamebox, player, enemy, x , y, 'w', message);
                break;
            case 's':
                ++player.x;
                CheckingStepPlayer(gamebox, player, enemy, x, y, 's', message);
                break;
            case 'a':
                --player.y;
                CheckingStepPlayer(gamebox, player, enemy, x, y, 'a', message);
                break;
            case 'd':
                ++player.y;
                CheckingStepPlayer(gamebox, player, enemy, x, y, 'd', message);
                break;
            case 'm':
                return RESUME_GAME;

            default:
                AddMessage(message, "Input errors are not excusable, you miss a move! Ha! Ha! Ha!...");
                break;
        }
        PrintGameBox(gamebox, message);
        sleep(2);
    }
    return EXIT_GAME;
}

bool SaveGame(const vector<Player> &enemy, const Player &player, const deque<string> &message){
    ofstream file;

    file.open("C::\\Skillbox\\dungeon.bin", ios::binary);

    if(!file){
        cerr<<"Error save game"<<"\n";
        return false;
    }
    int size = enemy.size();

    file.write((char *) &size, sizeof(size));
    for(int i = 0; i < size; ++i){
        file.write((char *) &enemy[i].x, sizeof(enemy[i].x) );
        file.write((char *) &enemy[i].y, sizeof(enemy[i].x) );
        file.write((char *) &enemy[i].prev, sizeof(enemy[i].prev) );
        int sizes = enemy[i].name.size();
        file.write((char*) &sizes, sizeof(sizes));
        file.write((char*) enemy[i].name.c_str(), enemy[i].name.size());
        file.write((char *) &enemy[i].health, sizeof(enemy[i].health) );
        file.write((char *) &enemy[i].armor, sizeof(enemy[i].armor) );
        file.write((char *) &enemy[i].damage, sizeof(enemy[i].damage) );
        file.write((char *) &enemy[i].alive, sizeof(enemy[i].alive) );
    }
    file.write((char *) &player.x, sizeof(player.x) );
    file.write((char *) &player.y, sizeof(player.y) );
    file.write((char *) &player.prev, sizeof(player.prev) );
    size = player.name.size();
    file.write((char*) &size, sizeof(size));
    file.write((char*) player.name.c_str(), player.name.size());
    file.write((char *) &player.health, sizeof(player.health) );
    file.write((char *) &player.armor, sizeof(player.armor) );
    file.write((char *) &player.damage, sizeof(player.damage) );
    file.write((char *) &player.alive, sizeof(player.alive) );

    size = message.size();
    file.write((char*)&size, sizeof(size));
    for(int i = 0; i < size; ++i){
        int sizes = message[i].size();
        file.write((char *) &sizes, sizeof(sizes));
        file.write((char *) message[i].c_str(), sizes);
    }

    file.close();
    return true;
}

bool LoadeGame(vector<Player> &enemy, Player &player, deque<string> &message){
    ifstream file;

    file.open("C::\\Skillbox\\dungeon.bin", ios::binary);

    if(!file){
        cout<<"Error load game"<<"\n";
        return false;
    }

    int size;
    file.read((char *) &size, sizeof(size));
    for(int i = 0; i < size; ++i){
        file.read((char *) &enemy[i].x, sizeof(enemy[i].x) );
        file.read((char *) &enemy[i].y, sizeof(enemy[i].x) );
        file.read((char *) &enemy[i].prev, sizeof(enemy[i].prev) );
        int sizes;
        file.read((char*) &sizes, sizeof(sizes));
        enemy[i].name.resize(sizes);
        file.read((char*) enemy[i].name.data(), sizes);
        file.read((char *) &enemy[i].health, sizeof(enemy[i].health) );
        file.read((char *) &enemy[i].armor, sizeof(enemy[i].armor) );
        file.read((char *) &enemy[i].damage, sizeof(enemy[i].damage) );
        file.read((char *) &enemy[i].alive, sizeof(enemy[i].alive) );
    }
    file.read((char *) &player.x, sizeof(player.x) );
    file.read((char *) &player.y, sizeof(player.y) );
    file.read((char *) &player.prev, sizeof(player.prev) );
    file.read((char*) &size, sizeof(size));
    player.name.resize(size);
    file.read((char*) player.name.data(), size);
    file.read((char *) &player.health, sizeof(player.health) );
    file.read((char *) &player.armor, sizeof(player.armor) );
    file.read((char *) &player.damage, sizeof(player.damage) );
    file.read((char *) &player.alive, sizeof(player.alive) );

    message.erase(message.begin(), message.end());
    file.read((char*)&size, sizeof(size));
    for(int i = 0; i < size; ++i){
        int sizes;
        string m;
        file.read((char *) &sizes, sizeof(sizes));
        m.resize(sizes);
        file.read((char *) m.data(), sizes);
        message.push_back(m + " *load* ");
    }
    file.close();
    return true;
}

int main() {
    srand(time(0));
    Logo("DungeonKnight");
    Player player{rand()%FIELD_SIZE, rand()%FIELD_SIZE, '.', "Ryuk", 100, 100, 100, true};
    char gamebox[FIELD_SIZE][FIELD_SIZE];
    vector<Player> enemy(5);
    deque<string> message;
    InitGameBox(gamebox);
    string answer;
    Return ret(OK_GAME);
    while(true){
        answer = GameMenu(ret);
        switch(answer[0]){
            case 'i':
                StatusKnight(player);
                sleep(2);
                break;
            case 'e':
                EditKnight(player);
                break;
            case 'p':
                ret =  PlayGameKnight(gamebox, enemy, player, ret, message);

                break;
            case 's':
                if(SaveGame(enemy, player, message)){
                    cout<<"Game saved!"<<"\n";
                }else{
                    cout<<"Game not saved!"<<"\n";
                }
                sleep(2);
                break;
            case 'l':
                if(LoadeGame(enemy, player, message)){
                    InitGameBox(gamebox);
                    cout<<"Game loads, press [p] to resume!"<<"\n";
                    ret = RESUME_GAME;
                }else{
                    cout<<"No saves found, start playing again"<<"\n";
                }
                sleep(2);
                break;
            case 'q':
                cout<<"Exit game"<<"\n";
                exit(0);
            default:
                cout<<"Not correct input."<<"\n";
                break;
        }
    }
}