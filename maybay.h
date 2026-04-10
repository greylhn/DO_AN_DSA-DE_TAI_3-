#include<bits/stdc++.h>
#define MAXMB 300
#define MAXSHMB 16
#define MAXLMB 41
struct MAYBAY {
    char SoHieuMB[MAXSHMB];
    char LoaiMB[MAXLMB];
    int SoCho;
};

struct DSMAYBAY {
    int n = 0;
    MAYBAY* mb[MAXMB];
};
int timmaybay (DSMAYBAY &ds , char soHieu[]);
void themmaybay (DSMAYBAY &ds); 
void xoamaybay (DSMAYBAY &ds) ;
void suamaybay (DSMAYBAY &ds) ;
void xuatDSMB (DSMAYBAY &ds) ;