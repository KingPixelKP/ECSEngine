#ifndef ECSDODLEARNING_PAGED_ARRAY_H
#define ECSDODLEARNING_PAGED_ARRAY_H
#include <vector>

#include "entity.h"

#define PAGE_SIZE 4

template <typename T>
class PagedArray {
    public:
    private:
    int get_page_from_index(int index);
    std::array<std::array<T,PAGE_SIZE>, MAX_ENTITIES/PAGE_SIZE> array;
};

#endif //ECSDODLEARNING_PAGED_ARRAY_H