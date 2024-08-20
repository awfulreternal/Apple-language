#include <iostream>
#include <vector>
#include <string>
#include <map>

using namespace std;

// Класс для создания графических интерфейсов
class Gui {
public:
  void createWindow(const string& title, int width, int height) {
    cout << "Creating window: " << title << " (" << width << "x" << height << ")" << endl;
  }

  void createButton(const string& text) {
    cout << "Creating button: " << text << endl;
  }

  // ... Другие функции для работы с GUI ...
};

// ... Другие определения ...
