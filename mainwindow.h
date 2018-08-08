#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

namespace Ui {
class xMainWindow;
}

class xMainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit xMainWindow(QWidget *parent = nullptr);
    ~xMainWindow();

private:
    Ui::xMainWindow *ui;
};

#endif // MAINWINDOW_H
