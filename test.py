import os

os.environ["QT_QPA_PLATFORM_PLUGIN_PATH"] = (
    "C:/code/gallop-bin/3rd/qt5.15.2/plugins/platforms"
)
import sys

sys.path.append("C:/code/pybindqt/build/")

from QtWidgets import QApplication, QMainWindow  # , QPushButton
# from QtCore import Signal

app = QApplication(["app"])
window = QMainWindow()
window.show()

# button = QPushButton()
# # button.setText("Click me")
# button.setParent(window)
# button.show()
# button.clicked.connect(lambda checked: print("Button clicked"))

app.exec_()
