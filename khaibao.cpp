#include <iostream>
#include <cstring>
#include <iomanip>
using namespace std;

#define MAXMB 300


struct DateTime {
    int day, month, year;
    int hour, minute;
};


struct MAYBAY {
    char SoHieuMB[16];
    char LoaiMB[41];
    int SoCho;
};

struct DSMAYBAY {
    int n = 0;
    MAYBAY* mb[MAXMB];
};


struct VE {
    int SoVe;
    char CMND[13];
};


struct DSVE {
    int TongVe;
    VE* ve;
};


struct CHUYENBAY {
    char MaCB[16];
    DateTime NgayGioKH;
    char SanBayDen[50];
    int TrangThai; 
    char SoHieuMB[16];
    DSVE dsve;
};

struct NodeCB {
    CHUYENBAY data;
    NodeCB* next;
};
typedef NodeCB* DSCB;


struct HANHKHACH {
    char CMND[13];
    char Ho[30];
    char Ten[20];
    char Phai[5];
};

struct NodeHK {
    HANHKHACH data;
    NodeHK* left;
    NodeHK* right;
};
typedef NodeHK* TREE_HK;
int main() {
    DSMAYBAY dsmb;         
    dsmb.n = 0;

    DSCB dscb = NULL;      

    TREE_HK hk = NULL;    

    return 0;
}
