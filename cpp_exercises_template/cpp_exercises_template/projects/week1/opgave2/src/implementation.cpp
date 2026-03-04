#include "implementation.h"
#include <algorithm>

bool implementation::isEmpty() const
{
    return vector.empty();
}

int implementation::size()
{
    return vector.size();
}

void implementation::insert(const int x)
{
    vector.push_back(x);
}

const int implementation::findMax() const
{
    int max = 0;
        for (auto itr = vector.begin(); itr != vector.end(); ++itr) {
        if (max < *itr)
        max = *itr;
    }
    return max;
}

int implementation::deleteMax()
{
    int max = 0;
    std::vector<int>::iterator iterator_;

    for (auto itr = vector.begin(); itr != vector.end(); ++itr) {
        if (max < *itr)
        max = *itr;
        iterator_ = itr;
    }

    vector.erase(iterator_);

    return max;
}
