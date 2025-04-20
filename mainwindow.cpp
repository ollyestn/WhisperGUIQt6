// #include "mainwindow.h"
// #include "./ui_mainwindow.h"

// MainWindow::MainWindow(QWidget *parent)
//     : QMainWindow(parent)
//     , ui(new Ui::MainWindow)
// {
//     ui->setupUi(this);
// }

// MainWindow::~MainWindow()
// {
//     delete ui;
// }

#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QFileDialog>
#include <QMessageBox>
#include <QClipboard>
#include <QTextStream>
#include <QProcess>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow) {
    ui->setupUi(this);
}

MainWindow::~MainWindow() {
    delete ui;
}

void MainWindow::on_btnChooseFile_clicked() {
    QString filePath = QFileDialog::getOpenFileName(this, "选择WAV文件", "", "WAV文件 (*.wav)");
    if (!filePath.isEmpty()) {
        ui->lineEditPath->setText(filePath);
    }
}

void MainWindow::on_btnRecognize_clicked() {
    QString path = ui->lineEditPath->text();
    if (path.isEmpty()) {
        QMessageBox::warning(this, "错误", "请先选择一个WAV文件！");
        return;
    }
    recognizeWavFile(path);
}

void MainWindow::recognizeWavFile(const QString& path) {
    QString cmd = QString("%1 -m \"%2\" -f \"%3\" -l zh %4 -otxt")
    .arg(whisperExePath)
        .arg(modelPath)
        .arg(path)
        .arg(prompt);

    // QMessageBox::information(this, "提示", cmd);
    ui->textEditOutput->append(cmd);
    QProcess::execute(cmd);
    QString txtPath = path + ".txt";
    appendTextFromFile(txtPath);
}

void MainWindow::appendTextFromFile(const QString& txtFilePath) {
    QFile file(txtFilePath);
    if (!file.open(QIODevice::ReadOnly | QIODevice::Text))
        return;

    QTextStream in(&file);
    QString content = in.readAll();
    file.close();

    ui->textEditOutput->append(content);
}

void MainWindow::on_btnCopy_clicked() {
    QClipboard *clipboard = QApplication::clipboard();
    clipboard->setText(ui->textEditOutput->toPlainText());
}

void MainWindow::on_btnExit_clicked() {
    QApplication::quit();
}

void MainWindow::on_btnSave_clicked() {
    QString savePath = QFileDialog::getSaveFileName(this, "保存为", "", "文本文件 (*.txt)");
    if (!savePath.isEmpty()) {
        QFile file(savePath);
        if (file.open(QIODevice::WriteOnly | QIODevice::Text)) {
            QTextStream out(&file);
            out << ui->textEditOutput->toPlainText();
            file.close();
        }
    }
}

void MainWindow::on_btnRecordAndRecognize_clicked() {
    QProcess::execute("record_audio.exe"); // 需预先准备好
    recognizeWavFile(tempRecordPath);
}
