# Используем базовый образ Alpine
FROM alpine:latest

# Установим необходимые пакеты: g++, git
RUN apk update && apk add --no-cache g++ git

# Установим рабочую директорию внутри контейнера
WORKDIR /app

COPY cpu_load.cpp .

# Скомпилируем программу
RUN g++ cpu_load.cpp -o cpu_load -fopenmp

# При запуске контейнера выполняем программу, результат сохраняем на хост
CMD ["./cpu_load"]