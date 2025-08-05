import sys
import os


def main():
    if len(sys.argv) != 2:
        print("用法: python make_dir.py <类名>")
        sys.exit(1)

    class_name = sys.argv[1]
    folder_name = f"bind_{class_name.lower()}"
    if os.path.exists(folder_name):
        print(f"文件夹 '{folder_name}' 已经存在，未进行新建操作。")
        sys.exit(0)

    os.makedirs(folder_name)
    filenames = [
        f"{folder_name}.cpp",
        f"{folder_name}_properties.cpp",
        f"{folder_name}_methods.cpp",
        f"{folder_name}_slots.cpp",
        f"{folder_name}_signals.cpp",
        "CMakeLists.txt",
    ]

    for filename in filenames:
        file_path = os.path.join(folder_name, filename)
        with open(file_path, "w", encoding="utf-8") as f:
            pass  # 创建空文件

    print(f"已成功创建文件夹 '{folder_name}' 及所需文件。")


if __name__ == "__main__":
    main()
