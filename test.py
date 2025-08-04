import os
import sys
sys.path.append("./build/")
from QtWidgets import QApplication, QMainWindow, QPushButton

qt_dir = os.environ["QTDIR"]
os.environ["QT_QPA_PLATFORM_PLUGIN_PATH"] = f"{qt_dir}/plugins/platforms"


app = QApplication(["app"])
window = QMainWindow()
window.show()

button = QPushButton(window)
button.setText("Hello")
button.clicked.connect(lambda checked: print("clicked"))
button.pressed.connect(lambda: print("pressed"))
button.released.connect(lambda: print("released"))
button.toggled.connect(lambda checked: print("toggled", checked))
button.show()

print("text:", button.text())
app.exec_()
