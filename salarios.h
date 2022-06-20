#ifndef SALARIOS_H
#define SALARIOS_H

#include "obrero.h"
#include "controlador.h"

#include <QDebug>
#include <QMainWindow>
#include <QMessageBox>
#include <QFileDialog>

QT_BEGIN_NAMESPACE
namespace Ui { class Salarios; }
QT_END_NAMESPACE

class Salarios : public QMainWindow
{
    Q_OBJECT

public:
    Salarios(QWidget *parent = nullptr);
    ~Salarios();

private slots:

    void on_btnCalcular_clicked();

    void on_actionNuevo_triggered();

    void on_actionCalcular_triggered();

    void on_actionSalir_triggered();

    void on_actionGuardar_triggered();

private:
    Ui::Salarios *ui;
    Controlador *m_control;
    void limpiar();
    void calcular();
};
#endif // SALARIOS_H
