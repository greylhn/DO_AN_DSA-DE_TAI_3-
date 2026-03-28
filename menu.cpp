#include <bits/stdc++.h>
#include <conio.h>   // _getch()
#include <windows.h> // màu sắc
using namespace std ;
//1. Cap nhat danh sach may bay 
//+ them may bay
//+ xoa may bay 
//+ hieu chinh may bay
//2. Cap nhat chuyen bay 
//+Lap chuyen bay moi
//+ Chinh sua ngay gio cua chuyen bay 
//+ Huy chuyen 
//3. Dat ve (tren chuyen bay) 
//4. Huy ve 
//5. In danh sach cac hanh khach thuoc 1 chuyen bay dua vao ma chuyen bay 
//6. In danh sách các chuyến bay khởi hành trong  ngày dd/mm/yyyy đến nơi XXXX mà còn vé 
//7. In danh sách các vé còn trống của 1 chuyến bay có mã chuyến bay là X. 
//8. Thống kê số lượt thực hiện chuyến bay của từng máy bay theo thứ tự  số lượt thực hiện giảm dần. 
// ===== đổi màu chữ =====
void setColor(int color) {
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), color);
}

// ===== menu =====
int menu() {
    string items[] = {
        "Nhap mang",
        "Xuat mang",
        "Tim max",
        "Thoat"
    };

    int n = 4;
    int pos = 0;

    while (true) {
        system("cls");

        cout << "=========== MENU PRO ===========" << endl;

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

// ===== xử lý mảng =====
void nhap(int a[], int &n) {
    cout << "Nhap n: ";
    cin >> n;
    for (int i = 0; i < n; i++) {
        cout << "a[" << i << "] = ";
        cin >> a[i];
    }
}

void xuat(int a[], int n) {
    cout << "Mang: ";
    for (int i = 0; i < n; i++) cout << a[i] << " ";
    cout << endl;
}

int maxx(int a[], int n) {
    int m = a[0];
    for (int i = 1; i < n; i++)
        if (a[i] > m) m = a[i];
    return m;
}

// ===== main =====
int main() {
    int a[100], n = 0;

    while (true) {
        int choice = menu();
        system("cls");

        if (choice == 0) {
            cout << "=== NHAP MANG ===\n";
            nhap(a, n);
        }
        else if (choice == 1) {
            cout << "=== XUAT MANG ===\n";
            xuat(a, n);
        }
        else if (choice == 2) {
            if (n == 0) cout << "Chua nhap!\n";
            else cout << "Max = " << maxx(a, n);
        }
        else if (choice == 3) {
            cout << "Tam biet!\n";
            break;
        }

        cout << "\n\nNhan phim bat ky de quay lai menu...";
        _getch();
    }

    return 0;
}