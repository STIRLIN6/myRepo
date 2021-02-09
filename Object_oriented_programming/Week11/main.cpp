#include <string>

#include "library/maxsearch.hpp"
#include "library/enumerator.hpp"
#include "library/seqinfileenumerator.hpp"
#include "library/counting.hpp"

struct Game
{
    std::string stadium;
    int attendance;
};

std::istream &operator>>(std::istream &is, Game &x)
{
    is >> x.stadium >> x.attendance;
    return is;
}

struct StadiumGames
{
    std::string stadium;
    int games;
};

class GameCounter : public Counting<Game>
{
public:
    GameCounter(const std::string &stadium) : stadium(stadium) {}

    virtual void first() override
    {
    }

    virtual bool cond(const Game &e) const override
    {
        return e.attendance > 50000;
    }

    virtual bool whileCond(const Game &current) const override
    {
        return current.stadium == stadium;
    }

private:
    std::string stadium;
};

class StadiumEnumerator : public Enumerator<StadiumGames>
{
public:
    StadiumEnumerator(const std::string &fname) : f(fname) {}

    void first() override
    {
        f.first();
        next();
    }

    void next() override
    {
        _end = f.end();
        if (_end)
        {
            return;
        }

        curr.stadium = f.current().stadium;

        GameCounter c(f.current().stadium);
        c.addEnumerator(&f);
        c.run();

        curr.games = c.result();
    }

    bool end() const override { return _end; }
    StadiumGames current() const override { return curr; }

private:
    SeqInFileEnumerator<Game> f;
    StadiumGames curr;
    bool _end;
};

class MaxStadium : public MaxSearch<StadiumGames, int>
{
    virtual int func(const StadiumGames &e) const
    {
        return e.games;
    }
};

int main()
{
    try
    {
        MaxStadium x;
        StadiumEnumerator enor("in.txt");
        x.addEnumerator(&enor);
        x.run();

        if (x.found())
        {
            std::cout << x.optElem().stadium << " " << x.opt() << std::endl;
        }
        else
        {
            std::cout << "Empty file!" << std::endl;
        }
    }
    catch (SeqInFileEnumerator<Game>::Exceptions ex)
    {
        std::cout << "File does not exist!" << std::endl;
    }
}