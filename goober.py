import ctypes

lib = ctypes.CDLL("./tracer.so")

depth, rows, cols = 200, 200, 3
total_elements = depth * rows * cols

lib.render.restype = ctypes.POINTER(ctypes.c_float * total_elements)

ptr = lib.render()

data_array = ptr.contents

d, r, c = 1, 1, 1
flat_index = (d * rows * cols) + (r * cols) + c
value = data_array[flat_index]

print(f"Value at 3D[{d}][{r}][{c}]: {float(value)}")
