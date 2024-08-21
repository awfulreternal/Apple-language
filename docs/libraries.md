# Библиотеки Apple

## telegram

* `sendMessage(chatId: int, text: string)` - Отправка сообщения в Telegram.
* `getUpdates()` - Получение обновлений от Telegram.
* `onMessage(handler: func(telegram.message) -> void)` - Обработка входящих сообщений.

## web

* `createServer(port: int)` - Создание веб-сервера.
* `sendResponse(request: web.request, content: string)` - Отправка ответа на HTTP-запрос.
* `on_request(handler: func(web.request) -> void)` - Обработка входящих запросов.

## gui

* `createWindow(title: string, width: int, height: int)` - Создание окна.
* `createButton(text: string)` - Создание кнопки.

## database

* `connect(databaseName: string)` - Подключение к базе данных.
* `executeQuery(connection: database.connection, query: string)` - Выполнение SQL-запроса.

## network

* `sendHTTPRequest(url: string, method: string, data: dictionary<string, any>)` - Отправка HTTP-запроса.

## filesystem

* `readFile(path: string)` - Чтение файла.
* `writeFile(path: string, content: string)` - Запись в файл.
