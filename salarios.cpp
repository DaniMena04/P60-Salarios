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
   calcular();
}


void Salarios::on_actionNuevo_triggered()
{
    // Limpiar widgets
    limpiar();
    // Limpiar el texto de calculos
    ui->outTexto->clear();
    // Mostrar mensaje de estado
    ui->statusbar->showMessage("Nueva hoja de calculos de salario",3000);
}

void Salarios::limpiar()
{
    // Limpiar widgets
    ui->intNombre->setText("");
    ui->intHoras->setValue(0);
    ui->intMatutina->setChecked(true);
    ui->intNombre->setFocus();
}

void Salarios::calcular()
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
    limpiar();

    // Mostrar mensaje de estado
    ui->statusbar->showMessage("Salario de " + nombre + " calculado",5000);
}


void Salarios::on_actionCalcular_triggered()
{
    calcular();
}


void Salarios::on_actionSalir_triggered()
{
    this->close();
}


void Salarios::on_actionGuardar_triggered()
{
    // Abrir un cuadro de dialogo para seleccionar el path y archivo a guardadr
    QString nombreArchivo = QFileDialog::getSaveFileName(this,"Guardar Calculos de Salarios",QDir::home().absolutePath() + "/salarios.txt","Archivos de texto (*.txt)");

    // Crear un objeto
    QFile archivo(nombreArchivo);

    // Tratar de abrir el archivo
    if(archivo.open(QFile::WriteOnly | QFile::Truncate)){
        //Crear un objeto "stream" de texto
        QTextStream salida(&archivo);
        // Enviar los datos del resultado a la salida
        salida << ui->outTexto->toPlainText();
        // Mostrar mensaje en la barra de estados
        ui->statusbar->showMessage("Datos guardados en: " + nombreArchivo, 5000);
        // Crear el archivo
        archivo.close();
    }else{
        // Mensaje de error
        QMessageBox::warning(this,"Guardar archivo","Nose puede acceder al archivo para guardar los datos");
    }
}

