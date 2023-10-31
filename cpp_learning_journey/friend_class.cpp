#include <iostream>
using namespace std;

class team;

class foot {
    string name;
    int    id;
    friend class team; // friend class declaration
    public: 
    void display()
    {
        cout << "name is " << name << endl << "id value: " << id << endl;
    }
};

 class team {
    public: 
    void setInfo(foot &obj)
    {
        obj.name = "madrid";
        obj.id = 10;
    }
 };

 int main()
 {
    foot obj;
    team obj1;
    obj1.setInfo(obj);
    obj.display();
 }