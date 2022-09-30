# Задание подготовлено на основе разбора задачи
# https://www.youtube.com/watch?v=P0KAGIlZV94
#
# Палиндромы для проверки:
# топот
# я иду с мечем судия
# Вон у батыров своры табунов
# Делу — тело, лету — лед
# А за работу дадут? — Оба раза!

from dataclasses import replace


def if_palin1(str):  # проверка методом среза
    return str == str[::-1]


def if_palin2(str):  # проверка пребором по индексу символа в строке
    str1 = ''
    for i in range(len(str)-1, -1, -1):
        str1 += str[i]
    return str == str1


def if_palin3(str):  # модифицированная проверка методом среза

    # Исключение пробелов из строки методами split() и join()
    # str = ''.join(str.split())

    # Задаем набор исключаемых из строки символов
    exclude_list = [' ', '.', ',', '?', '-', '—', ':', '!']

    # Исключение пробелов, знаков препинания и других символов из строки методом replace()
    # и преобразование прописных букв в строчные
    for symbol in exclude_list:
        str = str.replace(symbol, '').lower()
    # print(str)
    # print(str[::-1])
    return str == str[::-1]


s1 = "А за работу дадут? — Оба раза!"

# print(if_palin1(s1))
# print(if_palin2(s1))
print(if_palin3(s1))
