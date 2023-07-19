def convertString(input_string, encoding):
    with open('codemap.txt', 'r', encoding='utf-8') as f:
        for line in f:
            chinese, utf8, big5 = line.split()
            if chinese == input_string:
                if encoding == 'utf-8':
                    return int(utf8)
                else:
                    return int(big5)
    return -1

inputString = input("輸入你要轉換的中文句子：")
encoding = input("選擇輸出編碼：(utf-8 或 big5)： ")
if encoding not in ['utf-8', 'big5']:
    print("不支援所選編碼！")
else:
    print("請把以下輸出複製到 Arduino 的按鍵輸出功能下：\n")
    for char in inputString:
        zhCharCode = convertString(char,encoding)
        if (zhCharCode is -1):
            print("Keyboard_write('" + char + "');")
        else:
            print('typeChinese("' + str(zhCharCode) + '"); //' + char)

