#include <iostream>
#include <vector>
#include <string>
#include <map>

using namespace std;

// Класс для работы с Telegram API
class Telegram {
public:
  void sendMessage(int chatId, const string& text) {
    cout << "Sending message to chat ID " << chatId << ": " << text << endl;
  }

  // ... Другие функции Telegram API ...
};

// ... Другие определения ...
