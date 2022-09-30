from ast import dump
from dbm import dumb
from random import randint
from turtle import title
import requests as req
from bs4 import BeautifulSoup
import tqdm
import json
import time

data = {
    "data": []
}

# Для обхода антипарсинговой блокировки hh.ru устанавливаем заголовок
# 'user-agent': 'Mozilla/5.0 (X11; Linux x86_64) AppleWebKit/537.36 (KHTML, like Gecko) Chrome/103.0.0.0 Safari/537.36'
# Совет взят из чата курса в Телеграмме, спасибо неизвестному Андрею.


def headers():
    headers = dict()
    headers['user-agent'] = 'Mozilla/5.0 (X11; Linux x86_64) AppleWebKit/537.36 (KHTML, like Gecko) Chrome/103.0.0.0 Safari/537.36'
    return headers


for page in range(1, 200):
    # Базовый адрес страницы с поисковым запросом
    url = f"https://hh.ru/search/vacancy?no_magic=true&L_save_area=true&text=python+%D1%80%D0%B0%D0%B7%D1%80%D0%B0%D0%B1%D0%BE%D1%82%D1%87%D0%B8%D0%BA&area=113&salary=&currency_code=RUR&experience=doesNotMatter&order_by=relevance&search_period=0&items_on_page=100&page={page}&hhtmFrom=vacancy_search_list"

    # Получаем код страницы с поисковым запросом
    resp = req.get(url, headers=headers())

    # Обработка html-кода страницы с поисковым запросом
    # Создаем класс парсера BeautifulSoup
    soup = BeautifulSoup(resp.text, "lxml")

    #tags = soup.find_all(attrs={"data-qa": "serp-item__title"})
    tags = soup.find_all(class_="vacancy-serp-item-body")

    if len(tags) == 0:
        break

    for iter in tqdm.tqdm(tags):

        tag_title = iter.find(attrs={"data-qa": "serp-item__title"})
        tag_region = iter.find(
            attrs={"data-qa": "vacancy-serp__vacancy-address"}).text

        resp_object = req.get(tag_title.attrs["href"], headers=headers())
        soup_object = BeautifulSoup(resp_object.text, "lxml")

        tag_work_exp = soup_object.find(
            attrs={"data-qa": "vacancy-experience"}).text
        tag_salary = soup_object.find(
            attrs={"data-qa": "vacancy-salary"}).text

        # Заполняем запись
        data["data"].append(
            {"title": tag_title.text, "work experience": tag_work_exp, "salary": tag_salary, "region": tag_region})

        # Записываем в json файл
        with open("data.json", "w", encoding="utf8") as file:
            json.dump(data, file, ensure_ascii=False)

        time.sleep(randint(1, 3))  # эмулируем человека
