#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include <lesson.h>
#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

public slots:
    void findAuditory();
    void addToVector();

private:
    Ui::MainWindow *ui;

    std::vector<Lesson> lessons;

};
#endif // MAINWINDOW_H
