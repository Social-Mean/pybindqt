import os
import sys
# from pybindqt
# sys.path.append("./build/")
from pybindqt.QtWidgets import QApplication, QMainWindow, QPushButton
from pybindqt.QtCore import QString

qt_dir = os.environ["QTDIR"]
os.environ["QT_QPA_PLATFORM_PLUGIN_PATH"] = f"{qt_dir}/plugins/platforms"


app = QApplication(["app"])
window = QMainWindow()
window.resize(600, 400)
window.show()

button = QPushButton(window)
button.setText("Hello")
button.clicked.connect(lambda checked: print("clicked"))
button.pressed.connect(lambda: print("pressed"))
button.released.connect(lambda: print("released"))
button.toggled.connect(lambda checked: print("toggled", checked))
button.show()
buttons = []
for i in range(5):
    btn = QPushButton(window)
    btn.setText(f"Button {i + 1}")
    btn.move(10, 40 * i + 50)
    btn.show()
    buttons.append(btn)

print("text:", button.text())
app.exec_()
