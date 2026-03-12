
from std.benchmark import run
from std.collections import List

fn main() raises:
    comptime n = 512
    var A = List[Float64]()
    var B = List[Float64]()
    var C = List[Float64]()
    
    for _ in range(n * n):
        A.append(1.0); B.append(1.0); C.append(0.0)

    @parameter
    fn test_fn():
        # Using the standard triple-loop (Naive)
        for i in range(n):
            for k in range(n):
                for j in range(n):
                    C[i * n + j] += A[i * n + k] * B[k * n + j]

    var report = run[test_fn]()
    print("Mojo Time (Naive):", report.mean(), "s")