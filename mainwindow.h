#ifndef MAINWINDOW_H
#define MAINWINDOW_H

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

private slots:
    void on_btnAstroid_clicked();

    void on_btnCycloid_clicked();

    void on_btnHuygens_clicked();

    void on_btnHypoCycloid_clicked();

    void on_btnLine_clicked();

    void on_spinScale_valueChanged(double arg1);

    void update_ui();

    void on_spinInterval_valueChanged(double arg1);

    void on_spinCount_valueChanged(int arg1);

    void on_btnBackground_clicked();

    void on_btnPen_clicked();

    void on_btnCircle_clicked();

    void on_btnEllipse_clicked();

private:
    Ui::MainWindow *ui;
};
#endif // MAINWINDOW_H
