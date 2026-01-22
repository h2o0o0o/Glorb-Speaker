#include <iostream>
#include <stdio.h> 
#include <string>
#include <vector>
#include <fstream>
#include <iomanip>
#include <limits>
#include <conio.h>
#include <windows.h>
#include <mmsystem.h>

using namespace std;

#pragma comment(lib, "winmm.lib")
#pragma comment(lib, "user32.lib")

//glorb speaker 1.0
//h20. all right!

static wstring blya(const string& s, UINT codePage);

void printGlorb(string filename);

int main(){

    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    string filename = "GlorbEngine.txt";
    printGlorb(filename);

    vector<string> voice = {"null", "Frodge", "Shandu", "Dimak", "Old Dimak"}; 
    int n;

    for (int i = 0; i < 2; i++){
        cout << endl;
    }

    int vc_size = voice.size();

    cout << "Helo this is Glorb Speaker, please choose your voice" << endl;

    for (int i = 1; i < vc_size; i++){
        cout << setfill ('-');
        cout << left << setw(13)<< voice[i]<< right << setw(5) << i << endl;
    }

    bool answ = false;
    char c;

    do{
        while(true){
            cout << "> Enter voice number here: ";

            if (!(cin >> n)){
                cin.clear();
                cin.ignore(( numeric_limits<streamsize>::max)(), '\n' );
                cout << "debil, enter a number please\n";
                continue;
            }
            if (n >= 1 && n < vc_size) break;

            cout << "eblan, enter number from 1 to " << vc_size - 1 << " try again.\n";
        }

        cout << "You choosed : " << voice[n] << ", continue with " << voice[n] << "? " << voice[n] << endl;
        cout << "y/n > "; 

        cin >> c;
        if( c == 'y' || c == 'Y') answ = true;
        else answ = false; 

    } while (!answ);

    cin.ignore(( numeric_limits<streamsize>::max)(), '\n' );

    string input;

    cout << "Input your message :\n";
    cout << "> ";
    getline (cin, input);
    cout << "length is " << input.length() << endl; // debug

    const char* arr = input.c_str();
    cout << arr << endl; //debug

    for( int i = 0; i < input.length(); i++){
        char ch = arr[i];

        cout << arr[i] << "";
        std::string adress = "audio\\" + voice[n] + "\\" + std::string(1, ch) + ".wav";
        cout << adress << endl;

        std::wstring wadress = blya(adress, 1251);
        PlaySoundW(wadress.c_str(), NULL, SND_FILENAME | SND_SYNC);

    }

    system("pause");

}

static std::wstring blya(const std::string& s, UINT codePage)
{
    if (s.empty()) return L"";

    int needed = MultiByteToWideChar(codePage, 0, s.c_str(), -1, nullptr, 0);
    if (needed <= 0) return L"";

    std::wstring w(needed, L'\0');
    MultiByteToWideChar(codePage, 0, s.c_str(), -1, &w[0], needed);

    w.pop_back();
    return w;
}

void printGlorb(string filename){
    string line = "";
    ifstream inFile;
    
    inFile.open("GlorbEngine.txt");

    if(inFile.is_open()){
        while(getline(inFile, line)){
            cout<< line << endl;
        }
    }

    else{
        cout << "no glorb\n";
        cout << "no file\n";
    }
    inFile.close();

}