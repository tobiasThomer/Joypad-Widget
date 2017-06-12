#pragma once

#include <QWidget>

class QPropertyAnimation;
class QParallelAnimationGroup;

class JoyPad : public QWidget
{
    Q_OBJECT
    Q_PROPERTY(float x READ x WRITE setX NOTIFY xChanged)
    Q_PROPERTY(float y READ y WRITE setY NOTIFY yChanged)
public:
    explicit JoyPad(QWidget *parent = Q_NULLPTR);

    float x() const;
    float y() const;

signals:
    void xChanged(float value);
    void yChanged(float value);

public slots:
    void setX(float value);
    void setY(float value);

    void removeXAnimation();
    void addXAnimation();

    void removeYAnimation();
    void addYAnimation();

private:
    void resizeEvent(QResizeEvent *event) override;
    virtual void paintEvent(QPaintEvent *event) override;
    void mousePressEvent(QMouseEvent *event) override;
    void mouseReleaseEvent(QMouseEvent *event) override;
    void mouseMoveEvent(QMouseEvent *event) override;

    QPropertyAnimation *m_xAnimation;
    QPropertyAnimation *m_yAnimation;
    QParallelAnimationGroup *m_returnAnimation;

    QRectF m_bounds;
    QRectF m_knopBounds;
    QPoint m_lastPos;
    bool knopPressed;

    float m_x;
    float m_y;
};
