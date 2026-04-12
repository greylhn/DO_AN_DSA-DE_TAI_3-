#include "HanhKhach.h"

NodeHK* TaoNodeHK(HANHKHACH hk) {
    NodeHK* p = new NodeHK;
    p->data = hk;
    p->left = NULL;
    p->right = NULL;
    return p;
}

NodeHK* TimKiemHK(TREE_HK root, const char* CMND) {
    if (root == NULL) return NULL;
    
    int cmp = strcmp(CMND, root->data.CMND);
    if (cmp == 0) return root;
    else if (cmp < 0) return TimKiemHK(root->left, CMND);
    else return TimKiemHK(root->right, CMND);
}

bool ThemHK(TREE_HK& root, const HANHKHACH& hk) {
    if (root == NULL) {
        root = TaoNodeHK(hk);
        return true;
    }
    
    int cmp = strcmp(hk.CMND, root->data.CMND);
    if (cmp == 0) return false; // Trùng CMND
    else if (cmp < 0) {
        return ThemHK(root->left, hk);
    }
    else {
        return ThemHK(root->right, hk);
    }
}

void DuyetTrungTu(TREE_HK root) {
    if (root != NULL) {
        DuyetTrungTu(root->left);
        cout << root->data.CMND << " - " << root->data.Ho << " " << root->data.Ten << " - " << root->data.Phai << endl;
        DuyetTrungTu(root->right);
    }
}

void GiaiPhongTree(TREE_HK& root) {
    if (root != NULL) {
        GiaiPhongTree(root->left);
        GiaiPhongTree(root->right);
        delete root;
        root = NULL;
    }
}

void KhoiTaoTree(TREE_HK& root) {
    root = NULL;
}
