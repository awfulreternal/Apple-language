# Синтаксис Apple

## Комментарии

```apple
// Однострочный комментарий
/* Многострочный комментарий */

# Переменные

```apple
var name: string = "John"; // Объявление переменной типа string
let age: int = 30; // Объявление константы типа int

## Функции

func greet(name: string) -> void { 
  print("Hello, " + name); 
}

## Условные операторы

if age > 18 {
  print("You are an adult.");
} else {
  print("You are a minor.");
}

# Циклы

for i in 1...10 {
  print(i);
}

## Массивы

var fruits: array<string> = ["apple", "banana", "orange"];
print(fruits[0]); // Вывод: "apple"

# Словари

var person: dictionary<string, any> = { name: "John", age: 30 };
print(person["name"]); // Вывод: "John"

## Импорты (1)

pick telegram.sendMessage; // "Сорвать" функцию из библиотеки

