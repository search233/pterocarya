#!/usr/bin/env python3
import os
import shutil
import subprocess
import sys

# ================= 配置路径 =================
BASE_DIR = os.path.abspath(os.path.dirname(__file__))
SRC_DIR = os.path.normpath(os.path.join(BASE_DIR, "../src"))
DATA_DIR = os.path.normpath(os.path.join(BASE_DIR, "../data"))
COMPILED_DIR = os.path.normpath(os.path.join(BASE_DIR, "../compiled"))

DATA_CPP = os.path.join(SRC_DIR, "data.cpp")
STD_CPP = os.path.join(SRC_DIR, "std.cpp")

DATA_EXE = os.path.join(COMPILED_DIR, "data.out")
STD_EXE = os.path.join(COMPILED_DIR, "std.out")


def init_and_compile():
    """初始化编译目录并编译 C++ 文件"""
    # 创建编译目录
    os.makedirs(COMPILED_DIR, exist_ok=True)

    print("开始编译 C++ 程序...")
    # 编译 data.cpp
    try:
        subprocess.run(
            ["g++", "-O3", DATA_CPP, "-o", DATA_EXE], check=True, text=True
        )
        print(f"[-] 编译成功: {DATA_EXE}")
    except subprocess.CalledProcessError:
        print(f"[x] 错误: {DATA_CPP} 编译失败！")
        sys.exit(1)

    # 编译 std.cpp
    try:
        subprocess.run(
            ["g++", "-O3", STD_CPP, "-o", STD_EXE], check=True, text=True
        )
        print(f"[-] 编译成功: {STD_EXE}")
    except subprocess.CalledProcessError:
        print(f"[x] 错误: {STD_CPP} 编译失败！")
        sys.exit(1)


def generate_test_cases(sub_dir_name, count):
    """在指定子目录下生成多组数据"""
    target_dir = os.path.join(DATA_DIR, sub_dir_name)

    # 如果文件夹已存在则先删除，确保数据干净（可根据需求修改）
    if os.path.exists(target_dir):
        shutil.rmtree(target_dir)
    os.makedirs(target_dir, exist_ok=True)

    print(f"\n正在 {target_dir} 中生成 {count} 组数据...")

    for i in range(1, count + 1):
        in_file = os.path.join(target_dir, f"{i}.in")
        out_file = os.path.join(target_dir, f"{i}.out")

        # 1. 运行 data.out 生成输入数据 (.in)
        # 提示：如果你的 data.cpp 需要读入随机种子，可以在 input 中传入 str(i)
        with open(in_file, "w") as f_in:
            subprocess.run([DATA_EXE], stdout=f_in, check=True)

        # 2. 运行 std.out 读取 .in 并生成输出数据 (.out)
        with open(in_file, "r") as f_in, open(out_file, "w") as f_out:
            subprocess.run([STD_EXE], stdin=f_in, stdout=f_out, check=True)

        print(f" -> 已生成第 {i} 组数据: {i}.in / {i}.out")

    print("\n[√] 所有数据生成完毕！")


def cleanup():
    """程序退出时清空编译文件夹"""
    if os.path.exists(COMPILED_DIR):
        print(f"\n正在清理编译目录: {COMPILED_DIR}")
        shutil.rmtree(COMPILED_DIR)
        print("[-] 清理完毕。")


def main():
    # 检查源码是否存在
    if not os.path.exists(DATA_CPP) or not os.path.exists(STD_CPP):
        print(
            f"[x] 错误: 未在 {SRC_DIR} 中找到 data.cpp 或 std.cpp，请检查路径。"
        )
        sys.exit(1)

    try:
        # 1. 编译
        init_and_compile()

        # 2. 获取用户输入
        sub_dir_name = input("\n请输入要在 ../data 中新建的文件夹名称: ").strip()
        if not sub_dir_name:
            print("[x] 错误: 文件夹名称不能为空！")
            return

        try:
            count = int(input("请输入要生成的数据组数: "))
            if count <= 0:
                print("[x] 错误: 组数必须大于 0！")
                return
        except ValueError:
            print("[x] 错误: 请输入有效的数字！")
            return

        # 3. 生成数据
        generate_test_cases(sub_dir_name, count)

    except KeyboardInterrupt:
        print("\n[!] 用户终止了程序。")
    finally:
        # 4. 无论成功、失败还是中途退出，都会触发清空编译目录
        cleanup()


if __name__ == "__main__":
    main()