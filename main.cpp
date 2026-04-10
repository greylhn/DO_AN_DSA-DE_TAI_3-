#include<bits/stdc++.h>
#include"maybay.h"
#include <conio.h>   // _getch()
#include <windows.h> // mÃ u sáº¯c
using namespace std;
struct DateTime {
    int day, month, year;
    int hour, minute;
};

//=================menu================
//set mau
void setColor(int color) {
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), color);
}
//menu
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
        "5. Quay lai"
    };

    int n = 5;
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
	
	    if (choice == 0) {   // Cap nhat may bay
	
	        while (true) {
	            int c = menuMayBay();
	
	            if (c == 0) themmaybay(ds);
	            else if (c == 1) xoamaybay(ds);
	            else if (c == 2) suamaybay(ds);
	            else if (c == 3) xuatDSMB(ds);
	            else break;
	
	            cout << endl << "Nhan phim bat ky..." << endl;
	            _getch();
	        }
	
	    }
	    else if (choice == 1) {
	        cout << "=== CAP NHAT CHUYEN BAY ===" << endl;
	        cout << "1.Lap chuyen bay moi" << endl ;
	        cout << "2.Chinh sua ngay gio cua chuyen bay" << endl ;
	        cout << "3.Huy chuyen" << endl ;
	        int tmp ;
	        cout << "Moi nhap lua chon: " ;
	        cin >> tmp ;
	        cin.ignore();
	
	        if (tmp == 1)
	        {
	            // ham them chuyen bay 	
	        }
	        else if (tmp == 2)
	        {
	            // ham chinh sua ngay gio 
	        }
	        else if (tmp == 3)
	        {
	            // ham huy chuyen 
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


