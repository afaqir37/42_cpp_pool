#ifndef _BRAIN_HPP_
#define _BRAIN_HPP_
#include <iostream>

class Brain {
    private:
        std::string ideas[100];
    public:
        Brain();
        Brain(Brain& other);
        Brain& operator=(const Brain& other);
        ~Brain();

        void getIdeas(void);
        void setIdeas(int index, std::string str);
};

#endif