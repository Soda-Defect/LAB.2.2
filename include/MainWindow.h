#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include "WindowInt.h"
#include <QApplication>
int  run(int argc, char *argv[]){
    QApplication a(argc, argv);
    QStringList types = {"Целые числа", "Вещественные числа", "Символы", "Строки"};
    bool ok;
    QString choice = QInputDialog::getItem(nullptr, "Выбор типа данных",
                                           "Выберите тип данных для последовательностей:",
                                           types, 0, false, &ok);
    if (!ok || choice.isEmpty())
        return 0;

    if (choice == "Целые числа") {
        MainWindowInt w;
        w.show();
        return a.exec();
    return 1;
}
#endif // MAINWINDOW_H