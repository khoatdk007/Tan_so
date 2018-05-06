#include <iostream>
#include <vector>
#include <iomanip>
#include <algorithm>
using namespace std;

struct gt{
    int giatri;
    int tanso;
};

int chuso(int a)
{
    int i = 0;
    int b = a;
    do {
        b = b / 10;
        i++;
    } while (b > 0);
    return i;
};

int main()
{
    system("cls");
    cout << "Nhap N : ";
    int N;
    cin >> N;
    vector<gt> gtr(1);
    gtr[0].giatri = 0;
    gtr[0].tanso = 1;
    int r;
    bool flag;
    cout << "Nhap cac gia tri cua dau hieu : " << endl;
    for (int i = 0; i < N; i++)
    {
        cin >> r;
        flag = true;
        for (int j = 0; j <= i; j++){
            if (r == gtr[j].giatri)
            {
                gtr[j].tanso++;
                flag = false;
            }
        }
        if (flag != false)
        gtr.push_back({r,1});
    }
    
    gtr.erase(gtr.begin());

    {
        cout << "Gia tri (x) | ";
        for(int i = 0; i < gtr.size(); i++){
            cout << setw(chuso(gtr[i].giatri));
            cout << gtr[i].giatri << " | ";
        }
        cout << endl;
    }

    {
        cout << " Tan so (n) | ";
        for (int i = 0; i < gtr.size(); i++)
        {
            cout << setw(chuso(gtr[i].giatri));
            cout << gtr[i].tanso << " | " ;
        }
        cout << "N = " << N << endl;
    }

    int max = gtr[0].giatri;
    int min = gtr[0].giatri;
    int mot = gtr[0].tanso;
    int tansonhonhat = gtr[0].tanso;
    for (int i = 0; i < gtr.size(); i++){
        if (gtr[i].giatri > max) max = gtr[i].giatri;
        if (gtr[i].giatri < min) min = gtr[i].giatri; 
        if (gtr[i].tanso > mot) mot = gtr[i].giatri;
        if (gtr[i].tanso < tansonhonhat) tansonhonhat = gtr[i].giatri;
    }
    cout << endl << "* Nhan xet : " << endl;
    cout << "Co " << gtr.size() << " gia tri khac nhau cua dau hieu " << endl;
    cout << "Gia tri lon nhat la " << max << endl;
    cout << "Gia tri nho nhat la " << min << endl;
    cout << "Gia tri co tan so lon nhat la " << mot << endl;
    cout << "Gia tri co tan so nho nhat la " << tansonhonhat << endl << endl;
    return 0;
}