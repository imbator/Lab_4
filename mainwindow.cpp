#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <string>
#include "csvreader.h"
#include <iostream>
#include "csvwriter.h"
#include "json.hpp"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    // открытие файла
    CSVReader csv("schedule_database.csv");
    if (csv.is_open())
    {
         lessons = csv.readAll();

        // Чтение из файла в вектор
        // Поиск
        // Вывод в файл

    }
}

MainWindow::~MainWindow()
{
    CSVWriter csv("schedule_database_output.csv");
    csv.WriteAll(lessons);
    std::cout << "Database has been succesfuly updated." << std::endl;
    delete ui;
}




void MainWindow::findAuditory()
{
    // ui->textBrowser->append(ui->editSearch->text());
    int researched_size = 0;
    int showUp_par = -1;
    for (auto &e: lessons)
    {
        if ((e.title).right((e.title).size() - 1) == ui->editSearch->text())
        {
            ui->textBrowser->appendGreen(e.title + "," + QString::number(e.auditory) + "," + e.enum_def(e.type));
            showUp_par = 1;
        }
        researched_size += 1;
        if (researched_size == int (lessons.size()) && showUp_par == -1)
        {
            ui->textBrowser->appendRed("Искомая позиция не найдена.");
            researched_size = 0;
        }
    }
    showUp_par = -1;
}



void MainWindow::addToVector()
{
    Lesson c;
    c.number = (ui->editID->text()).toInt();
    c.title = ui->editTitle->text();
    c.auditory = (ui->editAuditory->text()).toInt();
    QString tempo;
    tempo = (ui->comboType->currentText());
    if (tempo == "lecture")
    {
        c.type =  static_cast<lesson_type>(0);
    }
    if (tempo=="practice")
    {
      c.type = static_cast<lesson_type>(1);
    }
    if (tempo == "laboratoty")
    {
        c.type = static_cast<lesson_type>(2);
    }
    else c.type = static_cast<lesson_type>(3);
    lessons.push_back(c);
    std::cout<<"Added"<<std::endl;
    std::cout<<"Database now have " << lessons.size() << " slots" << std::endl;

}





















