import os
import sys

sys.path.append("./build/")
from pybindqt.QtWidgets import QApplication, QMainWindow, QPushButton, QLabel
from pybindqt.QtCore import QPoint  # , Qt

qt_dir = os.environ["QTDIR"]
os.environ["QT_QPA_PLATFORM_PLUGIN_PATH"] = f"{qt_dir}/plugins/platforms"


class MainWindow(QMainWindow):
    def __init__(self):
        super().__init__()
        self.setWindowTitle("持续输出鼠标坐标")
        self.label = QLabel("坐标: (0, 0)", self)
        self.setCentralWidget(self.label)
        self.setMouseTracking(True)  # 启用鼠标追踪（即使不按下也能获取坐标）

    def mousePressEvent(self, event):
        # if event.button() == Qt.LeftButton:
        self.update_mouse_position(event.pos())

    def mouseMoveEvent(self, event):
        # if event.buttons() & Qt.LeftButton:  # 检查左键是否按下
        self.update_mouse_position(event.pos())

    def update_mouse_position(self, pos: QPoint):
        self.label.setText(f"坐标: ({pos.x()}, {pos.y()})")
        print(f"鼠标坐标: ({pos.x()}, {pos.y()})")


if __name__ == "__main__":
    app = QApplication([])
    window = MainWindow()
    window.show()
    app.exec_()
