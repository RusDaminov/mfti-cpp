#include <iostream>
#include <sstream>
#include <string>
#include <iomanip>
#include <cassert>

using namespace std;

void testNumberFormatting() {
    cout << "Тестирование форматирования чисел\n";
    cout << "=================================\n";
    
    // Тест 1: Проверка округления до двух знаков
    {
        streambuf* origCin = cin.rdbuf();
        streambuf* origCout = cout.rdbuf();
        
        stringstream input("Тест\n25\n7.777\n");
        ostringstream output;
        
        cin.rdbuf(input.rdbuf());
        cout.rdbuf(output.rdbuf());
        
        string name;
        int age;
        double average_score;
        
        cout << "Введите ваше имя: ";
        cin >> name;
        
        cout << "Введите ваш возраст: ";
        cin >> age;
        
        cout << "Введите ваш средний балл: ";
        cin >> average_score;
        
        cout << "Имя: " << name << endl;
        cout << "Возраст: " << age << endl;
        cout << fixed << setprecision(2);
        cout << "Средний балл: " << average_score << endl;
        
        string result = output.str();
        cin.rdbuf(origCin);
        cout.rdbuf(origCout);
        
        // Проверяем округление
        assert(result.find("7.78") != string::npos);
        cout << "✓ Тест округления 7.777 → 7.78 пройден\n";
    }
    
    // Тест 2: Проверка вывода ровно двух знаков после запятой
    {
        streambuf* origCin = cin.rdbuf();
        streambuf* origCout = cout.rdbuf();
        
        stringstream input("Тест\n30\n5.0\n");
        ostringstream output;
        
        cin.rdbuf(input.rdbuf());
        cout.rdbuf(output.rdbuf());
        
        string name;
        int age;
        double average_score;
        
        cout << "Введите ваше имя: ";
        cin >> name;
        
        cout << "Введите ваш возраст: ";
        cin >> age;
        
        cout << "Введите ваш средний балл: ";
        cin >> average_score;
        
        cout << "Имя: " << name << endl;
        cout << "Возраст: " << age << endl;
        cout << fixed << setprecision(2);
        cout << "Средний балл: " << average_score << endl;
        
        string result = output.str();
        cin.rdbuf(origCin);
        cout.rdbuf(origCout);
        
        assert(result.find("5.00") != string::npos);
        cout << "✓ Тест форматирования 5.0 → 5.00 пройден\n";
    }
    
    // Тест 3: Проверка граничных значений возраста
    {
        streambuf* origCin = cin.rdbuf();
        streambuf* origCout = cout.rdbuf();
        
        stringstream input("Граница\n0\n10.0\n");
        ostringstream output;
        
        cin.rdbuf(input.rdbuf());
        cout.rdbuf(output.rdbuf());
        
        string name;
        int age;
        double average_score;
        
        cout << "Введите ваше имя: ";
        cin >> name;
        
        cout << "Введите ваш возраст: ";
        cin >> age;
        
        cout << "Введите ваш средний балл: ";
        cin >> average_score;
        
        cout << "Имя: " << name << endl;
        cout << "Возраст: " << age << endl;
        cout << fixed << setprecision(2);
        cout << "Средний балл: " << average_score << endl;
        
        string result = output.str();
        cin.rdbuf(origCin);
        cout.rdbuf(origCout);
        
        assert(result.find("Возраст: 0") != string::npos);
        cout << "✓ Тест нулевого возраста пройден\n";
    }
    
    cout << "=================================\n";
    cout << "Все тесты форматирования пройдены успешно!\n";
}

int main() {
    testNumberFormatting();
    return 0;
}