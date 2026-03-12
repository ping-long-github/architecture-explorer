import time

def pure_python_dgemm(n):
    # Initialize matrices using standard Python lists (No NumPy!)
    A = [[1.0 for _ in range(n)] for _ in range(n)]
    B = [[2.0 for _ in range(n)] for _ in range(n)]
    C = [[0.0 for _ in range(n)] for _ in range(n)]
    
    start = time.time()
    # The most "expensive" way to do math in Python
    for i in range(n):
        for k in range(n):
            aik = A[i][k]
            for j in range(n):
                C[i][j] += aik * B[k][j]
    end = time.time()
    return end - start

size = 128 #@param [64, 128, 256] {type:"raw"}
print(f"Running {size}x{size} matrix in 100% Pure Python...")

# Using int(size) to prevent the TypeError you saw earlier
duration = pure_python_dgemm(int(size))

print(f"Total Time: {duration:.4f} seconds")