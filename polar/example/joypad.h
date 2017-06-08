

#pragma once

#include <QWidget>

class QPropertyAnimation;

class JoyPad : public QWidget
{
    Q_OBJECT
    Q_PROPERTY(float distance READ distance WRITE setDistance NOTIFY distanceChanged)
    Q_PROPERTY(float angle READ angle WRITE setAngle NOTIFY angleChanged)
public:
    explicit JoyPad(QWidget *parent = Q_NULLPTR);

    float distance() const;
    float angle() const;

signals:
    void distanceChanged(float value);
    void angleChanged(float value);

public slots:
    void setDistance(float value);
    void setAngle(float value);

private slots:

private:
    void resizeEvent(QResizeEvent *event) override;
    virtual void paintEvent(QPaintEvent *event) override;
    void mousePressEvent(QMouseEvent *event) override;
    void mouseReleaseEvent(QMouseEvent *event) override;
    void mouseMoveEvent(QMouseEvent *event) override;

    QPropertyAnimation *m_returnAnimation;

    QRectF m_bounds;
    QRectF m_knopBounds;
    QPoint m_lastPos;
    bool knopPressed;

    float m_distance;
    float m_angle;
};
