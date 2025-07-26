# PyBindQt (PBQ)

PyBindQt is another C++/Qt binding for Python, similar to PyQt and PySide.

## ❓ Why Another Python Qt Binding?

PyQt and PySide are definitely excellent Python Qt bindings. 
Many programmers have used them to create excellent applications.

However, the process of exporting custom C++ Qt widgets to PyQt or PySide is very difficult. 
The code generation backends, SIP for PyQt and Shiboken for PySide, are DSLs. 
They are rather complicated to use and lack relevant documentation (after searching through many related materials, I still haven't figured out how to use them).

On the other hand, [pybind11](https://github.com/pybind/pybind11) uses C++11 features and has detailed documentation, and is widely used by many projects. 
This provides a new, more developer-friendly way to export C++ Qt widgets to Python. 
It greatly reduces the difficulty of exporting custom widgets to Python. So this project was born.

## ❤️ Need Help

This project is still in its very early stages. 
As you can see, there are only a few files available now. 
I have successfully bound a few widgets and they are running smoothly. 
Developers are welcome to contribute code and ideas.
