import os
import sys
sys.path.append("./build/")
from QtWidgets import QApplication, QMainWindow  # , QPushButton

qt_dir = os.environ["QTDIR"]
os.environ["QT_QPA_PLATFORM_PLUGIN_PATH"] = f"{qt_dir}/plugins/platforms"


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
