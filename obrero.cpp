#include "obrero.h"

Obrero::Obrero(QObject *parent)
    : QObject{parent}
{

}

Obrero::Obrero(const QString &nombre, int horas, TipodeJornada jornada) : m_nombre(nombre),
    m_horas(horas),
    m_jornada(jornada)
{}

const QString &Obrero::nombre() const
{
    return m_nombre;
}

void Obrero::setNombre(const QString &newNombre)
{
    m_nombre = newNombre;
}

int Obrero::horas() const
{
    return m_horas;
}

void Obrero::setHoras(int newHoras)
{
    m_horas = newHoras;
}

TipodeJornada Obrero::jornada() const
{
    return m_jornada;
}

void Obrero::setJornada(TipodeJornada newJornada)
{
    m_jornada = newJornada;
}

double Obrero::salarioBruto() const
{
    return m_salarioBruto;
}

void Obrero::setSalarioBruto(double newSalarioBruto)
{
    m_salarioBruto = newSalarioBruto;
}

double Obrero::salarioNeto() const
{
    return m_salarioNeto;
}

void Obrero::setSalarioNeto(double newSalarioNeto)
{
    m_salarioNeto = newSalarioNeto;
}

double Obrero::descuento() const
{
    return m_descuento;
}

void Obrero::setDescuento(double newDescuento)
{
    m_descuento = newDescuento;
}

QString Obrero::toString()
{
    QString str = "";
    str.append("Nombre: " + m_nombre + "\n");
    str.append("Jornada: " + jornada2String() + "\n");
    str.append("Horas: " + QString::number(m_horas) + "\n");
    str.append("Salario Bruto: " + QString::number(m_salarioBruto) + "\n");
    str.append("Descuento: " + QString::number(m_descuento) + "\n");
    str.append("Salario Neto: " + QString::number(m_salarioNeto) + "\n");
    return str;
}

QString Obrero::jornada2String()
{
    switch (m_jornada) {
    case TipodeJornada::Matutina:
        return "Matutina";
        break;
    case TipodeJornada::Vespertina:
        return "Vespertina";
        break;
    case TipodeJornada::Nocturna:
        return "Nocturna";
        break;
    default:
        return "";
    }
}