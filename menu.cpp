#include <bits/stdc++.h>
#include <conio.h>   // _getch()
#include <windows.h> // màu sắc
using namespace std ;
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
        "7.In danh sach cac ve con trong của 1 chuyen bay co ma chuyen bay la X." ,
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
                setColor(10); // màu xanh
                cout << " >> " << items[i] << endl;
                setColor(7);  // reset
            } else {
                cout << "    " << items[i] << endl;
            }
        }

        int ch = _getch();

        if (ch == 224) { // phím đặc biệt
            ch = _getch();
            if (ch == 72) pos--; // ↑
            else if (ch == 80) pos++; // ↓

            if (pos < 0) pos = n - 1;
            if (pos >= n) pos = 0;
        }
        else if (ch == 13) { // Enter
            return pos;
        }
    }
}
// ===== main =====
int main() {
    int a[100], n = 0;

    while (true) {
        int choice = menu();
        system("cls");

        if (choice == 0) {
        	cout << "=== CAP NHAT DANH SACH MAY BAY ===\n" ;
        	cout << "1.Them may bay" <<endl ;
        	cout << "2.Xoa may bay" << endl ;
        	cout << "3.Cap nhat may bay" << endl ;
        	cout << "Moi nhap lua chon: " ;
            int tmp ;
            cin >> tmp ;
           	if(tmp==1) 
           	{
           		// ham them may bay
			}
			else if (tmp==2) 
			{
//				ham xoa may bay 
			}
			else if (tmp==3)
			{
//				ham cap nhat may bay 
			}
        }
        else if (choice == 1) {
            cout << "=== CAP NHAT CHUYEN BAY ===\n";
            cout << "1.Lap chuyen bay moi" << endl ;
            cout << "2.Chinh sua ngay gio cua chuyen bay" << endl ;
            cout << "3.Huy chuyen" << endl ;
            int tmp ;
            cout << "Moi nhap lua chon: " ;
            cin >> tmp ;
            if (tmp == 1)
            {
//            ham them chuyen bay 	
			}
			else if (tmp == 2)
			{
//				ham chinh sua ngay gio 
			}
			else if (tmp == 3)
			{
//				ham huy chuyen 
			}
        }
        else if (choice == 2) {
            cout << "=== DAT VE ===\n" ;
            // chuong trinh dat ve 
        }
        else if (choice == 3)
        {
        	cout << "=== HUY VE ===\n" ;
//        	ham huy ve 
		}
		else if (choice == 4)
		{
			cout << "=== IN DANH SACH CAC HANH KHACH TRONG 1 CHUYEN BAY DUA VAO MA CHUYEN BAY ===\n" ;
			//chuong trinh 
		}
		else if (choice == 5)
		{
			cout << "=== IN DANH SACH CAC CHUYEN BAY KHOI HANH TRONG  NGAY DD/MM/YYYY DEN NOI XXXX MA CON VE ===\n" ;
//			chuong trinh 
		}
		else if (choice == 6)
		{
			cout << "=== IN DANH SACH CAC VE CON TRONG CỦA 1 CHUYEN BAY CO MA CHUYEN BAY LA X ===\n" ;
//			chuong trinh 
		}
		else if (choice == 7)
		{
			cout << "=== THONG KE SO LUOT THUC HIEN CHUYEN BAY CUA TUNG MAY BAY THEO THU TU SO LUOT THUC HIEN GIAM DAN ===\n" ;
//			chuong trinh 
		}
        else if (choice == 8) {
            cout << "Tam biet!\n";
            break;
        }

        cout << "\n\nNhan phim bat ky de quay lai menu...";
        _getch();
    }

    return 0;
}
