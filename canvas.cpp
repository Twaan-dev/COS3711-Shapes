#include "canvas.h"
#include <QPainter>
//#include <QDebug>

Canvas::Canvas(QWidget *parent) :
    QWidget(parent)
{
    setBackgroundRole(QPalette::Base);
    setAutoFillBackground(true);
    //p = new QPainter(this);


}
QSize Canvas::minimumSizeHint() const
{
    return QSize(400, 200);
}
QSize Canvas::sizeHint() const
{
    return QSize(600, 600);
}

void Canvas::setDetails(int prop1, int prop2, QString shape, int penW, QColor penC, QColor fill)
{

    m_prop1=prop1;
    m_prop2=prop2;
    m_shape = shape;
    m_pen.setColor(penC);
    m_pen.setWidth(penW);
    if(penW == 0) m_pen.setStyle(Qt::NoPen);
    else  m_pen.setStyle(Qt::SolidLine);
    m_brush.setColor(fill);
    m_brush.setStyle(Qt::SolidPattern);

    update();
}



void Canvas::paintEvent(QPaintEvent * /* event */)
{
    QPainter painter(this);
    painter.setBrush(m_brush);
    painter.setPen(m_pen);
//    p->setBrush(m_brush);
//    p->setPen(m_pen);

    if(m_shape == "Square"){
        QRectF rect((this->size().width()-m_prop1)/2, (this->size().height()-m_prop1)/2, m_prop1, m_prop1);
        //painter.drawRect(rect);
        painter.drawRect(rect);
    }
    else if(m_shape == "Circle"){
        QRectF rect((this->size().width()-m_prop1)/2, (this->size().height()-m_prop1)/2, m_prop1, m_prop1);
        //painter.drawChord(rect,0,5760);
        painter.drawChord(rect,0,5760);
    }
    else if(m_shape == "Rectangle"){
        QRectF rect((this->size().width()-m_prop1)/2, (this->size().height()-m_prop2)/2, m_prop1, m_prop2);
        //painter.drawRect(rect);
        painter.drawRect(rect);
    }
    else if(m_shape == "Elipse"){
        QRectF rect((this->size().width()-m_prop1)/2, (this->size().height()-m_prop2)/2, m_prop1, m_prop2);
        //painter.drawChord(rect, 0, 5760);
        painter.drawChord(rect, 0, 5760);
    }

}
QPainter *Canvas::getP() const
{
    return p;
}

void Canvas::setP(QPainter *value)
{
    p = value;
}

QBrush Canvas::brush() const
{
    return m_brush;
}

void Canvas::setBrush(const QBrush &brush)
{
    m_brush = brush;
}

QPen Canvas::pen() const
{
    return m_pen;
}

void Canvas::setPen(const QPen &pen)
{
    m_pen = pen;
}

int Canvas::prop2() const
{
    return m_prop2;
}

void Canvas::setProp2(int prop2)
{
    m_prop2 = prop2;
}

int Canvas::prop1() const
{
    return m_prop1;
}

void Canvas::setProp1(int prop1)
{
    m_prop1 = prop1;
}


