#include <iostream>
#include <vector>
#include <string>
using namespace std;

enum TaskType {
    None = 0,
    A = 1,
    B = 2,
    C = 3
};

class People {
    string m_name = "unknown";
public:
    string setName (string inName) {
        return m_name = inName;
    }

    string getName() {
        return m_name;
    }
};

class Worker : public People {
    TaskType m_task = None;
public:
    bool isBusy() {
        if(m_task == None){
            return false;
        }
        else return true;
    }

    TaskType setTask(TaskType inTask) {
        return m_task = inTask;
    }

    TaskType getTask() {
        return m_task;
    }

    void addTask (TaskType inTask) {
        if (!isBusy()) setTask(inTask);
    }
};


class Team : public People {
    int m_count = 0;
    vector <Worker> workers;
    int m_id = 0;
    string m_managerName;
public:
    Team (int inId, int inCount) {
        m_id=inId;
        m_count = inCount;
        cout << "Please enter manager name\n";
        cin >> m_managerName;
        for (int i = 0; i < m_count; i++) {
            cout << "Please enter a Worker name\n";
            string temp;
            cin >> temp;
            Worker myWorker;
            myWorker.setName(temp);
            workers.push_back(myWorker);
        }
    }

    bool allIsBusy() {
        for(int i = 0; i < m_count; i++) {
            if (!workers[i].isBusy()) return false;
        }
        return true;
    }

    void giveTask (int inTask) {
        if (!allIsBusy()) {
            inTask = (inTask + m_id) % 3 + 1;
            int stick = 0;
            for (int i = 0 ; i < m_count; i++) {
                if (!workers[i].isBusy()) stick = i;
            }
            if (inTask == 1) workers[stick].setTask(A);
            else if (inTask == 2) workers[stick].setTask(B);
            else if (inTask == 3) workers[stick].setTask(C);
        }
        else cout << "All is busy in that team!";
    }
};

class Head : public People {
public:
    vector <Team> teams;
    int m_amount = 0;
public:

    void addTeam() {
        int inId, inCount;
        cout << "Please enter number of group and amount of employees\n";
        cin >> inId >> inCount;
        Team myTeam = Team(inId, inCount);
        teams.push_back(myTeam);
        m_amount ++;
    }

    void addTask() {
        int control = 0;
        int inAnswer = 0;
        cout << "Please give a number task\n";
        cin >> inAnswer;
        for (int i = 0; i < m_amount; i ++) {
            if (!teams[i].allIsBusy()) {
                teams[i].giveTask(inAnswer);
                break;
            }
            else control ++;
        }
        if(control == m_amount) cout << "All are busy!\n";
    }

    bool isEmpty() {
        for (int i = 0; i < m_amount; i ++) {
            if (!teams[i].allIsBusy()) return true;
        }
        return false;
    }

    int getAmount() {
        return m_amount;
    }
};

int main() {
    cout << "\n---=== Simulator Company ===---\n";
    Head myHead;
    string chef;
    cout << "Please enter a name of Chef" << "\n";
    cin >> chef;
    myHead.setName(chef);
    myHead.addTeam();
    while (myHead.isEmpty()) {
        myHead.addTask();
    }
}