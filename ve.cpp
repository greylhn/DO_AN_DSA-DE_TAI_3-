#include<bits/stdc++.h>
#include"ve.h"
using namespace std ;
ostream& operator<<(ostream& os, const VE &v)
{
    os << "[" << v.SoVe << "-" << v.CMND << "]";
    return os;
}
void xuatDSVe(DSVE ds) {
    for (int i = 0; i < ds.TongVe; i++) {
        cout << "[" << ds.ve[i].SoVe 
             << "-" << ds.ve[i].CMND << "] ";
    }
}
