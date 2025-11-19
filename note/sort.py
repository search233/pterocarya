import re

def sort_md_table(file_path):
    with open(file_path, 'r', encoding='utf-8') as f:
        lines = f.readlines()

    # 保留表头
    header = lines[:2]
    body = lines[2:]

    # 解析每一行，提取单词和释义
    rows = []
    for line in body:
        match = re.match(r'^\|\s*(.*?)\s*\|\s*(.*?)\s*\|$', line.strip())
        if match:
            word, meaning = match.groups()
            rows.append((word, meaning))

    # 按单词排序（字典序）
    rows.sort(key=lambda x: x[0].lower())

    # 重新构建表格
    new_lines = header[:]
    for word, meaning in rows:
        new_lines.append(f"| {word:<30} | {meaning:<30} |\n")

    # 覆写原文件
    with open(file_path, 'w', encoding='utf-8') as f:
        f.writelines(new_lines)

# 使用示例
if __name__ == "__main__":
    file_path = "单词拾遗.md"  # 替换为你的文件名
    sort_md_table(file_path)
