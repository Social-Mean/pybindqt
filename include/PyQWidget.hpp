#pragma once

#include <PyQObject.hpp>

template <class QBase = QWidget>
class PyQWidget : public PyQObject<QBase> {
public:
    void actionEvent(QActionEvent *event) override {
        PYBIND11_OVERRIDE(void, QBase, actionEvent, event);
    }
    void changeEvent(QEvent *event) override {
        PYBIND11_OVERRIDE(void, QBase, changeEvent, event);
    }

    void closeEvent(QCloseEvent *event) override {
        PYBIND11_OVERRIDE(void, QBase, closeEvent, event);
    }

    void contextMenuEvent(QContextMenuEvent *event) override {
        PYBIND11_OVERRIDE(void, QBase, contextMenuEvent, event);
    }

    void dragEnterEvent(QDragEnterEvent *event) override {
        PYBIND11_OVERRIDE(void, QBase, dragEnterEvent, event);
    }

    void dragLeaveEvent(QDragLeaveEvent *event) override {
        PYBIND11_OVERRIDE(void, QBase, dragLeaveEvent, event);
    }

    void dragMoveEvent(QDragMoveEvent *event) override {
        PYBIND11_OVERRIDE(void, QBase, dragMoveEvent, event);
    }

    void dropEvent(QDropEvent *event) override {
        PYBIND11_OVERRIDE(void, QBase, dropEvent, event);
    }

    void enterEvent(QEvent *event) override {
        PYBIND11_OVERRIDE(void, QBase, enterEvent, event);
    }

    void focusInEvent(QFocusEvent *event) override {
        PYBIND11_OVERRIDE(void, QBase, focusInEvent, event);
    }

    bool focusNextPrevChild(bool next) override {
        PYBIND11_OVERRIDE(bool, QBase, focusNextPrevChild, next);
    }

    void focusOutEvent(QFocusEvent *event) override {
        PYBIND11_OVERRIDE(void, QBase, focusOutEvent, event);
    }

    void hideEvent(QHideEvent *event) override {
        PYBIND11_OVERRIDE(void, QBase, hideEvent, event);
    }

    void inputMethodEvent(QInputMethodEvent *event) override {
        PYBIND11_OVERRIDE(void, QBase, inputMethodEvent, event);
    }

    void keyPressEvent(QKeyEvent *event) override {
        PYBIND11_OVERRIDE(void, QBase, keyPressEvent, event);
    }

    void keyReleaseEvent(QKeyEvent *event) override {
        PYBIND11_OVERRIDE(void, QBase, keyReleaseEvent, event);
    }

    void leaveEvent(QEvent *event) override {
        PYBIND11_OVERRIDE(void, QBase, leaveEvent, event);
    }

    void mouseDoubleClickEvent(QMouseEvent *event) override {
        PYBIND11_OVERRIDE(void, QBase, mouseDoubleClickEvent, event);
    }

    void mouseMoveEvent(QMouseEvent *event) override {
        PYBIND11_OVERRIDE(void, QBase, mouseMoveEvent, event);
    }

    void mousePressEvent(QMouseEvent *event) override {
        PYBIND11_OVERRIDE(void, QBase, mousePressEvent, event);
    }

    void mouseReleaseEvent(QMouseEvent *event) override {
        PYBIND11_OVERRIDE(void, QBase, mouseReleaseEvent, event);
    }

    void moveEvent(QMoveEvent *event) override {
        PYBIND11_OVERRIDE(void, QBase, moveEvent, event);
    }

    bool nativeEvent(const QByteArray &eventType, void *message, long *result) override {
        PYBIND11_OVERRIDE(bool, QBase, nativeEvent, eventType, message, result);
    }

    void paintEvent(QPaintEvent *event) override {
        PYBIND11_OVERRIDE(void, QBase, paintEvent, event);
    }

    void resizeEvent(QResizeEvent *event) override {
        PYBIND11_OVERRIDE(void, QBase, resizeEvent, event);
    }

    void showEvent(QShowEvent *event) override {
        PYBIND11_OVERRIDE(void, QBase, showEvent, event);
    }

    void tabletEvent(QTabletEvent *event) override {
        PYBIND11_OVERRIDE(void, QBase, tabletEvent, event);
    }

    void wheelEvent(QWheelEvent *event) override {
        PYBIND11_OVERRIDE(void, QBase, wheelEvent, event);
    }
};