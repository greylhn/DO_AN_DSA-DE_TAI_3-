#include<bits/stdc++.h>
#include"maybay.h"
using namespace std;
//tim may bay 
int timmaybay (DSMAYBAY &ds , char soHieu[])
{
	for (int i = 0 ; i <ds.n ; i++)
	{
		if (strcmp(ds.mb[i]->SoHieuMB , SoHieu)== 0) return i ;
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
	for (int i = pos ; i < ds.n ; i++)
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

    cin.ignore();
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
