#include "VersenyEnor.hpp"

void VersenyEnor::next() {
    
    if ( !(_end = _tt.End()) ) {
        this->_cur.occurrence = 0;

        _cur.verseny = _tt.Current().verseny;

        for ( ; !_tt.End() && _tt.Current().verseny == _cur.verseny; _tt.Next() ) {
            this->_cur.occurrence++;
        }
    }
}