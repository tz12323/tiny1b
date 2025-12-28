#!/bin/bash
set -euo pipefail  # 严格模式：报错立即退出，禁止未定义变量，管道失败则整体失败
clear
# ===================== 配置项（可根据你的项目调整）=====================
# 需要清理的构建产物（根据你的文件结构）
CLEAN_FILES=(
    "build/"                  # 编译缓存目录
    "uvc_camera.c"            # Cython 生成的 C 文件
    "uvc_camera.cpython-*.so" # 编译后的扩展模块（匹配任意 Python 版本）
    "__pycache__/"          # Python 缓存目录
    "*.html"                  # Cython 生成的 HTML 文件
)

# 构建命令（和你之前手动运行的一致）
BUILD_CMD="python setup.py build_ext --inplace"

# ======================================================================

# 函数：打印彩色提示
info() {
    echo -e "\033[34m[INFO] $1\033[0m"  # 蓝色
}

success() {
    echo -e "\033[32m[SUCCESS] $1\033[0m" # 绿色
}

error() {
    echo -e "\033[31m[ERROR] $1\033[0m"   # 红色
    exit 1
}

# 1. 检查是否在 setup.py 所在目录
if [ ! -f "setup.py" ]; then
    error "未找到 setup.py！请在 setup.py 所在目录运行此脚本"
fi

# 2. 清理构建产物
info "开始清理旧构建产物..."
# 启用 nullglob: 未匹配的 glob 模式会展开为零个项（避免把字面模式当作文件名删除）
shopt -s nullglob
for pattern in "${CLEAN_FILES[@]}"; do
    # 将模式展开为具体文件/目录列表
    matches=( $pattern )
    if [ ${#matches[@]} -eq 0 ]; then
        info "无匹配: $pattern"
        continue
    fi
    for file in "${matches[@]}"; do
        if [ -e "$file" ]; then
            if [ -d "$file" ]; then
                info "删除目录: $file"
                rm -rf -- "$file"
            else
                info "删除文件: $file"
                rm -f -- "$file"
            fi
        fi
    done
done
shopt -u nullglob
success "清理完成！"

# 3. 检查 Python 虚拟环境（可选，根据你的习惯）
if [ -z "${VIRTUAL_ENV:-}" ]; then
    echo -e "\033[33m[WARNING] 未激活虚拟环境，可能使用系统 Python！\033[0m"
    read -p "是否继续？(y/n，默认 y): " -n 1 -r
    echo
    if [[ ! $REPLY =~ ^[Yy]$ ]]; then
        error "用户取消操作"
    fi
fi

# 4. 重新构建
info "开始构建 Cython 扩展模块..."
echo "构建命令：$BUILD_CMD"
$BUILD_CMD  # 执行构建命令

# 5. 检查构建结果
SO_FILE=$(ls -1 uvc_camera.cpython-*.so 2>/dev/null | head -n 1)
if [ -f "$SO_FILE" ]; then
    success "构建成功！生成的扩展模块：$SO_FILE"
    info "运行 ldd 检查依赖："
    ldd "$SO_FILE" #| grep -E "iruvc|irparse|usb"  # 快速验证关键依赖是否找到
else
    error "构建失败！未生成 .so 扩展模块"
fi
