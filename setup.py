from setuptools import setup, Extension, find_packages
from Cython.Build import cythonize
import numpy as np

ext = Extension(
    name="tiny1b.uvc_camera",   # ★ 包内模块名（决定 import 路径）
    sources=["src/tiny1b/uvc_camera.pyx"],
    include_dirs=[
        "src/tiny1b/Inc",
        "src/tiny1b/include",
        np.get_include(),
    ],
    library_dirs=["src/tiny1b/lib"],
    libraries=["irparse", "irprocess", "irtemp", "iruvc", "usb-1.0"],
    extra_link_args=["-Wl,-rpath,$ORIGIN/lib"],
)

setup(
    name="tiny1b",              # PyPI 包名
    version="1.0.0",
    description="Tiny1B UVC camera bindings",
    packages=find_packages(where="src"),
    package_dir={"": "src"},
    ext_modules=cythonize(
        [ext],
        language_level=3,
        annotate=True,
    ),
    include_package_data=True,
    zip_safe=False,
    python_requires=">=3.8",
    install_requires=[
        "numpy",
    ],
)

# from setuptools import setup, Extension
# from Cython.Build import cythonize  # 必须加，因为你用了Cython（.pyx文件）
# import numpy as np
# uvc_camera_ext = Extension(
#     name="tiny1b",
#     sources=["uvc_camera.pyx"],
#     include_dirs=["./Inc", "./include",f"{np.get_include()}"],
#     library_dirs=["lib"],
#     libraries=["irparse", "irprocess", "irtemp", "iruvc", "usb-1.0"],
#     # 关键：添加rpath，让.so记住“当前目录下的lib”
#     extra_link_args=["-Wl,-rpath,$ORIGIN/lib"],  # $ORIGIN表示.so文件所在的目录
# )

# # 执行编译
# setup(
#     name="tiny1b",
#     version="1.0",
#     ext_modules=cythonize(uvc_camera_ext,annotate=True),  # 必须用cythonize处理Cython文件
#     packages=[],
#     py_modules=[],
# )

