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

    enum ShapeType{Astroid, Cycloid, HuygensCycloid, HypoCycloid, Line, Circle };

    void setBackgroundColor(QColor color) {mBackgroundColor = color; }
    QColor getBackgroundColor() const {return mBackgroundColor; }
    void setShapeColor(QColor color) {mShapeColor = color; }
    QColor getShapeColor() const {return mShapeColor; }

    void setShape (ShapeType shape){mShape = shape; on_shape_changed();}
    ShapeType getShape ()const {return mShape;}
    void setScale(float scale){mScale = scale; repaint();}
    float getScale() const {return mScale;}

    void setInterval(float interval){mIntervalLength = interval; repaint();}
    float getInterval() const {return mIntervalLength;}
    void setStepCount(int count){mStepCount = count; repaint();}
    int getStepCount() const {return mStepCount;}

protected:
    void paintEvent(QPaintEvent *event) override;

signals:

private:
    void update_ui();
    QPointF compute_cycloid(float);
    QPointF compute_hypocycloid(float);
    QPointF compute_huygens(float);
    QPointF compute_line(float);
    QPointF compute_circle(float);
    QPointF compute(float);
    QColor mBackgroundColor;
    QColor mShapeColor;
    ShapeType mShape;
    QPointF compute_astroid(float);
    void on_shape_changed();
    int mScale;
    int mStepCount;
    float mIntervalLength;
};

#endif // RENDERAREA_H
