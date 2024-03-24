#include "Serializer.hpp"

int main() {
    Data data;
    data.s1 = "Hello";
    data.n = 42;
    data.s2 = "World";

    uintptr_t raw = Serializer::serialize(&data);
    Data *data_ptr = Serializer::deserialize(raw);

    std::cout << data_ptr->s1 << std::endl;
    std::cout << data_ptr->n << std::endl;
    std::cout << data_ptr->s2 << std::endl;

    return 0;
}