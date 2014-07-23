#ifndef SYMBOL_H
#define SYMBOL_H

#include <QGraphicsItem>
#include <QPolygonF>
#include <QString>

class Link;

enum my_symbol { If, For, Bloc, Then, Else, ForBloc};

class Symbol : public QGraphicsItem
{
public:
    Symbol();
    Symbol(my_symbol);
    ~Symbol();
    my_symbol getSymbolMeaning();
    const char* getSymbolText();
    QString getcpp(QString);


    void setText(const QString &text);
    QString text() const;
    QRectF boundingRect() const;
    QPainterPath shape() const;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem * option, QWidget *widget);
    void mouseDoubleClickEvent(QGraphicsSceneMouseEvent *event);
    QVariant itemChange(GraphicsItemChange change, const QVariant &value);

    Link * from_link;
    Link * to_link;
    Link * then_link;
    Link * else_link;
    QRectF myPolygon;
    QPointF center;

private:
    my_symbol ms;

    QRectF outlineRect() const;
    int roundness(double size) const;
    QString myText;

};

#endif // SYMBOL_H
