#include <iostream>
#include <windows.h>
using namespace std;
class Drib {
private:
    int chys;
    int znam;
    void skrD() {
        if (znam == 0) {
            return;
        }
        int spD = (chys, znam);
        chys /= spD;
        znam /= spD;
        if (znam < 0) {
            chys = -chys;
            znam = -znam;
        }
    }
public:
    Drib() : chys(0), znam(1) {}

    Drib(int ch, int zn) {
        if (zn == 0) {
            cout << "Помилка: Знаменник не може бути нулем! Встановлено знаменник 1." << endl;
            chys = ch;
            znam = 1;
        } else {
            chys = ch;
            znam = zn;
            skrD();
        }
    }
    void vvD() {
        cout << "Введіть чисельник: ";
        cin >> chys;
        do {
            cout << "Введіть знаменник (не нуль): ";
            cin >> znam;
            if (znam == 0) {
                cout << "Знаменник не може бути нулем. Спробуйте ще раз." << endl;
            }
        } while (znam == 0);
        skrD();
    }
    void vyvD() const {
        if (znam == 1) {
            cout << chys;
        } else {
            cout << chys << "/" << znam;
        }
    }
    Drib dod(const Drib& dr) const {
        int novChys = chys * dr.znam + dr.chys * znam;
        int novZnam = znam * dr.znam;
        return Drib(novChys, novZnam);
    }

    Drib vid(const Drib& dr) const {
        int novChys = chys * dr.znam - dr.chys * znam;
        int novZnam = znam * dr.znam;
        return Drib(novChys, novZnam);
    }

    Drib mno(const Drib& dr) const {
        int novChys = chys * dr.chys;
        int novZnam = znam * dr.znam;
        return Drib(novChys, novZnam);
    }
    Drib dil(const Drib& dr) const {
        if (dr.chys == 0) {
            cout << "Помилка: Ділення на нульовий дріб неможливе! Повертаю 0/1." << endl;
            return Drib(0, 1);
        }
        int novChys = chys * dr.znam;
        int novZnam = znam * dr.chys;
        return Drib(novChys, novZnam);
    }
};
int main() {
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    Drib d1, d2;
    Drib rez;
    cout << "Введіть перший дріб:" << endl;
    d1.vvD();
    cout << "Введіть другий дріб:" << endl;
    d2.vvD();
    cout << "\nПерший дріб: ";
    d1.vyvD();
    cout << endl;
    cout << "Другий дріб: ";
    d2.vyvD();
    cout << endl;
    rez = d1.dod(d2);
    cout << "\nДодавання: ";
    d1.vyvD();
    cout << " + ";
    d2.vyvD();
    cout << " = ";
    rez.vyvD();
    cout << endl;
    rez = d1.vid(d2);
    cout << "Віднімання: ";
    d1.vyvD();
    cout << " - ";
    d2.vyvD();
    cout << " = ";
    rez.vyvD();
    cout << endl;
    rez = d1.mno(d2);
    cout << "Множення: ";
    d1.vyvD();
    cout << " * ";
    d2.vyvD();
    cout << " = ";
    rez.vyvD();
    cout << endl;
    rez = d1.dil(d2);
    cout << "Ділення: ";
    d1.vyvD();
    cout << " / ";
    d2.vyvD();
    cout << " = ";
    rez.vyvD();
    cout << endl;
    Drib d3(7, 21);
    cout << "\nСтворений дріб 7/21 (скорочений): ";
    d3.vyvD();
    cout << endl;
    Drib d4(5, 0);
    cout << "Створений дріб 5/0 (з обробкою помилки): ";
    d4.vyvD();
    cout << endl;
    return 0;
}