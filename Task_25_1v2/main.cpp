#include <iostream>
#include <fstream>
#include <ctime>
#include <iomanip>

struct Project
{
  std::string name = "unknown";
  std::time_t open;
  std::time_t close;
  float hours = 0;
};

void finish(Project& a)
{
  if (a.name != "unknown")
  {
    a.close = std::time (nullptr);
    a.hours = (a.close - a.open);
    std::ofstream file ("saving.txt",std::ios::app);
    file << a.name << " " << a.hours << std::endl;
    file.close();
  } else
  {
    std::cout << "There is no open task, please enter command again" << std::endl;
  }

};

void begin(Project& a)
{
  if (a.name == "unknown")
  {
    std::cout << "Please enter a name of task" <<std::endl;
    std::cin >> a.name;
    a.open = std::time (nullptr);
  }
  else
  {
    finish(a);
    std::cout << " There is open task, please enter a command again" <<std::endl;
  }
};

void overview()
{
  std::string buffer;
  int temp;
  std::ifstream file ("saving.txt");
  while (!file.eof())
  {
    file >> buffer;
    file >> temp;
    std::cout << "Project name " << buffer <<std::endl;
    std::cout<< buffer << " length " << temp << " hours" << std::endl;
  }

};



int main() {
  std::string command;
  std::time_t start, end;
  Project IT;
  while (command != "exit")
  {
    std::cout << "What you want to do?" << std::endl;
    std::cout << "To start a project enter -> begin" << std::endl;
    std::cout << "To close a current project enter -> end" << std::endl;
    std::cout << "To see current overview of closed tasks enter -> status" << std::endl;
    std::cin >> command;
    if (command == "begin") begin (IT);
    else if (command == "end") finish(IT);
    else if (command == "status") overview();
    else if (command != "exit") std::cout << "Error";
  }
}