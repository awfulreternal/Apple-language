#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <fstream>

using namespace std;

// Класс для работы с файловой системой
class FileSystem {
public:
  string readFile(const string& path) {
    ifstream file(path);
    if (file.is_open()) {
      string content;
      string line;
      while (getline(file, line)) {
        content += line + "\n";
      }
      file.close();
      return content;
    } else {
      // ... Обработка ошибки: файл не найден ...
      return "";
    }
  }

  void writeFile(const string& path, const string& content) {
    ofstream file(path);
    if (file.is_open()) {
      file << content;
      file.close();
    } else {
      // ... Обработка ошибки: ошибка записи ...
    }
  }

  // ... Другие функции для работы с файловой системой ...
};

// ... Другие определения ...
