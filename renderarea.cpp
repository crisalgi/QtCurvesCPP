#include "renderarea.h"
#include <QPainter>
#include <QPaintEvent>
#include <QtMath>

RenderArea::RenderArea(QWidget *parent) : QWidget(parent),
    mBackgroundColor(0,0,255),
    mShapeColor (255,255,255),
    mShape(Astroid)
{
    on_shape_changed();
}

QSize RenderArea::minimumSizeHint() const
{
    return QSize(100,100);
}

QSize RenderArea::sizeHint() const
{
    return QSize(400,200);
}

QPointF RenderArea::compute_astroid(float t){
    float cos_t = cos(t);
    float sin_t = sin(t);
    float x = 2*cos_t*cos_t*cos_t;
    float y = 2*sin_t*sin_t*sin_t;
    return QPointF(x,y);
}

QPointF RenderArea::compute(float t){
    switch (mShape) {
    case Cycloid:
        return compute_cycloid(t);
        break;
    case HypoCycloid:
         return compute_hypocycloid(t);
         break;
    case HuygensCycloid:
        return compute_huygens(t);
        break;
    case Astroid:
       return compute_astroid(t);
        break;
    case Line:
       return compute_line(t);
        break;
    }
}

QPointF RenderArea::compute_cycloid(float t){
    return QPointF(
                1.5* (1-cos(t)),
                1.5* (t-sin(t))
    );
}

QPointF RenderArea::compute_huygens(float t){
    return QPointF(
                4* (3*cos(t) - cos(3*t)),
                4* (3*sin(t) - sin(3*t))
    );

}

QPointF RenderArea::compute_hypocycloid(float t){
    return QPointF(
                1.5 * (2*cos(t) + cos(2*t)),
                1.5 * (2*sin(t) - sin(2*t))
    );
}

QPointF RenderArea::compute_line(float t){
    return QPointF(
                1-t,
                1-t
    );
}

void RenderArea::on_shape_changed(){

    switch (mShape) {

    case Cycloid:
            mScale = 4;
            mIntervalLength = 6 * M_PI;
            mStepCount = 128;
        break;
    case HypoCycloid:
            mScale = 15;
            mIntervalLength = 2 * M_PI;
            mStepCount = 256;
         break;
    case HuygensCycloid:
            mScale = 4;
            mIntervalLength = 4 * M_PI;
            mStepCount = 256;
        break;
    case Astroid:
           mScale = 40;
           mIntervalLength = 2 * M_PI;
           mStepCount = 256;
        break;
    case Line:
           mScale = 50;
           mIntervalLength = 1;
           mStepCount = 256;
        break;
    }
}

void RenderArea::paintEvent(QPaintEvent *event)
{
   Q_UNUSED(event);
   QPainter painter(this);

   painter.setRenderHint(QPainter::Antialiasing, true);



    painter.setPen(mShapeColor);
    painter.setBrush(mBackgroundColor);

   //drawing area
   painter.drawRect(this->rect());

   QPoint center = this->rect().center();
   QPointF prevPoint = compute(0);
   QPoint prevPixel;
   prevPixel.setX(prevPoint.x() * mScale + center.x());
   prevPixel.setY(prevPoint.y() * mScale + center.y());
   float step = mIntervalLength / mStepCount;

   for(float t = 0; t< mIntervalLength; t += step){
       QPointF point = compute(t);
       QPoint pixel;
       pixel.setX(point.x() * mScale + center.x());
       pixel.setY(point.y() * mScale + center.y());
       //painter.drawPoint(pixel);
       painter.drawLine(pixel, prevPixel);
       prevPixel = pixel;
   }
}

