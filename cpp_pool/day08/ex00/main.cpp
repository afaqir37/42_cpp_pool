#include "easyfind.hpp"

int main() {
    std::vector<int> vec;
    vec.push_back(1);
    vec.push_back(2);
    vec.push_back(3);
    vec.push_back(4);

    try {
        int i = *easyfind(vec, 34);
        std::cout << "[std::vector] " << i << std::endl;
    } catch (std::exception& e) {
        std::cout << "[std::vector] element not found" << std::endl;
    }

    try {
        int i = *easyfind(vec, 4);
        std::cout << "[std::vector] " << i << std::endl;
    } catch (std::exception& e) {
        std::cout << "[std::vector] element not found" << std::endl;
    }

    std::list<int> vec2;
    vec2.push_front(1);
    vec2.push_front(2);
    vec2.push_back(3);
    vec2.push_back(4);

    try {
        int i = *easyfind(vec2, 38);
        std::cout << "[std::list] " << i << std::endl;
    } catch (std::exception& e) {
        std::cout << "[std::list] element not found" << std::endl;
    }

    try {
        int i = *easyfind(vec2, 1);
        std::cout << "[std::list] " << i << std::endl;
    } catch (std::exception& e) {
        std::cout << "[std::list] element not found" << std::endl;
    }

    std::deque<int> vec3;
    vec3.push_back(10);
    vec3.push_back(20);
    vec3.push_back(30);
    vec3.push_back(40);

    try {
        int i = *easyfind(vec3, 44);
        std::cout << "[std::deque] " << i << std::endl;
    } catch (std::exception& e) {
        std::cout << "[std::deque] element not found" << std::endl;
    }

    try {
        int i = *easyfind(vec3, 40);
        std::cout << "[std::deque] " << i << std::endl;
    } catch (std::exception& e) {
        std::cout << "[std::deque] element not found" << std::endl;
    }

}