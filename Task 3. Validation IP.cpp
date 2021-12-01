/* Task 3. Validation IP.cpp
 Проверьте, задаёт ли введённая пользователем строка корректный IP-адрес четвёртой версии (IPv4). IP-адрес должен представлять из себя четыре числа,
 разделённые точками без пробелов, причём каждое число должно быть в диапазоне от 0 до 255 включительно. Числа не должны содержать ведущих нулей.
 Других символов в строке, кроме вышеописанных, присутствовать не должно.

Пользователь вводит строку, задающую ip-адрес. Программа должна вывести слово Yes, если адрес корректен, и слово No, если это не так.



Примеры

Корректные:

127.0.0.1
255.255.255.255
1.2.3.4
55.77.213.101


Некорректные:

255.256.257.258 (числа больше 255)
0.55.33.22. (лишняя точка в конце)
10.00.000.0 (лишние нули)
23.055.255.033 (опять лишние нули)
65.123..9 (две точки подряд)
a.b.c.d (посторонние символы, помимо цифр и точек)


Советы и рекомендации
Активно используйте оператор индексации строки str[i], но помните что индексы начинаются с нуля, а не с единицы.
Создайте отдельную функцию для получения отдельных чисел из IP-адреса и валидируйте эти отдельные числа.
Для валидации отдельных цифр у чисел следует использовать оператор сравнения с константами символов. Символы от ‘0’ до ‘9’ расположены последовательно и поэтому уместные операторы <= и >=.


Что оценивается
Корректность валидации заданного пользователем адреса.

 */

#include <iostream>
#include <string>
using namespace std;

//function
bool ValidationAddresses(string szEnteredIP)
{
    // checking that the value consists of numbers and dots
    bool bNotDigitsAndPoints = false;
    for (int i = 0; i < szEnteredIP.length(); i++) {
        if (szEnteredIP[i] != '.' && (szEnteredIP[i] < '0' || szEnteredIP[i] > '9')) bNotDigitsAndPoints = true;
    }

    //checking double dots
    bool bDablePoints = false;

    for (int i = 0; i < szEnteredIP.length() - 1; i++) {
        if (szEnteredIP[i] == '.' && szEnteredIP[i + 1] == '.') bDablePoints = true;
    }
    //checking dots at the beginning and end
    bool bPointsToStartAndEnd = false;
    
    if (szEnteredIP[0]== '.' || szEnteredIP[szEnteredIP.length() - 1] == '.')  bPointsToStartAndEnd = true;

    //checking double or more zero
    bool bMoreOneZero = false;
    for (int i = 0; i < szEnteredIP.length() - 1; i++) {
        if (szEnteredIP[i] == '0' && szEnteredIP[i + 1] == '0') bMoreOneZero = true;
    }

    //check for zero before number
    bool bZeroBeforeDigit = false;
    for (int i = 0; i < szEnteredIP.length() - 1; i++) {
        if (szEnteredIP[i] == '0' && (szEnteredIP[i + 1] > '0' && szEnteredIP[i + 1] <= '9')) bZeroBeforeDigit = true;
    }
    
    // if checking correct, moving on. Else, send "false"
    bool bIPOk = false; 
    if (bNotDigitsAndPoints || bDablePoints || bPointsToStartAndEnd || bMoreOneZero || bZeroBeforeDigit) {
        bIPOk = false;
        }
    else {
        bIPOk = true;
        }

    if (bIPOk) {
        string ipparth;
        for (int n = 0; n <= szEnteredIP.length(); n++) {
            if (szEnteredIP[n] == '.' || szEnteredIP[n] == 0) {
                //check part IP
                if (ipparth >= "0" && ipparth <= "255") {
                    ipparth = "";
                    continue;
                }
                //if part not correct, send "false"
                else {
                    bIPOk = false;
                    break;
                }
            }
            else {
                //copy char to ipparth variable 
                ipparth += szEnteredIP[n];
            }
        }
    }
    return bIPOk;
}

int main()
{
    for (;;){
        string szEnteredIP;
        cout << "Input IP: ";
        cin >> szEnteredIP;

        if (ValidationAddresses(szEnteredIP)) {
            cout << "Input IP correct." << endl;
        }
        else {
            cout << "Input IP incorrect!" << endl;
        }
    }
}