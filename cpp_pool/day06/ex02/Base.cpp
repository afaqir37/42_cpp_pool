#include "Base.hpp"

Base::~Base() {}

Base* generate(void) {
    static int random = 0;
    random++;
    random %= 3;
    if (random == 0) {
        std::cout << "A generated" << std::endl;
        return new A();
    } else if (random == 1) {
        std::cout << "B generated" << std::endl;
        return new B();
    } else {
        std::cout << "C generated" << std::endl;
        return new C();
    }
}

void identify(Base *p) {
    if (dynamic_cast<A*>(p)) {
        std::cout << "A" << std::endl;
    } else if (dynamic_cast<B*>(p)) {
        std::cout << "B" << std::endl;
    } else if (dynamic_cast<C*>(p)) {
        std::cout << "C" << std::endl;
    } else {
        std::cout << "Unknown" << std::endl;
    }
}

void identify(Base &p) {
    try {
        A &a = dynamic_cast<A&>(p);
        (void)a;
        std::cout << "A" << std::endl;
    } catch (std::exception &e) {
        try {
            B &b = dynamic_cast<B&>(p);
            (void)b;
            std::cout << "B" << std::endl;
        } catch (std::exception &e) {
            try {
                C &c = dynamic_cast<C&>(p);
                (void)c;
                std::cout << "C" << std::endl;
            } catch (std::exception &e) {
                std::cout << "Unknown" << std::endl;
            }
        }
    }
}