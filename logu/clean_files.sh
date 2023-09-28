#!/bin/bash

# 清除除了以.cpp、.in和.out结尾的其他文件
find . ! -name "*.cpp" ! -name "*.in" ! -name "*.out" ! -name "$(basename "$0")" -type f -delete

echo "已清除除了以.cpp、.in、.out和脚本文件之外的所有文件"
