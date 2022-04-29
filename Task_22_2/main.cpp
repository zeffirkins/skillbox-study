#include <iostream>
#include <vector>
#include <string>
using namespace std;

enum class ConstructType{
    HOUSE,
    GARAGE,
    BARN,
    BATCH
};

enum class RoomType{
    BEDROOM,
    KITCHEN,
    BATHROOM,
    CHILDREN_ROOM,
    LIVING_ROOM,
    CLOSE
};

struct Room{
    RoomType type;
    int area_size;
};

struct Floor{
    vector<Room> room;
};

struct Construction{
    ConstructType type;
    int area_size;
    float witch_floor;
    bool fireplace;
    vector<Floor> floor;
};

string GetTypeConstruction(ConstructType type);
string GetTypeConstruction(RoomType room);

struct Plotofland{
    int id;
    int size_plot;
    vector<Construction> construct;
};
bool AddConstruction(vector<Plotofland> &land, int id, ConstructType type){
    if(id<=0 || land.size()<id){
        cout<<"Invalid plot number"<<"\n";
        return false;
    }
    Construction construction{};
    if(ConstructType::HOUSE == type){
        Floor floor{};
        Room rooms{};
        rooms.area_size = 0;
        rooms.type = RoomType::CLOSE;
        construction.type = ConstructType::HOUSE;
        construction.area_size = 0;
        construction.fireplace = true;
        construction.witch_floor = 0;
        floor.room.push_back(rooms);
        construction.floor.push_back(floor);
    }
    if(ConstructType::BATCH == type){
        construction.fireplace = true;
    }
    construction.type = type;
    construction.area_size = 0;
    land[id-1].construct.push_back(construction);
    return true;
}
bool CreatePlotOfLand(vector<Plotofland> &land, int count){
    if(count<=0){
        cout<<"The number cannot be less than 1"<<"\n";
        return false;
    }
    cout<<"Marking up "<<count<<" new plots with the construction of a House"<<"\n";
    for(int i = 1; i<=count; ++i){
        Plotofland plot{};
        Construction construction{};
        Floor floor{};
        Room rooms{};

        plot.id=i;
        plot.size_plot = 1000;
        rooms.area_size = 0;
        rooms.type = RoomType::CLOSE;
        construction.type = ConstructType::HOUSE;
        construction.area_size = 0;
        construction.fireplace = true;
        construction.witch_floor = 0.0f;
        floor.room.push_back(rooms);
        construction.floor.push_back(floor);
        plot.construct.push_back(construction);
        land.push_back(plot);
        cout<<"On the plot number "<<land[i-1].id<<" added a building "<<GetTypeConstruction(land[i-1].construct[0].type)<<"\n";
    }
    return true;
}

bool EditPlot(vector<Plotofland> &plot, int id){
    id-=1;
    string answer;
    cout<<"[ Plot number "<<plot[id].id <<" editing mode ]"<<"\n";
    cout<<"Enter the plot area :"<<"\n";
    cout<<":> ";
    cin>>plot[id].size_plot;
    for(int i = 0; i < plot[id].construct.size(); ++i){
        switch(plot[id].construct[i].type){
            case ConstructType::HOUSE:
                cout<<"Editing "<<GetTypeConstruction(plot[id].construct[i].type)<<":"<<"\n";
                cout<<"Enter the "<<GetTypeConstruction(plot[id].construct[i].type)<<" area :"<<"\n";
                cout<<":> ";
                cin>>plot[id].construct[i].area_size;
                cout<<"Enter the high floor :"<<"\n";
                cout<<":> ";
                cin>>plot[id].construct[i].witch_floor;
                do{
                    cout<<"Enter installed Fireplace (yes or no):"<<"\n";
                    cout<<":> ";
                    cin >> answer;
                }while(answer != "yes" && answer != "no");
                plot[id].construct[i].fireplace = (answer == "yes");

                cout<<"You have "<<plot[id].construct[i].floor.size()<<" floor, add more? (yes) or (no)"<<"\n";
                cout<<"Enter (del) to delete a floor"<<"\n";
                cout<<":> ";
                cin>> answer;
                if(answer == "yes"){
                    int floors = 0;
                    cout<<"Enter the floor numbers:"<<"\n";
                    cout<<":> ";
                    cin>>floors;
                    for(int floor_col =0; floor_col < floors; ++floor_col){
                        Floor floor{};
                        Room room{};
                        room.type = RoomType::CLOSE;
                        floor.room.push_back(room);
                        plot[id].construct[i].floor.push_back(floor);
                    }
                }else if(answer == "del"){
                    int floors = 0;
                    cout<<"How many floors to delete:"<<"\n";
                    cout<<":> ";
                    cin>>floors;
                    if(floors-plot[id].construct[i].floor.size() <=1){
                        cout<<"Deletion is not possible!"<<"\n";
                    }else{
                        for(int del = 0; del < floors; ++del){
                            plot[id].construct[i].floor.pop_back();
                        }
                        cout<<floors<<" floors removed."<<"\n";
                    }
                }

                for(int j = 0; j < plot[id].construct[i].floor.size(); ++j ){
                    cout<<"Editing floor number "<<j+1<<"\n";
                    cout<<"Do you have "<<plot[id].construct[i].floor[j].room.size()<<" room on the floor, add more? (yes) or (no)"<<"\n";
                    cout<<"Enter (del) to delete a room"<<"\n";
                    cin >> answer;

                    if(answer == "yes"){
                        int rooms = 0;
                        cout<<"Enter the rooms numbers:"<<"\n";
                        cout<<":> ";
                        cin>>rooms;
                        for(int rooms_col =0; rooms_col < rooms; ++rooms_col){
                            Room room{};
                            room.type = RoomType::CLOSE;
                            plot[id].construct[i].floor[j].room.push_back(room);
                        }
                    }else if(answer == "del"){
                        int rooms = 0;
                        cout<<"How many rooms to delete:"<<"\n";
                        cout<<":> ";
                        cin>>rooms;
                        if(rooms-plot[id].construct[i].floor[j].room.size() <=1){
                            cout<<"Deletion is not possible!"<<"\n";
                        }else{
                            for(int del = 0; del < rooms; ++del){
                                plot[id].construct[i].floor[j].room.pop_back();
                            }
                            cout<<rooms<<" rooms removed."<<"\n";
                        }
                    }

                    for(int k = 0; k < plot[id].construct[i].floor[j].room.size(); ++k){

                        int ans;
                        cout<<"Editing room number "<<k+1<<"\n";
                        do {
                            cout << "Enter the room type:" << "\n";
                            cout
                                    << "(0) - BEDROOM, (1) - KITCHEN, (2) BATHROOM, (3) - CHILDREN ROOM, (4) - LIVING ROOM"
                                    << "\n";
                            cout << ":> ";
                            cin >> ans;
                        }while(ans < 0 || ans >4);
                        plot[id].construct[i].floor[j].room[k].type = static_cast<RoomType> (ans);
                        cout<<"Enter the size of the room"<<"\n";
                        cout<<":> ";
                        cin>>plot[id].construct[i].floor[j].room[k].area_size;
                    }
                }
                break;
            case ConstructType::BATCH:
                cout<<"Editing "<<GetTypeConstruction(plot[id].construct[i].type)<<":"<<"\n";
                cout<<"Enter the "<<GetTypeConstruction(plot[id].construct[i].type)<<" area :"<<"\n";
                cout<<":> ";
                cin>>plot[id].construct[i].area_size;
                do{
                    cout<<"Enter installed Fireplace (yes or no):"<<"\n";
                    cout<<":> ";
                    cin >> answer;
                }while(answer != "yes" && answer != "no");
                plot[id].construct[i].fireplace = (answer == "yes");
                break;
            case ConstructType::GARAGE:
            case ConstructType::BARN:
                cout<<"Editing "<<GetTypeConstruction(plot[id].construct[i].type)<<":"<<"\n";
                cout<<"Enter the "<<GetTypeConstruction(plot[id].construct[i].type)<<" area :"<<"\n";
                cout<<":> ";
                cin>>plot[id].construct[i].area_size;
                break;
            default:
                cout<<"Error construction type"<<"\n";
                break;
        }

    }
    cout<<"Editing completed successful!"<<"\n";
    cout<<"-------------------------------------"<<"\n";
    return true;

}

string SizeToString(int size){
    return (size >0)? to_string(size):"not set";
}
string SizeToString(float size){
    return (size >0)? to_string(size):"not set";
}

bool InfoPlot(const vector<Plotofland> &plot, int id){
    if(id<=0 || plot.size()<id){
        cout<<"Invalid plot number"<<"\n";
        return false;
    }

    cout<<"\nInformation about the plot number: "<<id<<"\n";
    cout<<"Plot area: "<<SizeToString(plot[id-1].size_plot)<<"\n";
    cout<<"Number of buildings: "<<SizeToString(static_cast<int>(plot[id-1].construct.size()))<<"\n";
    for(int i =0; i < plot[id-1].construct.size(); ++i){
        cout<<"\t"<<GetTypeConstruction(plot[id-1].construct[i].type)<<":"<<"\n";
        switch(plot[id-1].construct[i].type) {
            case ConstructType::HOUSE:
                cout << "\tThe area: " << SizeToString(plot[id - 1].construct[i].area_size) << "\n";
                cout << "\tNumber of floors: " << SizeToString(static_cast<int>(plot[id - 1].construct[i].floor.size())) << "\n";
                cout << "\tHeight of floors: " << SizeToString(plot[id - 1].construct[i].witch_floor) << "\n";
                cout << "\tFireplace: " << (plot[id - 1].construct[i].fireplace ? "installed" : "is not installed") << "\n";

                for(int j =0; j < plot[id - 1].construct[i].floor.size(); ++j){
                    cout<<"\t\tFloor number "<<j+1<<"\n";
                    cout << "\t\tNumber of rooms per floor: " << plot[id - 1].construct[i].floor[j].room.size()<< "\n";
                    for(int k = 0; k < plot[id-1].construct[i].floor[j].room.size(); ++k){
                        cout<<"\t\t\t"<<GetTypeConstruction(plot[id-1].construct[i].floor[j].room[k].type)<<"\n";
                        cout<<"\t\t\tRoom size: "<<SizeToString(plot[id-1].construct[i].floor[j].room[k].area_size)<<"\n";
                    }

                }

                break;
            case ConstructType::BATCH:
                cout << "\tThe area: " << SizeToString(plot[id - 1].construct[i].area_size) << "\n";
                cout << "\tFireplace: " << (plot[id - 1].construct[i].fireplace ? "installed" : "is not installed") << "\n";
                break;
            case ConstructType::GARAGE:
            case ConstructType::BARN:
                cout << "\tThe area: " << SizeToString(plot[id - 1].construct[i].area_size) << "\n";
                break;
            default:
                cout<<"Error"<<"\n";
                break;
        }

    }
    cout<<"-------------------------------------"<<"\n";

    return true;
}

float TotalOFLand(vector<Plotofland> &land){
    float total_land = 0;
    float total_plot = 0;

    for(int i = 0; i < land.size(); ++i){
        total_land+=land[i].size_plot;
        for(int j = 0; j < land[i].construct.size(); ++j){
            total_plot+=land[i].construct[j].area_size;
        }
    }

    return static_cast<float> (total_plot/total_land * 100);
}

void PrintMenu(vector<Plotofland> &land){
    cout<<"\n\t[ Information ]\n";
    cout<<"Percentage of land occupied by buildings to the total area of the entire village "<<TotalOFLand(land)<<" %"<<"\n";
    cout<<"\n\t[ Menu ]\n";
    cout<<"info - Plot information"<<"\n";
    cout<<"add  - Add a building to the plot"<<"\n";
    cout<<"edit - Edit objects on a plot"<<"\n";
    cout<<"q - enter to exit"<<"\n";
    cout<<":> ";
}

bool firePlace(vector<Plotofland> &land, int id, bool add){

    if(id<=0 || land.size()<id){
        cout<<"Invalid plot number"<<"\n";
        return false;
    }

    if(land[id-1].construct[0].type == ConstructType::HOUSE || land[id-1].construct[0].type ==ConstructType::BATCH){
        land[id-1].construct[0].fireplace = add;
        return true;
    }
    return false;
}

int main() {

    int size_land = 0;
    vector<Plotofland> land;
    do{
        cout<<"Enter the number of sections to mark up:\n";
        cout<<":> ";
        cin >> size_land;

    }while(!CreatePlotOfLand(land, size_land));

    string answer;
    do{

        PrintMenu(land);
        cin>>answer;
        if(answer == "info"){
            int number;
            cout<<"Enter the plot number from 1 to "<<land.size()<<": \n";
            cout<<":> ";
            cin>>number;
            InfoPlot(land, number);
        }else if(answer == "add"){
            int number, construct;
            cout<<"Enter the plot number: \n";
            cout<<":> ";
            cin>>number;
            cout<<"Select construction type:\n";
            cout<<"(0) - HOUSE, (1) - GARAGE, (2) - BARN, (3) - BATCH"<<"\n";
            cout<<":> ";
            cin>>construct;

            if(construct < 0 || construct > 3){
                cout<<"Error number construction type"<<"\n";
                continue;
            }

            if(AddConstruction(land, number, static_cast<ConstructType> (construct))){
                cout<<"Built successfully"<<"\n";
            } else{
                cout<<"Build error"<<"\n";
            }
        }else if(answer == "edit"){
            int number;
            cout<<"Enter the plot number from 1 to "<<land.size()<<": \n";
            cout<<":> ";
            cin>>number;
            if(InfoPlot(land, number)){
                EditPlot(land, number);
            }

        }else if(answer == "q"){
            cout<<"Program exit"<<"\n";
        }else{
            cout<<"Unknown parameter"<<"\n";
        }
    }while(answer!="q");

    return 0;
}

string GetTypeConstruction(RoomType room){
    string name;
    switch (room) {
        case RoomType::BEDROOM:
            name = "Bedroom";
            break;
        case RoomType::KITCHEN:
            name = "Kitchen";
            break;
        case RoomType::BATHROOM:
            name = "Bathroom";
            break;
        case RoomType::CHILDREN_ROOM:
            name = "Children room";
            break;
        case RoomType::LIVING_ROOM:
            name = "Living room";
            break;
        case RoomType::CLOSE:
            name = "Room type not specified";
            break;
        default:
            name = "Invalid room type";
            break;
    }
    return name;
}

string GetTypeConstruction(ConstructType type){
    string name;
    switch (type) {
        case ConstructType::HOUSE:
            name = "House";
            break;
        case ConstructType::GARAGE:
            name = "Garage";
            break;
        case ConstructType::BARN:
            name = "Barn";
            break;
        case ConstructType::BATCH:
            name = "Batch";
            break;
        default:
            name = "Invalid building type";
            break;
    }
    return name;
}