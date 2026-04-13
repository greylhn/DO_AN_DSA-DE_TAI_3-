#include<iostream>
#include<fstream>
#include<string>
#include<cstring>
#include<iomanip>
#include"chuyenbay.h"
using namespace std;

NodeCB makeNodeCB(CHUYENBAY a) {
    NodeCB tmp = new NoCB;
    if (tmp == nullptr) return nullptr;
    tmp->data = a;
    tmp->next = nullptr;
    return tmp;
}
// chen co thu tu theo ma chuyen bay
void insert_order(listCB &ls, CHUYENBAY a) {
    NodeCB newNode = makeNodeCB(a);
//    neu danh sach rong hoac maCB cua a nho hon head
    if (ls.head == nullptr || strcmp(a.MaCB, ls.head->data.MaCB) < 0) {
        newNode->next = ls.head;
        ls.head = newNode;
        if (ls.tail == nullptr) ls.tail = newNode; 
    }
//	neu maCB kh nam o dau  
	else {
        NodeCB p = ls.head;
        NodeCB pre = nullptr;
//        tim den khi thay macb lon hon 
        while (p != nullptr && strcmp(p->data.MaCB, a.MaCB) < 0) {
            pre = p;
            p = p->next;
        }
//        chen node moi vao giua
        newNode->next = p;
        pre->next = newNode;
//        cap nhat neu p la node cuoi 
        if (p == nullptr) ls.tail = newNode;
    }
    ls.soLuongCB++;
}
//luu file 
void save_file_dscb(listCB &ls) {
    ofstream ofs("chuyenbay.txt", ios::out);
    if (!ofs.is_open()) { cout << "Khong the mo file!\n"; return; }
    NodeCB p = ls.head;
    while (p != nullptr) {
        ofs << p->data.MaCB << "\n"
            << p->data.NgayGioKH.hour << " "
            << p->data.NgayGioKH.minute << " "
            << p->data.NgayGioKH.day << " "
            << p->data.NgayGioKH.month << " "
            << p->data.NgayGioKH.year << "\n"
            << p->data.SanBayDen << "\n"
            << p->data.TrangThai << "\n"
            << p->data.SoHieuMB << "\n";
        p = p->next;
    }
    ofs.close();
    cout << "Da luu file thanh cong!\n";
}

void load_file_dscb(listCB &ls) {
	ls.head = nullptr;      
    ls.tail = nullptr;     
    ls.soLuongCB = 0;       

    ifstream ifs("chuyenbay.txt", ios::in);
    if (!ifs.is_open()) { cout << "Khong tim thay file!\n"; return; }
    while (ifs.peek() != EOF) {
        CHUYENBAY tmp;
        ifs.getline(tmp.MaCB, MAXMCB);
        ifs >> tmp.NgayGioKH.hour >> tmp.NgayGioKH.minute
            >> tmp.NgayGioKH.day >> tmp.NgayGioKH.month >> tmp.NgayGioKH.year;
        ifs.ignore();
        ifs.getline(tmp.SanBayDen, MAXSBD);
        ifs >> tmp.TrangThai;
        ifs.ignore();
        ifs.getline(tmp.SoHieuMB, MAXSHMB);
        if (strlen(tmp.MaCB) > 0)
            insert_order(ls, tmp);
    }
    ifs.close();
}

NodeCB check_maCB(listCB ls, string ma) {
    NodeCB p = ls.head;
    while (p != nullptr) {
        if (strcmp(p->data.MaCB, ma.c_str()) == 0) return p; 
        p = p->next;
    }
    return nullptr;
}

void themCB(listCB &ls) {
	load_file_dscb(ls) ;
	in_danh_sach_cb(ls) ; 
    CHUYENBAY tmp;
    cout << "-----Nhap thong tin chuyen bay moi-----\n";
    do {
        cout << "Nhap MaCB: ";
        cin.getline(tmp.MaCB, MAXMCB);
        if (check_maCB(ls, tmp.MaCB) != nullptr)
            cout << "Ma CB da trung, nhap lai!\n";
    } while (check_maCB(ls, tmp.MaCB) != nullptr);

    cout << "Nhap Ngay (d m y): ";
    cin >> tmp.NgayGioKH.day >> tmp.NgayGioKH.month >> tmp.NgayGioKH.year;
    cout << "Nhap Gio (h m): ";
    cin >> tmp.NgayGioKH.hour >> tmp.NgayGioKH.minute;
    cin.ignore(); 
    cout << "Nhap San Bay Den: ";
    cin.getline(tmp.SanBayDen, MAXSBD);
    cout << "Nhap So Hieu May Bay: ";
    cin.getline(tmp.SoHieuMB, MAXSHMB);
//    chuyen bay moi luon trong trang thai con ve 
    tmp.TrangThai = 1;

    insert_order(ls, tmp); 
    cout << "Them thanh cong!\n";
    save_file_dscb(ls);
}

void chinh_Datetime(listCB &ls) {
	in_danh_sach_cb(ls) ; 
    string ma_tim;
    cout << "Nhap maCB muon chinh ngay gio: ";
    getline(cin, ma_tim);
    NodeCB p = ls.head;
    while (p != nullptr) {
        if (strcmp(p->data.MaCB, ma_tim.c_str()) == 0) break;
        p = p->next;
    }
    if (p == nullptr) { cout << "Khong tim thay!\n"; return; }
    cout << "Ngay gio hien tai: " << p->data.NgayGioKH.day << "/"
         << p->data.NgayGioKH.month << "/" << p->data.NgayGioKH.year
         << " " << p->data.NgayGioKH.hour << ":" << p->data.NgayGioKH.minute << "\n";
    cout << "Nhap ngay moi (d m y): ";
    cin >> p->data.NgayGioKH.day >> p->data.NgayGioKH.month >> p->data.NgayGioKH.year;
    cout << "Nhap gio moi (h m): ";
    cin >> p->data.NgayGioKH.hour >> p->data.NgayGioKH.minute;
    cin.ignore();
    save_file_dscb(ls);
    cout << "Cap nhat thanh cong!\n";
}

void huyCB(listCB &ls) {
	load_file_dscb(ls) ;
	in_danh_sach_cb(ls) ; 
    if (ls.head == nullptr) { cout << "Danh sach rong!\n"; return; }
    string ma_tim;
    cout << "Nhap maCB can huy: ";
    getline(cin, ma_tim);
    NodeCB p = ls.head, pre = nullptr;
    while (p != nullptr && strcmp(p->data.MaCB, ma_tim.c_str()) != 0) {
        pre = p;
        p = p->next;
    }
    if (p == nullptr) { cout << "Khong tim thay!\n"; return; }
    if (pre == nullptr) {
        ls.head = p->next;
        if (ls.head == nullptr) ls.tail = nullptr; 
    } else {
        pre->next = p->next;
        if (p == ls.tail) ls.tail = pre;
    }
    delete p;
    ls.soLuongCB--;
    save_file_dscb(ls);
    cout << "Da huy chuyen " << ma_tim << " thanh cong!\n";
}

void in_danh_sach_cb(listCB ls) {
	load_file_dscb (ls) ;
    if (ls.head == nullptr) { cout << "\nDanh sach rong!\n"; return; }
    cout << "\n" << string(100, '=') << "\n";
    cout << setw(15) << left << "MA CB"
         << setw(15) << left << "SO HIEU MB"
         << setw(20) << left << "SAN BAY DEN"
         << setw(20) << left << "NGAY GIO KH"
         << setw(15) << left << "TRANG THAI" << "\n";
    cout << string(100, '-') << "\n";
    NodeCB p = ls.head;
    while (p != nullptr) {
        string ngayGio = to_string(p->data.NgayGioKH.day) + "/" +
                         to_string(p->data.NgayGioKH.month) + "/" +
                         to_string(p->data.NgayGioKH.year) + " " +
                         to_string(p->data.NgayGioKH.hour) + ":" +
                         to_string(p->data.NgayGioKH.minute);
        string stt;
        if (p->data.TrangThai == 0) stt = "Huy chuyen";
        else if (p->data.TrangThai == 1) stt = "Con ve";
        else if (p->data.TrangThai == 2) stt = "Het ve";
        else stt = "Hoan tat";
        cout << setw(15) << left << p->data.MaCB
             << setw(15) << left << p->data.SoHieuMB
             << setw(20) << left << p->data.SanBayDen
             << setw(20) << left << ngayGio
             << setw(15) << left << stt << "\n";
        p = p->next;
    }
    cout << string(100, '=') << "\n";
    cout << "Tong: " << ls.soLuongCB << " chuyen bay.\n";
}
