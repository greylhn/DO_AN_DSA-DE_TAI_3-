#include<iostream>
#include<cstring>
#include <conio.h>   // _getch()
#include <windows.h> // mau sac
#include <fstream>
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
void SaveFile(DSMAYBAY &ds)
{
	 ofstream ofs ;
	 ofs.open("maybay.txt" , ios::out) ;
	 if (!ofs.is_open())
	 {
	 	cout << "khong the mo file" << endl ;
	 	return ;
	 }
	 for (int i = 0 ; i < ds.n;i++)
	 {
	 	ofs << ds.mb[i]->SoHieuMB << "/n";
		ofs << ds.mb[i]->SoCho << "/n";
		ofs << ds.mb[i]->LoaiMB << "/n";
	 }
	 ofs.close() ;
	 cout << "Da luu file thanh cong" ;
}
void Openfile (DSMAYBAY &ds)
{
	ifstream ifs ;
	ifs.open("maybay.txt" , ios::in) ;
	MAYBAY tmp ;
	if (!ifs.is_open())
	{
		cout << "Khong tim thay file" << endl ;
		return ;
	}
	while (ifs.peek() != EOF)
	{
		MAYBAY* tmp = new MAYBAY;
    	ifs.getline(tmp->SoHieuMB, MAXSHMB);
    	ifs >> tmp->SoCho;
    	ifs.ignore();
    	ifs.getline(tmp->LoaiMB, MAXLMB);
    	ds.mb[ds.n] = tmp;
    	ds.n++;
	}
	ifs.close() ;
}
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
	SaveFile(ds) ;
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
	SaveFile(ds) ;
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
    SaveFile(ds) ;
}
void xuatDSMB(DSMAYBAY &ds){
	Openfile(ds) ;
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
void DeleteItem (DSMAYBAY &ds, int i){
	delete  ds.mb[i]; // chi dung trong mang con tro
    for (int j=i+1; j <ds.n; j++)
       ds.mb[j-1]=ds.mb[j];
    ds.n--;
	 }
	 
