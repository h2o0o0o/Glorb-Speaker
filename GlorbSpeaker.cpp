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
//glorb speaker 0.5


void printGlorb(string filename);

int main(){

    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    string filename = "GlorbEngine.txt";
    printGlorb(filename);

    vector<string> voice = {"null", "Frodge", "Max", "Dimak", "Old Dimak"}; 
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
        cout << arr[i] << "\n";
        string adress = "audio\\" + voice[n] + "\\" + char(arr[i]) + ".wav";
        cout << adress << endl;
        PlaySoundA(adress.c_str(), NULL, SND_FILENAME | SND_SYNC);


    }

    system("pause");

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

    //если вводить вместо цифры вначале букву пизда программе

    // выводит в консоль привет, выберите голос.
    // холодос
    // димак
    // макс
    // димак(олд)
    // пользователь выбирает голос. 
    // выбирается основная папка с голосом который выбрал пользователь где лежат звуки.
    // введите текст >> 
    // пользователь вводит текст. 
    // текст разбивается на array из chars, где к каждому символу присваивается звук и проигрывается подряд. 
    // что дальше типо воспроизвести еще или вернуться в главное меню