# Импортируем ранее установленные библиотеки
# import requests as req
from requests_tor import RequestsTor
from bs4 import BeautifulSoup
import json
import tqdm
import time


# Создаем контейнер, куда будут сохраняться данные парсинга
data = {
    "data": []
}


req = RequestsTor()

# Запишем основной URL
# url = "https://www.avito.ru/all/vakansii?cd=1&q=python"

# Запрашиваем данные с сайта
# resp = req.get(url)

# Выведем текст с запрошенной страницы
# print(resp.text)  # выводим на экран полный текст запрошенной страницы

# Создаем элемент класса-парсера BeatifulSoup
# soup = BeautifulSoup(resp.text, "lxml")

# Ищем тег по атрибуту
# tag = soup.find(attrs={"data-marker": "page-title/text"})
# print(tag.text)  # вывести на экран текст тэга
# print(tag.attrs["class"])  # вывести на экран класс тэга

# Ищем тег по имени
# tag = soup.find_all("a")
# print(tag)

# Ищем тэг по классу
# tag = soup.find_all(class_="Logo-module-root-_kAtn")
# print(tag)

# Ищем тэг по id
# tag = soup.find_all(id_="Logo-module-root-_kAtn")
# print(tag)

# Ищем тег вакансии по атрибуту data-marker="item-title"
# tags = soup.find_all(attrs={"data-marker": "item-title"})
# print(tags)

for page in range(1, 3):  # перебираем страницы в поисковой выдаче (в примере их 2)

    # Запишем основной URL c учетом страницы поисковой выдачи
    url = f"https://www.avito.ru/all/vakansii?cd=1&p={page}&q=python"
    # Запрашиваем данные с сайта
    resp = req.get(url)

    # Создаем элемент класса-парсера BeatifulSoup
    soup = BeautifulSoup(resp.text, "lxml")

    # Ищем тег вакансии по атрибуту data-marker="item-title"
    tags = soup.find_all(attrs={"data-marker": "item-title"})

    for iter in tqdm.tqdm(tags):  # перебираем в цикле все найденные теги
        #    print(iter.text, iter.attrs["href"])

        # Ставим прерывание запросов парсинга
        time.sleep(2)

        # Запишем url для страниц с вакансиями
        url_object = "https://www.avito.ru" + iter.attrs["href"]

    # Парсим каждую страницу вакансий аналогично странице поиска
        resp_object = req.get(url_object)
        soup_object = BeautifulSoup(resp_object.text, "lxml")
        tag_price = soup_object.find(attrs={"itemprop": "offers"}).find(
            attrs={"itemprop": "price"}).text

    #    print(iter.text, tag_price)

        tag_region = soup_object.find(
            attrs={"itemtype": "http://schema.org/ListItem"}).find_all(attrs={"itemprop": "name"})[0].text

        #print(iter.text, tag_price, tag_region)

        data["data"].append(
            {"Title": iter.text, "Salary": tag_price, "Region": tag_region})

        with open("data.json", "w", encoding='utf-8') as file:
            json.dump(data, file, ensure_ascii=False)
