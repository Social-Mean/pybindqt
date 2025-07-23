#pragma once
#include "Signal.h"
#include <QPushButton>

class PB_QPushButton : public QPushButton {
public:
    PB_QPushButton(QWidget *parent = nullptr);
    Clicked clicked;
};