#ifndef RENDERAREA_H
#define RENDERAREA_H

#include <QWidget>
#include<QColor>
class RenderArea : public QWidget
{
    Q_OBJECT
public:
    explicit RenderArea(QWidget *parent = nullptr);

    QSize minimumSizeHint() const override;
    QSize sizeHint() const override;

    enum ShapeType{Astroid, Cycloid, HuygensCycloid, HypoCycloid };

    void setBackgroundColor(QColor color) {mBackgroundColor = color; }
    QColor getBackgroundColor() const {return mBackgroundColor; }

    void setShape (ShapeType shape){mShape = shape;}
    ShapeType getShape ()const {return mShape;}

protected:
    void paintEvent(QPaintEvent *event) override;

signals:

private:
    QColor mBackgroundColor;
    QColor mShapeColor;
    ShapeType mShape;
    QPointF compute_astroid(float t);
};

#endif // RENDERAREA_H
