#pragma once
#include "Signal.h"
#include <QPushButton>

class CustomPushButton : public QPushButton {
public:
    CustomPushButton(QWidget *parent = nullptr);
    Clicked clicked;
};