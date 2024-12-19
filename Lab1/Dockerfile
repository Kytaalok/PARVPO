# Используем базовый образ Alpine
FROM alpine:latest

# Установим необходимые пакеты: g++, git
RUN apk update && apk add --no-cache g++ git

# Установим рабочую директорию внутри контейнера
WORKDIR /app

# Склонируем ваш репозиторий с GitHub
RUN git clone https://github.com/Kytaalok/PARVPO.git

# Перейдём в директорию Lab
WORKDIR /app/PARVPO/Lab1

# Скомпилируем программу
RUN g++ cpu_load.cpp -o cpu_load -fopenmp

# При запуске контейнера выполняем программу, результат сохраняем на хост
CMD ["./cpu_load"]