#pragma once
#include <iostream>
#include <cstring>
#include <string>

using namespace std;

struct HANHKHACH {
    char CMND[13];
    char Ho[30];
    char Ten[20];
    char Phai[5];
};

struct NodeHK {
    HANHKHACH data;
    NodeHK* left;
    NodeHK* right;
};
typedef NodeHK* TREE_HK;

// Binary Search Tree của Hành Khách theo CMND
void KhoiTaoTree(TREE_HK& root);
NodeHK* TaoNodeHK(HANHKHACH hk);
NodeHK* TimKiemHK(TREE_HK root, const char* CMND);
bool ThemHK(TREEHK& root, HANHKHACH hk);
void DuyetTrungTu(TREE_HK root);
void GiaiPhongTree(TREE_HK& root);
