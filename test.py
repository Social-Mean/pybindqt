import os

os.environ["QT_QPA_PLATFORM_PLUGIN_PATH"] = (
    "D:/code/gallop-bin/3rd/qt5.15.2/plugins/platforms"
)
import sys

sys.path.append("D:/code/pybindqt/build/Release")

from QtWidgets import QApplication, QMainWindow, QPushButton


app = QApplication(["app"])
window = QMainWindow()
window.show()

button = QPushButton()
# button.setText("Click me")
button.setParent(window)
button.show()
button.connect(lambda: print("Button clicked"))

app.exec_()
