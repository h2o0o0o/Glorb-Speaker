#include <iostream>
#include <stdio.h> 
#include <string>
#include <vector>
#include <fstream>
#include <iomanip>
#include <windows.h>

using namespace std;

//glorb speaker 0.5
//jopa

void printGlorb(string filename);

int main(){

    SetConsoleOutputCP(CP_UTF8);
    SetConsoleCP(CP_UTF8);

    string filename = "GlorbEngine.txt";
    printGlorb(filename);

    vector<string> voice = {"null", "Frodge", "Max", "Dimak", "Old Dimak"}; 
    int n{};

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

    do {
        cout << "> Enter here: ";
        cin >> n;

        while (n > vc_size - 1){
            cout << "eblan fuck you\n";
            cout << "> Enter again : ";
            cin >> n;
        }

        cout << "You choosed : " << voice[n] << ", continue with " << voice[n] << "? " << voice[n] << endl;
        cout << "y/n > "; 

        cin >> c;
        if( c == 'y' || c == 'Y') answ = true;
        else answ = false; 
    } while (!answ);
    

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