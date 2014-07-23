#include "symbol.h"
#include "QApplication"
#include <QFontMetricsF>
#include <QPixmap>
#include <QPainter>
#include <QInputDialog>
#include <QGraphicsSceneMouseEvent>
#include <QStyleOptionGraphicsItem>
#include <QPolygonF>
#include <QPointF>
#include <QLine>
#include <QList>
#include <QGraphicsItem>
#include <link.h>
#include <QString>
using namespace std;

Symbol::Symbol()
{
}

Symbol::Symbol(my_symbol ms)
{
    this->ms = ms;
    setFlags(ItemIsMovable | ItemIsSelectable | ItemSendsScenePositionChanges);
    from_link = NULL;
    to_link = NULL;
    then_link = NULL;
    else_link = NULL;
}

Symbol::~Symbol()
{
    delete from_link;
    delete to_link;
    delete then_link;
    delete else_link;
}


my_symbol Symbol::getSymbolMeaning()
{
    return this->ms;
}

const char* Symbol::getSymbolText()
{
    switch (this->ms)
    {
        case If :
            return "If";
        case For :
            return "For";
        case Bloc :
            return "Bloc";
        case Then :
            return "Then";
        case Else :
            return "Else";
        case ForBloc :
            return "Instructions";
        default:
           return "";
      }
}

void Symbol::setText(const QString &text)
{
    prepareGeometryChange();
    myText = text;
    update();
}

QRectF Symbol::outlineRect() const
{
    const int Padding = 8;
    QFont myFont = qApp->font();

    QFontMetricsF metrics(myFont); //ou option->fontmetrics
    QRectF rect = metrics.boundingRect(myText);
    rect.adjust(-Padding, -Padding, +Padding, +Padding);
    rect.translate(-rect.center());
    return rect;
}

QRectF Symbol::boundingRect() const
{
    const int Margin = 1;
    return outlineRect().adjusted(-Margin, -Margin, +Margin, +Margin);
}

QPainterPath Symbol::shape() const
{
    QRectF rect = outlineRect();

    QPainterPath path;
    path.addRoundRect(rect, roundness(rect.width()),
                      roundness(rect.height()));
    return path;
}

void Symbol::paint(QPainter *painter, const QStyleOptionGraphicsItem * option,
                 QWidget * /* widget */)
{

    QPen pen(Qt::darkBlue);

    if (option->state & QStyle::State_Selected) {
        pen.setStyle(Qt::DotLine);
        pen.setWidth(2);
    }
    painter->setPen(pen);
    painter->setBrush(Qt::white);

    myPolygon = outlineRect();
    switch (this->ms)
    {
        case If :
    {
            painter->drawEllipse(myPolygon);
            break;
    }
        case For :
       {
            painter->drawRect(myPolygon);
            break;
    }
        case Bloc :
            painter->drawRoundRect(myPolygon, roundness(myPolygon.width()), roundness(myPolygon.height()));
            break;
        default:
            painter->drawRoundRect(myPolygon, roundness(myPolygon.width()), roundness(myPolygon.height()));
      }

    painter->setPen(Qt::darkGreen);
    painter->drawText(myPolygon, Qt::AlignCenter, myText);

}

QVariant Symbol::itemChange(GraphicsItemChange change,
                          const QVariant &value)
{
    if (change == ItemPositionHasChanged) {
        if (from_link != NULL)
            from_link->trackNodes();
        if (to_link != NULL)
            to_link->trackNodes();
        if (then_link != NULL)
            then_link->trackNodes();
        if (else_link != NULL)
            else_link->trackNodes();
        center = value.toPointF();
    }
    return QGraphicsItem::itemChange(change, value);
}

void Symbol::mouseDoubleClickEvent(QGraphicsSceneMouseEvent *event)
{
    QString text = QInputDialog::getText(event->widget(),"Edit Instruction", "Enter new text:",
                           QLineEdit::Normal, myText);
    if (!text.isEmpty())
        setText(text);
}

int Symbol::roundness(double size) const
{
    const int Diameter = 12;
    return 100 * Diameter / int(size);
}

QString Symbol::getcpp(QString res){
    switch (this->ms)
    {
        case If :
            //return myText + " \n {"+ then_link->toNode()->to_link->toNode()->getcpp(res) + "} \n else { \n" + else_link->toNode()->to_link->toNode()->getcpp(res) + "}";
            return myText + " { \n "+ then_link->toNode()->to_link->toNode()->getcpp(res) + "\n } else { \n" + else_link->toNode()->to_link->toNode()->getcpp(res);
        case For :
            return "For";
        case Bloc :
            return myText;
        case Then :
            return "{"+ to_link->toNode()->getcpp(res) + "}";
        case Else :
            return " else {" + to_link->toNode()->getcpp(res) + "}";
        case ForBloc :
            return "Instructions";
        default:
           return "";
      }
}
