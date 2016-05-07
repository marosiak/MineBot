#define WINVER 0x0500
#include <windows.h>
#include <string>
#include <iostream>
#include <fstream>
#include <sstream>
using namespace std;


int kamienny[2] = {180000, 220000};
int zelazny[2] = {520000, 660000};
int diamentowy[2] = {1000000, 2000000};

int convert(string key)
{
    int _size = 36;
    int kCodes[] = {0x41, 0x42, 0x43, 0x44, 0x45, 0x46, 0x47, 0x48, 0x49,
                    0x4A, 0x4B, 0x4C, 0x4D, 0x4E, 0x4F, 0x50,
                    0x51, 0x52, 0x53, 0x54, 0x55, 0x56, 0x57,
                    0x58, 0x59, 0x5A, 0x30, 0x31, 0x32, 0x33, 0x34
                    ,0x35, 0x36, 0x37, 0x38, 0x39
                   };
    string kCodes_str[] = {"A", "B", "C", "D", "E", "F", "G", "H", "I",
                           "J", "K", "L", "M", "N", "O", "P",
                           "Q", "R", "S", "T", "U", "V", "W",
                           "X", "Y", "Z", "0", "1", "2", "3",
                           "4", "5", "6", "7", "8", "9"
                          };
    for(int i = 0; i<= _size; i++)
    {
        if(key == kCodes_str[i])
        {
            return kCodes[i];
        }
    }
}

void release(int key){
    INPUT ip;
    ip.type = INPUT_KEYBOARD;
    ip.ki.wScan = 0;
    ip.ki.time = 0;
    ip.ki.dwExtraInfo = 0;
    ip.ki.wVk = key;
    ip.ki.dwFlags = 0;
    SendInput(1, &ip, sizeof(INPUT));
    ip.ki.dwFlags = KEYEVENTF_KEYUP;
    SendInput(1, &ip, sizeof(INPUT));
}

void hold(string key, int time){
    INPUT ip;
    ip.type = INPUT_KEYBOARD;
    ip.ki.wScan = 0;
    ip.ki.time = 0;
    ip.ki.dwExtraInfo = 0;
    ip.ki.wVk = convert(key);
    ip.ki.dwFlags = 0;
    SendInput(1, &ip, sizeof(INPUT));
    Sleep(time);
    if(time > 0){
        release(convert(key));
    }
}

void _hold(int key, int time){
    INPUT ip;
    ip.type = INPUT_KEYBOARD;
    ip.ki.wScan = 0;
    ip.ki.time = 0;
    ip.ki.dwExtraInfo = 0;
    ip.ki.wVk = key;
    ip.ki.dwFlags = 0;
    SendInput(1, &ip, sizeof(INPUT));
    Sleep(time);
    if(time > 0){
        release(key);
    }
}
string kilof;
char doKonca;
char wylaczyc;
void askQuestions(){

    cout << "Jakich kilofow bedziesz uzywal? [kamienny/zelazny/diamentowy]: ";
    cin >> kilof;
    cout << "Czy chcesz aby twoj kilof zostal zuzyty do konca? [t/n]: ";
    cin >> doKonca;
    cout << "Czy chcesz aby twoj komputer zostal wylaczony po skonczeniu kopania? [t/n]: ";
    cin >> wylaczyc;
    cout << endl << "==================================================================="<<endl;
    cout << "Teraz przelacz na okno Minecraft'a, pamietaj ze przycisk kopania musi byc ustawiony na M!";
    cout << endl;
}

int main(){
    askQuestions();
    Sleep(7000);
    for(int i = 2; i<=9; i++){
            if(kilof == "kamienny"){
                if(doKonca == 't'){
                    hold("M", kamienny[1]);
                }
                else{
                    hold("M", kamienny[0]);
                }
            }
            if(kilof == "zelazny"){
                if(doKonca == 't'){
                    hold("M", zelazny[1]);
                }
                else{
                    hold("M", zelazny[0]);
                }
            }
            if(kilof == "diamentowy"){
                if(doKonca == 't'){
                    hold("M", diamentowy[1]);
                }
                else{
                    hold("M", diamentowy[0]);
                }
            }
        ostringstream ss;
        ss << i;
        string str = ss.str();
        hold(str, 1);
    }
    if(wylaczyc == 't'){
        system("shutdown -s");
    }
}
