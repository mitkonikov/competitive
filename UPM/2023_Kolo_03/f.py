def hex(n):
    n = int(n)
    a = n // 16
    b = n % 16
    if (a >= 10):
        a = chr(ord('a') + a - 10)
    if (b >= 10):
        b = chr(ord('a') + b - 10)
    a = str(a)
    b = str(b)
    return str(a + b)
 
def col_to_hex(r, g, b):
    return "#" + hex(r) + hex(g) + hex(b)
 
def col_to_rgb(r, g, b):
    return "rgb({}, {}, {})".format(r, g, b)
 
def col_to_list(r, g, b):
    r /= 256
    g /= 256
    b /= 256
    return "[{:.8f}, {:.8f}, {:.8f}]".format(r, g, b)
 
def from_hex(h):
    # print(h)
    a = h[0]
    b = h[1]
    A = 0
    B = 0
    if (ord(a) >= ord('a') and ord(a) <= ord('f')):
        A = ord(a) - ord('a') + 10
    else:
        A = int(a)
    if (ord(b) >= ord('a') and ord(b) <= ord('f')):
        B = ord(b) - ord('a') + 10
    else:
        B = int(b)
    A = int(A)
    B = int(B)
    return A * 16 + B
 
def hex_to_rgb(h):
    r = from_hex(h[1:3])
    g = from_hex(h[3:5])
    b = from_hex(h[5:7])
    return r, g, b
 
while True:
    try:
        line = input()
        if line.startswith("rgb"):
            V = line.split('(')[1].split(')')[0].split(',')
            R = int(V[0])
            G = int(V[1][1:])
            B = int(V[2][1:])
 
            print(col_to_hex(R, G, B), col_to_list(R, G, B))
            
        elif line.startswith("#"):
            R, G, B = hex_to_rgb(line)
            print(col_to_rgb(R, G, B), col_to_list(R, G, B))
        else:
            V = line.split('[')[1].split(']')[0].split(',')
            R = int(round(float(V[0]) * 256))
            G = int(round(float(V[1][1:]) * 256))
            B = int(round(float(V[2][1:]) * 256))
            
            print(col_to_rgb(R, G, B), col_to_hex(R, G, B))
    except:
        break
