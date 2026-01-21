#include <iostream>
#include <stdio.h> 
#include <string>
#include <vector>
#include <fstream>
#include <windows.h>

using namespace std;

//glorb speaker 0.1

void printGlorb(string filename);

int main(){

    SetConsoleOutputCP(CP_UTF8);
    SetConsoleCP(CP_UTF8);

    string filename = "GlorbEngine.txt";
    printGlorb(filename);

    vector<string> voices = {"null", "fridge", "max", "dimak", "old dimak"}; 
    int n{};

    for (int i = 0; i < 3; i++){
        cout << endl;
    }

    cout << "Helo this is Glorb Speaker, please choose your voice :\n";
    cout << "Frodge - 1, \nMax - 2, \nDimak - 3, \nOld Dimak - 4\n";
    cout << "Enter here: ";
    cin >> n;
    cout << "You choosed : " << voices[n] << endl;

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