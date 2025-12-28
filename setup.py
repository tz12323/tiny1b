from setuptools import setup, Extension
from Cython.Build import cythonize  # 必须加，因为你用了Cython（.pyx文件）
import numpy as np
uvc_camera_ext = Extension(
    name="uvc_camera",
    sources=["uvc_camera.pyx"],
    include_dirs=["./Inc", "./include",f"{np.get_include()}"],
    library_dirs=["lib"],
    libraries=["irparse", "irprocess", "irtemp", "iruvc", "usb-1.0"],
    # 关键：添加rpath，让.so记住“当前目录下的lib”
    extra_link_args=["-Wl,-rpath,$ORIGIN/lib"],  # $ORIGIN表示.so文件所在的目录
)

# 执行编译
setup(
    name="uvc_camera",
    version="1.0",
    ext_modules=cythonize(uvc_camera_ext,annotate=True),  # 必须用cythonize处理Cython文件
)
