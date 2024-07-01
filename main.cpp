//#include <QCoreApplication>

//int main(int argc, char *argv[])
//{
//    QCoreApplication a(argc, argv);

//    return a.exec();
//}
#include <QCoreApplication>
#include <QFile>
#include <QTextStream>
#include <QRandomGenerator64>
#include <iostream>

int main(int argc, char *argv[]) {
    QCoreApplication a(argc, argv);

    // Имя файла для записи
    QString filename = "/home/viktor/my_projects_qt_2/Sgenerirovannye_fayly/1-1/sinapsi.txt";
    QFile file(filename);

    // Открываем файл для записи
    if (!file.open(QIODevice::WriteOnly | QIODevice::Text)) {
        std::cerr << "Unable to open file for writing!" << std::endl;
        return 1;
    }

    QTextStream out(&file);

    // Генератор случайных чисел
    QRandomGenerator64 randomGenerator;

    // Генерация и запись 10105 строк
    int count = 0;
    while (count < 10105) {
        long long int randomValue = randomGenerator.generate64();

        // Проверка на ноль
        if (randomValue != 0) {
            out << randomValue << "\n";
            ++count;
        }
    }

    // Закрываем файл
    file.close();

    std::cout << "Successfully generated 10105 numbers and wrote to " << filename.toStdString() << std::endl;

    return 0;
}
