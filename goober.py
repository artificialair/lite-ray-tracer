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
        d.append(r.copy());
    array.append(d.copy());
print()
print(len(array), len(array[0]), len(array[0][0]))

# two year old level tkinter python renderer
import tkinter as tk

width = 200
height = 200

def rgb_to_hex(r, g, b):
    return '#{:02x}{:02x}{:02x}'.format(r, g, b)      

root = tk.Tk()

canvas = tk.Canvas(root, width=width, height=height, bg='#FFFFFF')
canvas.pack()

def draw_pixels():
    for i in range(len(array)):
        for j in range(len(array[i])):
            c = array[i][j]
            c = [int(aga * 256) for aga in c]
            canvas.create_rectangle(i, j, i+1, j+1, outline=rgb_to_hex(c[0], c[1], c[2]))

draw_pixels()
root.mainloop()  # make it not close
