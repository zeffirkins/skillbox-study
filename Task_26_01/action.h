using namespace std;
struct point
{
    double x;
    double y;
};

void scalpel (point& start, point& finish){
    cout << "Enter X and Y of start point:";
    cin >> start.x >> start.y;
    cout << "Enter X and Y of finish point:";
    cin >> finish.x >> finish.y;
    cout << "You make cut with start in X:" << start.x << "/Y:" << start.y
            << " and finish in X:" << finish.x << "/Y:" << finish.y << "\n";
}

void hemostat (point& start) {
    cout << "Enter coordinate point where you want use clamp.\n";
    cout << "Enter X point:";
    cin >> start.x;
    cout << "Enter Y point:";
    cin >> start.y;
    cout << "You use clamp in point X:" <<start.x << "/Y:" << start.y << "\n";
}

void tweezers (point& start) {
    cout << "Enter coordinate point where you want use take tweezers.\n";
    cout << "Enter X point:";
    cin >> start.x;
    cout << "Enter Y point:";
    cin >> start.y;
    cout << "You use tweezers in point X:" << start.x << "/Y:" << start.y << "\n";
}

void suture (point& start, point& finish){
    cout << "Suture means what you want finish operation.\n";
    cout << "Enter X and Y of start point:";
    cin >> start.x >> start.y;
    cout << "Enter X and Y of finish point:";
    cin >> finish.x >> finish.y;
    cout << "You make suture with start in X:" << start.x << "/Y:" << start.y
         << " and finish in X:" << finish.x << "/Y:" << finish.y << "\n";
}