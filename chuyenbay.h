#include<iostream>
#include<string>
#include "Datetime.h"
#include"ve.h"
#define MAXMCB 16
#define MAXSBD 50
#define MAXSHMB 16
using namespace std ;
struct CHUYENBAY {
    char MaCB[MAXMCB];
    DateTime NgayGioKH;
    char SanBayDen[MAXSBD];
    int TrangThai; // 0  
    char SoHieuMB[MAXSHMB];
    DSVE dsve;
};
// chi quan tam den chuyen bay nay va ke tiep
struct NoCB {
    CHUYENBAY data;
    NoCB* next;
};
typedef NoCB* NodeCB;
struct listCB 
{
	NodeCB head ;
	NodeCB tail ;
	int soLuongCB ;
};
NodeCB makeNodeCB (CHUYENBAY a);
void insert_order (listCB &ls , CHUYENBAY a);
void load_file_dscb (listCB &ls) ;
void save_file_dscb(listCB &ls) ;
NodeCB check_maCB (listCB ls, string ma) ;
void themCB (listCB &ls) ;
void chinh_Datetime (listCB &ls) ;
void huyCB (listCB &ls) ;
void in_danh_sach_cb(listCB ls) ;
