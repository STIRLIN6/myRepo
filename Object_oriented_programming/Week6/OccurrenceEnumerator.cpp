#include "OccurrenceEnumerator.hpp"

OccurrenceEnumerator::OccurrenceEnumerator(const std::string &path) : f(path)
{
}

void OccurrenceEnumerator::Read()
{
    if (f >> df)
    {
        sf = norm;
    }
    else
    {
        sf = abnorm;
    }
}

void OccurrenceEnumerator::First()
{
    Read();
    Next();
}

void OccurrenceEnumerator::Next()
{
    end = (sf == abnorm);
    if (end)
        return;

    current.value = df;
    current.occurrence = 1;

    Read();
    while (sf == norm && df == current.value)
    {
        current.occurrence++;
        Read();
    }
}

EnorItem OccurrenceEnumerator::Current() const
{
    return current;
}

bool OccurrenceEnumerator::End() const
{
    return end;
}