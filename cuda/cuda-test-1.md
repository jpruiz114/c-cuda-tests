# Readme

```bash
sudo apt install nvidia-cuda-toolkit

which nvcc

nvcc --version

nvcc cuda-test-1.c -o cuda-test-1.out
./cuda-test-1.out

# Identifying which CUDA driver version is installed and active in the kernel
cat /proc/driver/nvidia/version

# Identifying which GPU card is installed and what version
nvidia-smi
```
