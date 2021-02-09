#include "PrQueue.hpp"

int PrQueue::GetMaxItemIndex () const
{
    if (IsEmpty()) {
        throw EMPTY;
    }

    int maxIndex = 0;
    int maxPriority = items[maxIndex].priority;
    for (unsigned int i = 1; i < items.size(); ++i) {
        if (items[i].priority > maxPriority) {
            maxPriority = items[i].priority;
            maxIndex = i;
        }
    }
    return maxIndex;
}

bool PrQueue::IsEmpty () const 
{
    return items.empty ();
}

std::string PrQueue::Top () const
{
    int maxIndex = GetMaxItemIndex ();
    return items[maxIndex].value;
}

void PrQueue::Pop ()
{
    int maxIndex = GetMaxItemIndex ();
    items.erase(items.begin() + maxIndex);
}

void PrQueue::Push (int priority, std::string value)
{
    items.push_back ({priority, value});
}
