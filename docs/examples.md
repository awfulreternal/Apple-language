# Примеры кода на Apple

## Telegram-бот

```apple
pick telegram.sendMessage;
pick telegram.getUpdates;
pick telegram.onMessage;

var chatId: int = 123456789; // ID чата

onMessage(func(message: telegram.message) -> void {
  if message.text == "Hello" {
    sendMessage(message.chat.id, "Hello to you too!");
  } else {
    sendMessage(message.chat.id, "I don't understand.");
  }
});

## Веб-сайт

pick web.createServer;
pick web.sendResponse;
pick web.on_request;

func handleRequest(request: web.request) -> void {
  web.sendResponse(request, "<h1>Welcome to my Apple website!</h1>");
}

var server: web.server = createServer(8080);
server.on_request(handleRequest);


# GUI-приложение

pick gui.createWindow;
pick gui.createButton;

func handleClick(event: gui.event) -> void {
  print("Button clicked!");
}

var window: gui.window = createWindow("My Apple App", 400, 300);
var button: gui.button = createButton("Click me!");
button.on_click(handleClick); // Обработчик события нажатия на кнопку
window.add(button);
window.show();
