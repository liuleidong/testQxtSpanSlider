#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

public slots:
    void lowerValueChangedSlot(int);
    void upperValueChangedSlot(int);
    void lowerTextChangedSlot(const QString &text);
    void upperTextChangedSlot(const QString &text);
private:
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
