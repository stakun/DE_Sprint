# Импортируем ранее установленные библиотеки
import requests as req
from bs4 import BeautifulSoup

# Запишем основной URL
url = ""

# Запрашиваем данные с сайта
resp = req.get(url)

# Выведем текст с запрошенной страницы
print(resp.text)

# Создаем элемент класса-парсера BeatifulSoup
#soup = BeautifulSoup(resp.text, "lxml")

#tag = soup.find(attrs={"data-marker": "page-title/text"})
# print(tag)
