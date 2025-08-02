import os
import sys
sys.path.append("./build/")
from QtWidgets import QApplication, QMainWindow, QPushButton, QObject

qt_dir = os.environ["QTDIR"]
os.environ["QT_QPA_PLATFORM_PLUGIN_PATH"] = f"{qt_dir}/plugins/platforms"


app = QApplication(["app"])
window = QMainWindow()
window.show()

button = QPushButton()
button.setParent(window)
button.clicked.connect(lambda checked: print("clicked"))
button.show()

print("text:", button.text())
app.exec_()
