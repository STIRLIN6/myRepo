#pragma once

#include <fstream>
#include <string>

struct EnorItem
{
    int value;
    int occurrence;
};

class OccurrenceEnumerator
{
public:
    OccurrenceEnumerator(const std::string &path);

    void First();
    void Next();

    EnorItem Current() const;
    bool End() const;

private:
    void Read();

    enum Status
    {
        abnorm,
        norm
    };

    std::ifstream f;
    Status sf;
    int df;

    bool end;
    EnorItem current;
};