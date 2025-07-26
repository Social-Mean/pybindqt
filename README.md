# PyBindQt (PBQ)

PyBindQt is another C++/Qt bindings for Python, similar to PyQt and PySide.

## ❓ Why Another Python Qt Bindings?

PyQt and PySide are definitely excellent Python Qt bindings. 
Many programmers have used these bindings to create excellent applications.

However, the process of exporting custom C++ Qt widgets to PyQt or PySide is very difficult. 
The code generation backends, SIP for PyQt and Shiboken for PySide, are DSLs. 
They are rather complicated to use and lack relevant documentation (at least, after searching through a lot of related materials, I still haven't figured out how to use them).

On the other hand, pybind11 uses C++11 features and has detailed documentation, and is used extensively by many projects. 
This provides a new, more developer-friendly way to export C++ Qt widgets to Python. 
It has greatly reduced the difficulty of exporting custom widgets to Python. So this project was born.

## ❤️ Need Help

This project is still in its very early stages. 
As you can see, there are only a few files available at this time. 
I have successfully bound a few widgets and they are running smoothly. 
Developers are welcome to contribute code and ideas.
