#include "salarios.h"
#include "ui_salarios.h"

Salarios::Salarios(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::Salarios)
{
    ui->setupUi(this);
    m_control = new Controlador();
}

Salarios::~Salarios()
{
    delete ui;
}


void Salarios::on_btnCalcular_clicked()
{
    // Obtener los datos de la GUI

    QString nombre = ui->intNombre->text();

    int horas = ui->intHoras->value();

    TipodeJornada jornada;

    if(ui->intMatutina->isChecked()){
        jornada = TipodeJornada::Matutina;
    }else if (ui->intVespertina->isChecked()){
        jornada = TipodeJornada::Vespertina;
    }else{
        jornada = TipodeJornada::Nocturna;
    }

    //Validar datos
    if(nombre == "" || horas == 0){
        QMessageBox::warning(this,"Advertencia","El nombre y/o el numero de horas es incorrecto");
        return;
    }

    // Establecer datos
    m_control->setDatos(nombre, horas, jornada);

    // Calcular salarios
    if(m_control->calcular()){
        // Mostrar los resultados
        ui->outTexto->appendPlainText(m_control->getDatos());
    }else{
        QMessageBox::critical(this,"ERROR","No se puede calcular el salario");
    }

    // Limpiar widgets
    ui->intNombre->setText("");
    ui->intHoras->setValue(0);
    ui->intMatutina->setChecked(true);
    ui->intNombre->setFocus();

    // Mostrar mensaje de estado

    ui->statusbar->showMessage("Salario de " + nombre + " calculado",5000);
}

