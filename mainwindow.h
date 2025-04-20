// #ifndef MAINWINDOW_H
// #define MAINWINDOW_H

// #include <QMainWindow>

// QT_BEGIN_NAMESPACE
// namespace Ui {
// class MainWindow;
// }
// QT_END_NAMESPACE

// class MainWindow : public QMainWindow
// {
//     Q_OBJECT

// public:
//     MainWindow(QWidget *parent = nullptr);
//     ~MainWindow();

// private:
//     Ui::MainWindow *ui;
// };
// #endif // MAINWINDOW_H

#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow {
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_btnChooseFile_clicked();
    void on_btnRecognize_clicked();
    void on_btnCopy_clicked();
    void on_btnExit_clicked();
    void on_btnSave_clicked();
    void on_btnRecordAndRecognize_clicked();

private:
    void recognizeWavFile(const QString& path);
    void appendTextFromFile(const QString& txtFilePath);

    Ui::MainWindow *ui;

    QString whisperExePath = ".\\whisper.cpp\\build\\bin\\Release\\whisper-cli.exe";
    QString modelPath = "./whisper.cpp/models/ggml-base.bin";
    QString tempRecordPath = "record.wav";
    QString prompt = "--prompt \"这是一段会议记录。\" ";
};
#endif // MAINWINDOW_H
