import os

os.environ["QT_QPA_PLATFORM_PLUGIN_PATH"] = (
    "D:/code/gallop-bin/3rd/qt5.15.2/plugins/platforms"
)
import sys

sys.path.append("D:/code/pybindqt/build/Release")

from QtWidget import QApplication, QMainWindow


app = QApplication(["app"])
window = QMainWindow()
window.show()
app.exec_()
