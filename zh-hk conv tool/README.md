# Zh-HK Conversion Tool

This tool is designed to work with Python 3 and convert any Traditional Chinese sentence into their corrisponding utf-8 keypress sequence or ALT+DEC CODE for Windows applications.



## Usage

To use this tool, you first need to copy and paste the "win-zh_util.h" file in to the same folder as your arduino .ino file. Next, import the util script into your Arduino code that emulate a USB HID keyboard

```arduino
#include "win-zh_util.h"
```

then you open python IDLE and execute the convert.py file. Follow the on-screen description to enter your setenece and select an encoding method. Here are some example usecase

```
輸入你要轉換的中文句子：這是 big5 的中文輸出
選擇輸出編碼：(utf-8 或 big5)： big5
請把以下輸出複製到 Arduino 的按鍵輸出功能下：

typeChinese("36889"); //這
typeChinese("26159"); //是
Keyboard_write(' ');
Keyboard_write('b');
Keyboard_write('i');
Keyboard_write('g');
Keyboard_write('5');
Keyboard_write(' ');
typeChinese("30340"); //的
typeChinese("20013"); //中
typeChinese("25991"); //文
typeChinese("36664"); //輸
typeChinese("20986"); //出
```

```
輸入你要轉換的中文句子：這是 UTF-8 的中文輸出
選擇輸出編碼：(utf-8 或 big5)： utf-8
請把以下輸出複製到 Arduino 的按鍵輸出功能下：

typeChinese("45935"); //這
typeChinese("44111"); //是
Keyboard_write(' ');
Keyboard_write('U');
Keyboard_write('T');
Keyboard_write('F');
Keyboard_write('-');
Keyboard_write('8');
Keyboard_write(' ');
typeChinese("43706"); //的
typeChinese("42148"); //中
typeChinese("42213"); //文
typeChinese("49129"); //輸
typeChinese("42328"); //出
```

Afterward, copy the code into your Arduino code and modify anything required.




