#include<bits/stdc++.h>
#include<string>
#include<conio.h>
#include"Datetime.h"
using namespace std ;
void nhapNgay(int &d, int &m, int &y)
{
    char c;
    string s = "";

    cout << "Nhap ngay khoi hanh(dd/mm/yyyy): ";

    while (true)
    {
        c = _getch();

        // ENTER
        if (c == 13 && s.length() == 10)
            break;

        // BACKSPACE
        if (c == 8 && !s.empty())
        {
            if (s.back() == '/')
            {
                cout << "\b \b";
                s.pop_back();
            }
            cout << "\b \b";
            s.pop_back();
            continue;
        }

        // chi nhan so
        if (c >= '0' && c <= '9')
        {
            if (s.length() < 10)
            {
                s += c;
                cout << c;

                // tu them /
                if (s.length() == 2 || s.length() == 5)
                {
                    s += '/';
                    cout << "/";
                }
            }
        }
    }

   // tach ngay thang nam
    d = stoi(s.substr(0, 2));
    m = stoi(s.substr(3, 2));
    y = stoi(s.substr(6, 4));
}
