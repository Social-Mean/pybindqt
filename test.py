import os
import sys
sys.path.append("./build/")
from QtWidgets import QApplication, QMainWindow

qt_dir = os.environ["QTDIR"]
os.environ["QT_QPA_PLATFORM_PLUGIN_PATH"] = f"{qt_dir}/plugins/platforms"


app = QApplication(["app"])
window = QMainWindow()
window.show()

app.exec_()
