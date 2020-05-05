#ifndef RENDERAREA_H
#define RENDERAREA_H

#include <QWidget>
#include <QColor>
#include <QPen>
class RenderArea : public QWidget
{
    Q_OBJECT
public:
    explicit RenderArea(QWidget *parent = nullptr);

    QSize minimumSizeHint() const override;
    QSize sizeHint() const override;

    enum ShapeType{Astroid, Cycloid, HuygensCycloid, HypoCycloid, Line, Circle, Ellipse, Fancy, Starfish, Cloud };

    void setBackgroundColor(QColor color) {mBackgroundColor = color; }
    QColor getBackgroundColor() const {return mBackgroundColor; }
    void setShapeColor(QColor color) {mPen.setColor(color); }
    QColor getShapeColor() const {return mPen.color(); }

    void setShape (ShapeType shape){mShape = shape; on_shape_changed();}
    ShapeType getShape ()const {return mShape;}
    void setScale(float scale){mScale = scale; repaint();}
    float getScale() const {return mScale;}

    void setInterval(float interval){mIntervalLength = interval; repaint();}
    float getInterval() const {return mIntervalLength;}
    void setStepCount(float count){mStepCount = count; repaint();}
    float getStepCount() const {return mStepCount;}

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
    QPointF compute_ellipse(float);
    QPointF compute_fancy(float);
    QPointF compute_starfish(float);
    QPointF compute_cloud(float);
    QPointF compute(float);
    QColor mBackgroundColor;
    ShapeType mShape;
    QPen mPen;
    QPointF compute_astroid(float);
    void on_shape_changed();
    float mScale;
    float mStepCount;
    float mIntervalLength;
};

#endif // RENDERAREA_H
