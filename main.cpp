#include <iostream>
#include <string>
#include <fstream>
#include <cstdio>
#include<algorithm>
#include<iterator>

#define SNARES 6

using namespace std;

// Объявление функций

void push_downtune(int **arr, string tonika, int rows);
void show_array(int **arr, int rows, int cols);
void fill_array(int **arr, int rows, int cols);
int counter(int **arr, int rows, int cols, string S_accord);
int output_to_file(int c);

// Мэйн

int main(){
    setlocale(LC_ALL, "Russian");
    basic_string <char>::size_type size, length;

    int cols;
    const int rows = SNARES;
    char str1[32];
    char str2[32];

    string S_accord;
    string S_pre_tonika;
    string S_tonika;

    FILE *fin = fopen("INPUT.txt", "r");
    fscanf(fin, "%i", &cols); // считываем количество ладов
    fgetc(fin);
    fgets(str1, 32, fin); // считываем первый лад
    fgets(str2, 32, fin); // считываем тонику

    fclose(fin);

    S_pre_tonika = string(str1);
    remove_copy(S_pre_tonika.begin(), S_pre_tonika.end(), back_inserter(S_tonika), char(10));
    S_accord = string(str2);

    int **arr = new int *[rows];
    for (int i = 0; i < rows; i++) {
        arr[i] = new int[cols];
    }

    push_downtune(arr, S_tonika, rows);
    fill_array(arr, rows, cols);
    cout << '\n';
    show_array(arr, rows, cols);

    int count;
    count = counter(arr, rows, cols, S_accord);
    output_to_file(count);
    delete[] arr;

    return 0;
}

// Реализация функций

void push_downtune(int **arr, string tonika ,const int rows){
    
    // Определяет тонику

    int k = 0;

    for(int i = 0; i < rows; i++){

        string S_note;

        while( (tonika[k]!=' ')&&((tonika[k] != char(0))) ){
            S_note += tonika[k];
            k++;
        }
        k++;

        int note;
        if (S_note == "C") note = 0;
        if ((S_note == "C#")||(S_note == "Db")) note = 1;
        if (S_note == "D") note = 2;
        if ((S_note == "D#")||(S_note == "Eb")) note = 3;
        if (S_note == "E") note = 4;
        if (S_note == "F") note = 5;
        if ((S_note == "F#")||(S_note == "Gb")) note = 6;
        if (S_note == "G") note = 7;
        if ((S_note == "G#")||(S_note == "Ab")) note = 8;
        if (S_note == "A") note = 9;
        if ((S_note == "A#")||(S_note == "Bb")) note = 10;
        if (S_note == "B") note = 11;
        cout << '\t';
        arr[i][0] = note;
    }
}

void show_array(int **arr, const int rows, const int cols){
    
    // Выводит лады в консоль

    for(int i = 0; i < rows; i++){
        for(int j = 0;j < cols; j++){
            if (arr[i][j] == 0) cout << "C" << '\t';
            if (arr[i][j] == 1) cout << "C#" << '\t';
            if (arr[i][j] == 2) cout << "D" << '\t';
            if (arr[i][j] == 3) cout << "D#" << '\t';
            if (arr[i][j] == 4) cout << "E" << '\t';
            if (arr[i][j] == 5) cout << "F" << '\t';
            if (arr[i][j] == 6) cout << "F#" << '\t';
            if (arr[i][j] == 7) cout << "G" << '\t';
            if (arr[i][j] == 8) cout << "G#" << '\t';
            if (arr[i][j] == 9) cout << "A" << '\t';
            if (arr[i][j] == 10) cout << "A#" << '\t';
            if (arr[i][j] == 11) cout << "B" << '\t';
        }
        cout << '\n';
    }


}

void fill_array(int **arr, const int rows, const int cols) {
    
    // Заполняет массив с ладами

    for (int i = 0; i < rows; i++) {
        for (int j = 1; j < cols; j++) {
            if (arr[i][j-1] + 1 >= 12){
                
                arr[i][j] = arr[i][j-1] - 11;
                
            } else {
                
                arr[i][j] = arr[i][j - 1] + 1;
            
            }
        }
    }
}

int counter(int **arr, const int rows, const int cols, string S_accord){
    
    // Считает количество способов взятия заданного аккорда

    int length;
    length = S_accord.length();
    char last = S_accord[length-1], pre_last = S_accord[length - 2];

    int accord;
    int count, count_1 = 0, count_2 = 0, count_3 = 0, count_4 = 0;

    if(last == '7') {

        S_accord.erase(length - 1,1);

        if (pre_last == 'm') {

            S_accord.erase( length - 2,1);

            if (S_accord == "C") accord = 0;
            if ((S_accord == "C#")||(S_accord == "Db")) accord = 1;
            if (S_accord == "D") accord = 2;
            if ((S_accord == "D#")||(S_accord == "Eb")) accord = 3;
            if (S_accord == "E") accord = 4;
            if (S_accord == "F") accord = 5;
            if ((S_accord == "F#")||(S_accord == "Gb")) accord = 6;
            if (S_accord == "G") accord = 7;
            if ((S_accord == "G#")||(S_accord == "Ab")) accord = 8;
            if (S_accord == "A") accord = 9;
            if ((S_accord == "A#")||(S_accord == "Bb")) accord = 10;
            if (S_accord == "B") accord = 11;

            int accord_2_part = accord + 3;
            int accord_3_part = accord + 7;
            int accord_4_part = accord + 10;
            if (accord_2_part >= 12) accord_2_part -= 11;
            if (accord_3_part >= 12) accord_3_part -= 11;
            if (accord_4_part >= 12) accord_4_part -= 11;
            for (int i = 0; i < rows; i++) {
                for (int k = 0; k < cols; k++) {
                    if (arr[i][k] == accord) count_1++;
                    if (arr[i][k] == accord_2_part) count_2++;
                    if (arr[i][k] == accord_3_part) count_3++;
                    if (arr[i][k] == accord_4_part) count_4++;
                }
            }
            count = count_1 * count_2 * count_3 * count_4;

        } else {

            if (S_accord == "C") accord = 0;
            if ((S_accord == "C#")||(S_accord == "Db")) accord = 1;
            if (S_accord == "D") accord = 2;
            if ((S_accord == "D#")||(S_accord == "Eb")) accord = 3;
            if (S_accord == "E") accord = 4;
            if (S_accord == "F") accord = 5;
            if ((S_accord == "F#")||(S_accord == "Gb")) accord = 6;
            if (S_accord == "G") accord = 7;
            if ((S_accord == "G#")||(S_accord == "Ab")) accord = 8;
            if (S_accord == "A") accord = 9;
            if ((S_accord == "A#")||(S_accord == "Bb")) accord = 10;
            if (S_accord == "B") accord = 11;

            int accord_2_part = accord + 3;
            int accord_3_part = accord + 7;
            int accord_4_part = accord + 10;
            if (accord_2_part >= 12) accord_2_part -= 11;
            if (accord_3_part >= 12) accord_3_part -= 11;
            if (accord_4_part >= 12) accord_4_part -= 11;
            for (int i = 0; i < rows; i++) {
                for (int k = 0; k < cols; k++) {
                    if (arr[i][k] == accord) count_1++;
                    if (arr[i][k] == accord_2_part) count_2++;
                    if (arr[i][k] == accord_3_part) count_3++;
                    if (arr[i][k] == accord_4_part) count_4++;
                }
            }
            count = count_1 * count_2 * count_3 * count_4;
        }
    } else {

        if(last == 'm'){

            S_accord.erase(length-1,1);

            if (S_accord == "C") accord = 0;
            if ((S_accord == "C#")||(S_accord == "Db")) accord = 1;
            if (S_accord == "D") accord = 2;
            if ((S_accord == "D#")||(S_accord == "Eb")) accord = 3;
            if (S_accord == "E") accord = 4;
            if (S_accord == "F") accord = 5;
            if ((S_accord == "F#")||(S_accord == "Gb")) accord = 6;
            if (S_accord == "G") accord = 7;
            if ((S_accord == "G#")||(S_accord == "Ab")) accord = 8;
            if (S_accord == "A") accord = 9;
            if ((S_accord == "A#")||(S_accord == "Bb")) accord = 10;
            if (S_accord == "B") accord = 11;

            int accord_2_part = accord + 3;
            int accord_3_part = accord + 7;
            if (accord_2_part >= 12) accord_2_part -= 11;
            if (accord_3_part >= 12) accord_3_part -= 11;
            for(int i = 0; i < rows; i++){
                for(int k = 0; k < cols; k++){
                    if(arr[i][k] == accord) count_1++;
                    if(arr[i][k] == accord_2_part) count_2++;
                    if(arr[i][k] == accord_3_part) count_3++;
                }
            }
            count = count_1 * count_2 * count_3;

        } else {

            if (S_accord == "C") accord = 0;
            if ((S_accord == "C#")||(S_accord == "Db")) accord = 1;
            if (S_accord == "D") accord = 2;
            if ((S_accord == "D#")||(S_accord == "Eb")) accord = 3;
            if (S_accord == "E") accord = 4;
            if (S_accord == "F") accord = 5;
            if ((S_accord == "F#")||(S_accord == "Gb")) accord = 6;
            if (S_accord == "G") accord = 7;
            if ((S_accord == "G#")||(S_accord == "Ab")) accord = 8;
            if (S_accord == "A") accord = 9;
            if ((S_accord == "A#")||(S_accord == "Bb")) accord = 10;
            if (S_accord == "B") accord = 11;

            int accord_2_part = accord + 4;
            int accord_3_part = accord + 7;
            if (accord_2_part >= 12) accord_2_part -= 11;
            if (accord_3_part >= 12) accord_3_part -= 11;
            for(int i = 0; i < rows; i++){
                for(int k = 0; k < cols; k++){
                    if(arr[i][k] == accord) count_1++;
                    if(arr[i][k] == accord_2_part) count_2++;
                    if(arr[i][k] == accord_3_part) count_3++;
                }
            }
            count = count_1 * count_2 * count_3;
        }

    }

    return count;

}

int output_to_file(const int c){
    
    // Записывает в файл количество способов взятия заданного аккорда

    string out_path = "OUTPUT.txt";
    ofstream fout;
    fout.open(out_path);

    if(!fout.is_open()){

        cout << "Ошибка открытия файла!" << out_path << endl;

    } else {

        fout << "Вы можете взять аккорд " << c << " способами";

    }

    fout.close();
}
