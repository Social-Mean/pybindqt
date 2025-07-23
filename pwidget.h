#pragma once
#include <QWidget>

class PWidget : public QWidget {
    Q_OBJECT
public:
    using QWidget::QWidget;  // 继承所有构造函数
};