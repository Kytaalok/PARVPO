#include <iostream>
#include <chrono>
#include <thread>

int main() {
    auto start = std::chrono::steady_clock::now();
    // Нагрузим процессор. Например, будем искать простые числа или просто крутить цикл.
    // Для простоты просто организуем цикл по времени ~30 секунд.

    while (true) {
        auto now = std::chrono::steady_clock::now();
        std::chrono::duration<double> elapsed = now - start;
        if (elapsed.count() >= 30.0) {
            // Когда прошло 30 секунд, завершаем
            std::cout << "Время работы: " << elapsed.count() << " секунд\n";
            break;
        }
        // Цикл без сна — максимальная загрузка CPU
        // Можно добавить какую-нибудь "бесполезную" операцию для симуляции работы
        double x = 0;
        for (int i=0; i<1000000; i++) {
            x += i*i;
        }
    }

    return 0;
}