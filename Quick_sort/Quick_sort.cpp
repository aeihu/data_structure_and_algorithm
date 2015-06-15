#include "Quick_sort.h"

void CQuicksort::AddNumber(int num)
{
    _list.push_back(num);
}

void CQuicksort::ClearNumber()
{
    _iter = _i = _j = 0;
    _list.clear();
}

void CQuicksort::Swap(int& a, int& b)
{
    int __tmp = a;
    a = b;
    b = __tmp;
}

void CQuicksort::Print()
{
    for (size_t i=0; i<_list.size(); i++){
        cout << _list[i] << " ";
    }
    cout << endl;
}

void CQuicksort::Sort()
{
    if (_list.size() < 2)
        return;

    while (_iter < _list.size()){
        _i = _iter;
        _j = _checkpoint.size() > 0 ? _checkpoint.back() : _list.size()-1;

        while (_i != _j){
            if (_list[_j] < _list[_iter]){
                if (_list[_i] > _list[_iter]){
                    Swap(_list[_i], _list[_j]);
                    Print();
                }
                else{
                    ++_i;
                }
            }
            else{
                --_j;
            }
        }

        if (_iter == _j){
            ++_iter;
            if (!_checkpoint.empty())
                _checkpoint.pop_back();
        }
        else{
            Swap(_list[_iter], _list[_j]);
            _checkpoint.push_back(_j);
            Print();
        }
    }
}