#include <iostream>
#include <vector>
#include <cstdlib>

using namespace std;


class CQuicksort
{
protected:
    size_t          _iter;
    vector<size_t>  _checkpoint;

    size_t          _i;
    size_t          _j;

    vector<int>     _list;

    void Swap(int& a, int& b);
    void Print();
public:
    void    AddNumber(int num);
    void    ClearNumber();
    void    Sort();
    CQuicksort() { _iter = _i = _j =0;}
};