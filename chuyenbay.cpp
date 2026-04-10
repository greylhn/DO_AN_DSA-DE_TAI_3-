#include<bits/stdc++.h>
#include"chuyenbay.h"
using namespace std ;
//nhap thong tin 1 chuyen bay 
void nhapthongtincb (CHUYENBAY &cb)
{
cout << "--- NHAP THONG TIN CHUYEN BAY ---" << endl;
    
    cout << "Nhap ma chuyen bay: ";
    cin.getline(cb.MaCB, MAXMCB); 

	nhapNgay(cb.NgayGioKH.day , cb.NgayGioKH.month , cb.NgayGioKH.year) ;
	cout << endl ;
	cout << "Nhap gio khoi hanh (hh mm): ";
	cin >> cb.NgayGioKH.hour;
	cin.ignore();
	
	cin >> cb.NgayGioKH.minute;
	cin.ignore(); 


    cout << "Nhap ten san bay den: ";
    cin.getline(cb.SanBayDen, MAXSBD);

    cout << "Nhap so hieu may bay: ";
    cin.getline(cb.SoHieuMB, MAXSHMB);

    cout << "Nhap trang thai (0: Huy, 1: Con ve, 2: Het ve, 3: Hoan): ";
    cin >> cb.TrangThai;
    
    cin.ignore();
    
    cout << "=> Nhap thong tin thanh cong!" << endl;
    cout << "---------------------------------" << endl;
}
//tao node moi cho cb
DSCB makenodeCB ()
{
	DSCB tmp = new NodeCB ;
	nhapthongtincb(tmp->data) ;
	tmp->next = nullptr ;
	return tmp ;
}
// them chuyen bay 
void themCB (DSCB &a)
{
	DSCB tmp = makenodeCB();  

	if (a == nullptr)
	{
		a = tmp;
		return;
	}

	DSCB p = a;
	while (p->next != nullptr)
	{
		p = p->next;
	}
	p->next = tmp;
}
//in 1 chuyen bay 
void inCB (CHUYENBAY cb)
{
cout << "||" << cb.MaCB 
     << "||" << cb.NgayGioKH.hour << ":" << cb.NgayGioKH.minute
     << "||" << cb.NgayGioKH.day 
     << "||" << cb.NgayGioKH.month 
     << "||" << cb.NgayGioKH.year 
     << "||" << cb.TrangThai 
     << "||" << cb.SoHieuMB << "||";

xuatDSVe(cb.dsve); 

cout << endl;}
//danh sach chuyen bay 
void indsCB (DSCB ds)
{
	if (ds == nullptr)
	{
		cout << "Danh sach rong!" << endl;
		return;
	}

	cout << "=====================================================================================\n";
	cout << left 
     << setw(10) << "MaCB"
     << setw(10) << "Gio"
     << setw(15) << "Ngay"
     << setw(12) << "Trang thai"
     << setw(15) << "SoHieuMB"
     << "DSVE\n";
	cout << "=====================================================================================\n";

	DSCB p = ds;
	while (p != nullptr)
	{
		inCB(p->data);   
		cout << endl;
		p = p->next;
	}

	cout << "=====================================================================================\n";
}
//xoa chuyen bay 
void xoaCB (DSCB &a)
{
	if (a == nullptr) return;

	indsCB(a);

	cout << "Nhap so thu tu chuyen bay muon xoa (bat dau tu 1): ";
	int x;
	cin >> x;

	if (x == 1)
	{
		DSCB tmp = a;
		a = a->next;
		delete tmp;
		return;
	}

	DSCB p = a;
	for (int i = 1; i < x - 1 && p->next != nullptr; i++)
	{
		p = p->next;
	}

	if (p->next == nullptr) return;

	DSCB tmp = p->next;
	p->next = tmp->next;
	delete tmp;
}


