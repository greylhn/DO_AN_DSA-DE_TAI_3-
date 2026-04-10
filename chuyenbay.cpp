#include<bits/stdc++.h>
#include"chuyenbay.h"
using namespace std ;
//nhap thong tin 1 chuyen bay 
void nhapthongtincb (CHUYENBAY &cb)
{
cout << "--- NHAP THONG TIN CHUYEN BAY ---" << endl;
    
    cout << "Nhap ma chuyen bay: ";
    cin.getline(cb.MaCB, MAXMCB); 

    cout << "Nhap ngay khoi hanh (dd mm yyyy): ";
    cin >> cb.NgayGioKH.day >> cb.NgayGioKH.month >> cb.NgayGioKH.year;

    cout << "Nhap gio khoi hanh (hh mm): ";
    cin >> cb.NgayGioKH.hour >> cb.NgayGioKH.minute;

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
void makenodeCB ()
{
	DSCB tmp = new CHUYENBAY ;
	tmp->data = nhapthongtincb(tmp) ;
	tmp->next = nullptr ;
	return tmp ;
}
// them chuyen bay 
void themCB (DSCB &a)
{
	DSCB tmp ;
	if (a==nullptr)
	{
		a = tmp ;
		return ;
	}
	DSCB p = a ;
	while (p->next != nullptr)
	{
		p = p->next ;
	}
	p->next = tmp ;
}
//xoa chuyen bay 
void xoaCB (DSCB &a)
{
	
}
