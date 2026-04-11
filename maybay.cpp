#include<iostream>
#include<cstring>
#include <conio.h>   // _getch()
#include <windows.h> // mau sac
using namespace std;
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
//tim may bay 
int timmaybay (DSMAYBAY &ds , char soHieu[])
{
	for (int i = 0 ; i <ds.n ; i++)
	{
		if (strcmp(ds.mb[i]->SoHieuMB , soHieu)== 0) return i ;
	}
	return -1 ;
}
void themmaybay (DSMAYBAY &ds)
{
	if (ds.n == MAXMB)
	{
		cout << "DANH SACH DAY" << endl ;
		return ;
	}
	MAYBAY *mb = new MAYBAY ;
	do 
	{
		cout << "Nhap so hieu may bay: " ;
		cin.getline(mb->SoHieuMB , MAXSHMB) ;
		if (timmaybay(ds, mb->SoHieuMB) >= 0)
		{
			cout << "So hieu da bi trung , vui long nhap lai" << endl ;
		}
	} while (timmaybay(ds,mb->SoHieuMB) >= 0) ;
	cout << "Nhap loai may bay: " ;
	cin.getline(mb->LoaiMB,MAXLMB) ;
	do 
	{
		cout << "Nhap so cho: ";
		cin >> mb->SoCho ;
		cin.ignore();
		if (mb->SoCho < 20)
		{
			cout << "So cho may bay phai lon hon 20 , vui long nhap lai" << endl ;
		}
	}while (mb->SoCho < 20) ;
	ds.mb[ds.n] = mb ;
	ds.n++ ;
}
// xoa may bay 
void xoamaybay (DSMAYBAY &ds) 
{
	char sohieu[MAXSHMB] ;
	cout << "Nhap so hieu may bay muon xoa: " ;
	cin.getline(sohieu , MAXSHMB) ;
	int pos = timmaybay(ds,sohieu) ;
	if (pos == -1)
	{
		cout << "khong tim thay" << endl ;
		return ;
	}
	delete ds.mb[pos];
	for (int i = pos ; i < ds.n-1 ; i++)
	{
		ds.mb[i] = ds.mb[i+1] ;
	}
	ds.n-- ;
	cout << "Xoa Thanh Cong" << endl ;
}
// sua may bay
void suamaybay(DSMAYBAY &ds){
	char SoHieu[MAXSHMB] ;
	cout << "Nhap so hieu may bay muon sua: " ;
	cin.getline(SoHieu , MAXSHMB) ;
    int pos = timmaybay(ds,SoHieu);
    if(pos == -1){
        cout<<"Khong tim thay!\n";
        return;
    }
    cout<<"Nhap lai thong tin may bay:\n";
    cout<<"Nhap loai moi: ";
    cin.getline(ds.mb[pos]->LoaiMB,MAXLMB);

    do{
        cout<<"Nhap so cho moi >=20: ";
        cin>>ds.mb[pos]->SoCho;
    }while(ds.mb[pos]->SoCho < 20);

    cout<<"--> Cap nhat thanh cong!\n";
}
void xuatDSMB(DSMAYBAY &ds){
    if(ds.n==0){
        cout<<"Danh sach rong!\n";
        return;
    }

    cout<<"\n===== DANH SACH MAY BAY =====\n";
    for(int i=0;i<ds.n;i++){
        cout<<i+1<<". "
            <<ds.mb[i]->SoHieuMB<<" - "
            <<ds.mb[i]->LoaiMB<<" - "
            <<ds.mb[i]->SoCho<<endl;
    }
}
void BaoLoi(const char* msg){
    cout << msg << endl;
}
void SaveFile(DSMAYBAY &ds, char *filename)
{
    FILE *f;
    if ((f = fopen(filename, "wb")) == NULL)
    {
        BaoLoi("Loi mo file de ghi");
        return;
    }

    for (int i = 0; i < ds.n; i++)
        fwrite(ds.mb[i], sizeof(MAYBAY), 1, f);

    fclose(f);
    BaoLoi("Da ghi xong danh sach vao file");
}
void OpenFile(DSMAYBAY &ds, char *filename)
{
    FILE *f;
    MAYBAY mb;
    for(int i = 0; i < ds.n; i++)
    delete ds.mb[i];
     ds.n = 0;

    if ((f = fopen(filename, "rb")) == NULL)
    {
        BaoLoi("Loi mo file de doc");
        return;
    }

    while (fread(&mb, sizeof(MAYBAY), 1, f) != 0)
    {
        ds.mb[ds.n] = new MAYBAY;
        *ds.mb[ds.n] = mb;
        ds.n++;
    }

    fclose(f);
    BaoLoi("Da load xong danh sach vao bo nho");
}
void DeleteItem (DSMAYBAY &ds, int i){
	delete  ds.mb[i]; // chi dung trong mang con tro
    for (int j=i+1; j <ds.n; j++)
       ds.mb[j-1]=ds.mb[j];
    ds.n--;
	 }
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

	 
	 
