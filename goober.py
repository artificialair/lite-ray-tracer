import ctypes

lib = ctypes.CDLL("./tracer.so")

depth, rows, cols = 200, 200, 3
total_elements = depth * rows * cols

lib.render.restype = ctypes.POINTER(ctypes.POINTER(ctypes.POINTER(ctypes.c_float)))

ptr = lib.render()

array = []
for i in range(depth):
    d = []
    for j in range(rows):
        r = []
        for k in range(cols):
            r.append(ptr[i][j][k]);
        d.append(r);
    array.append(d);
print()
print(len(array), len(array[0]), len(array[0][0]))
