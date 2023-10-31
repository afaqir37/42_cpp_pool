#include <iostream>
#include <string>
using namespace std;

class music;

class artist {
    char aname[20] = "hello";
    friend class music;
};

class music {
    char song[20];
    artist a;
    public:
        void setData()
        {
            strcpy(a.aname, "houssam");
            strcpy(song, "nossa");
        }
};

int main()
{
    artist fouad;
    cout << fouad.aname;

}