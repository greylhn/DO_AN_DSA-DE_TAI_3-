#include<bits/stdc++.h>
#include"maybay.h"
#include"chuyenbay.h"
#include <conio.h>   // _getch()
#include <windows.h> // mau sac
using namespace std;

 //=================menu================
///set mau
void setColor(int color) {
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), color);
}

// ===== menu =====
int menu() {
    string items[] = {
        "1.Cap nhat danh sach may bay",
        "2.Cap nhat chuyen bay",
        "3.Dat ve",
        "4.Huy ve" ,
        "5.In danh sach cac hanh khach trong 1 chuyen bay dua vao ma chuyen bay.",
        "6.In danh sach cac chuyen bay khoi hanh trong  ngay dd/mm/yyyy den noi XXXX ma con ve.",
        "7.In danh sach cac ve con trong cá»§a 1 chuyen bay co ma chuyen bay la X." ,
        "8.Thong ke so luot thuc hien chuyen bay cua tung may bay theo thu tu so luot thuc hien giam dan." ,
        "9.Thoat chuong trinh"
    };

    int n = 9;
    int pos = 0;

    while (true) {
        system("cls");

        cout << "=========== MENU ===========" << endl;

        for (int i = 0; i < n; i++) {
            if (i == pos) {
                setColor(10); // mÃ u xanh
                cout << " >> " << items[i] << endl;
                setColor(7);  // reset
            } else {
                cout << "    " << items[i] << endl;
            }
        }

        int ch = _getch();

        if (ch == 224) { // phÃ­m Ä‘áº·c biá»‡t
            ch = _getch();
            if (ch == 72) pos--; // â†‘
            else if (ch == 80) pos++; // â†“

            if (pos < 0) pos = n - 1;
            if (pos >= n) pos = 0;
        }
        else if (ch == 13) { // Enter
            return pos;
        }
    }
}
//menu con quan li maybay
int menuMayBay() {
    string items[] = {
        "1. Them may bay",
        "2. Xoa may bay",
        "3. Sua thong tin may bay",
        "4. Liet ke danh sach may bay",
        "5. Quay lai",
        "6. luu file",
        "7. Doc file"
    };

    int n = 7;
    int pos = 0;

    while (true) {
        system("cls");
        cout << "===== QUAN LY MAY BAY =====\n";

        for (int i = 0; i < n; i++) {
            if (i == pos) {
                setColor(10);
                cout << " >> " << items[i] << endl;
                setColor(7);
            } else {
                cout << "    " << items[i] << endl;
            }
        }

        int ch = _getch();

        if (ch == 224) {
            ch = _getch();
            if (ch == 72) pos--;
            else if (ch == 80) pos++;

            if (pos < 0) pos = n - 1;
            if (pos >= n) pos = 0;
        }
        else if (ch == 13) {
            return pos;
        }
    }
}
int main ()
{
	DSMAYBAY ds ;
	ds.n = 0 ;
	int a[100], n = 0;
	
	while (true) {
	    int choice = menu();
	    system("cls");
	
	    if (choice == 0) {   // Cáº­p nháº­t mÃ¡y bay
	
	        while (true) {
	            int c = menuMayBay();
	
        if (c == 0) themmaybay(ds);
        else if (c == 1) xoamaybay(ds);
        else if (c == 2) suamaybay(ds);
        else if (c == 3) xuatDSMB(ds);
        else if (c == 5) SaveFile(ds, (char*)"maybay.dat");
        else if (c == 6) OpenFile(ds, (char*)"maybay.dat");
        else break;
	            cout << endl << "Nhan phim bat ky..." << endl;
	            _getch();
	        }
	
}
}
}
//menu con quan li chuyen bay
int menuChuyenBay() {
    string items[] = {
        "1. Them chuyen bay",
        "2. Xoa chuyen bay",
        "3. Sua thong tin chuyen bay",
        "4. Liet ke danh sach chuyen bay",
        "5. Quay lai"
    };

    int n = 5;
    int pos = 0;

    while (true) {
        system("cls");
        cout << "===== QUAN LY CHUYEN BAY =====\n";

        for (int i = 0; i < n; i++) {
            if (i == pos) {
                setColor(10);
                cout << " >> " << items[i] << endl;
                setColor(7);
            } else {
                cout << "    " << items[i] << endl;
            }
        }

        int ch = _getch();

        if (ch == 224) {
            ch = _getch();
            if (ch == 72) pos--;
            else if (ch == 80) pos++;

            if (pos < 0) pos = n - 1;
            if (pos >= n) pos = 0;
        }
        else if (ch == 13) {
            return pos;
        }
    }
}
int main ()
{
	DSMAYBAY ds ;
	ds.n = 0 ;
	int a[100], n = 0;
	DSCB dscb = nullptr ;
	while (true) {
	    int choice = menu();
	    system("cls");
	
	    if (choice == 0) {   // Cap nhat may bay
	
	        while (true) {
	            int c = menuMayBay();
	
	            if (c == 0) themmaybay(ds);
	            else if (c == 1) xoamaybay(ds);
	            else if (c == 2) suamaybay(ds);
	            else if (c == 3) xuatDSMB(ds);
				else if (c == 5) SaveFile(ds, (char*)"maybay.dat");
                else if (c == 6) OpenFile(ds, (char*)"maybay.dat");
	            else break;
	
	            cout << endl << "Nhan phim bat ky..." << endl;
	            _getch();
	        }
	
	    }
	    else if (choice == 1) {
	        while (true) {
	            int c = menuChuyenBay();
	            if (c == 0) themCB (dscb) ;
	            else if (c == 1) xoaCB (dscb) ;
	            else if (c == 2) ;//suamaybay(ds);
	            else if (c == 3) indsCB (dscb) ;
	            else break;
	
	            cout << endl << "Nhan phim bat ky..." << endl;
	            _getch();
	        }
	    }
	    else if (choice == 2) {
	        cout << "=== DAT VE ===" << endl ;
	    }
	    else if (choice == 3)
	    {
	        cout << "=== HUY VE ===" << endl ;
	    }
	    else if (choice == 4)
	    {
	        cout << "=== IN DANH SACH HANH KHACH ===" << endl ;
	    }
	    else if (choice == 5)
	    {
	        cout << "=== CHUYEN BAY TRONG NGAY ===" << endl ;
	    }
	    else if (choice == 6)
	    {
	        cout << "=== VE CON TRONG ===" << endl ;
	    }
	    else if (choice == 7)
	    {
	        cout << "=== THONG KE ===" << endl ;
	    }
	    else if (choice == 8) {
	        cout << "Tam biet!" << endl;
	        break;
	    }
	
	    cout << endl << "Nhan phim bat ky de quay lai menu..." << endl;
	    _getch();
}
}


