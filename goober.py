import sys
import struct

array = []
with open(sys.argv[1], 'r') as f:
    for line in f:
        rgb = []
        for x in line.split(' '):
            if x == '0' or x =='0\n': rgb.append(0.0)
            else: 
                try: rgb.append(struct.unpack('>f', bytes.fromhex(x))[0])
                except Exception:
                    print(repr(x))
        array.append(rgb)
        # array.append([struct.unpack('>f', bytes.fromhex(x))[0] for x in line.split(' ')])

width = 200
height = 200

img = []
for i in range(height):
    row = []
    for j in range(width):
        row.append(array[(i * width) + j])
    img.append(row)
        

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
    for i in range(height):
        for j in range(width):
            c = img[i][j]
            c = [int(aga * 256) for aga in c]
            canvas.create_rectangle(i, j, i+1, j+1, outline=rgb_to_hex(c[0], c[1], c[2]))

draw_pixels()
root.mainloop()  # make it not close
