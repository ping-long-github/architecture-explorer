[![Open In Colab](https://colab.research.google.com/assets/colab-badge.svg)](https://colab.research.google.com/github/ping-long-github/architecture-explorer/blob/main/explorer.ipynb)

# Architecture Explorer 🚀
*The Godbolt for Compute Performance.*

Architecture Explorer is an interactive, browser-based benchmarking tool. Just as Compiler Explorer (Godbolt) lets you instantly see how C++ maps to assembly, **Architecture Explorer** lets you instantly write compute kernels and see how different compilers and schedules map to hardware performance.

## ⚡ Quick Start
The easiest way to use Architecture Explorer is entirely in the cloud. You don't need to install anything locally.
1. Click the **Open in Colab** badge above.
2. If you want to benchmark on a GPU or TPU, go to `Runtime > Change runtime type` in the Colab menu and select your hardware.
3. Run the cells to write your compute kernels and instantly see the execution time and GFLOPs.

## 🛠️ How it Works
Under the hood, Architecture Explorer bypasses heavy Jupyter wrappers. It gives you raw, unhindered access to native compilers and AI frameworks directly in the Google Cloud Ubuntu environment. 

Test the impact of:
* **Compiler optimizations** (`-O0` vs `-O3`, `-march=native`)
* **Hardware architectures** (x86, ARM64, RISC-V, NVIDIA GPUs, Google TPUs)
* **Programming languages** (C/C++, Rust, Python, Go, Mojo)
* **Compute frameworks** (Apache TVM, Halide, CUDA, Triton, JAX/XLA)

## 📄 License
This project is licensed under the Apache License 2.0 - see the LICENSE file for details.
