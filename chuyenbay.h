#include<bits/stdc++.h>
#include "Datetime.h"
#include"ve.h"
#define MAXMCB 16
#define MAXSBD 50
#define MAXSHMB 16
struct CHUYENBAY {
    char MaCB[MAXMCB];
    DateTime NgayGioKH;
    char SanBayDen[MAXSBD];
    int TrangThai; 
    char SoHieuMB[MAXSHMB];
    DSVE dsve;
};

struct NodeCB {
    CHUYENBAY data;
    NodeCB* next;
};
typedef NodeCB* DSCB;
void themCB (DSCB &a) ;
void inCB (CHUYENBAY cb);
void indsCB (DSCB ds) ;
void xoaCB (DSCB &a) ;

