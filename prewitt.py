#encoding: utf-8
from PIL import Image
import numpy as np
import matplotlib.pyplot as pyplot
import pylab
import cv2
im1 =Image.open('image_collection/yuchuli/left.jpg')#记得要用灰度图，如果是彩色图需要转换成灰度图
im = im1.convert('L')
w,h = im1.size
res = np.zeros((w, h))#取一个和原图一样大小的图片，并在里面填充0
roberts_x =[[1, 0],[0, -1]]#Roberts模板
roberts_y =[[0, 1],[-1, 0]]
for x in range(w-1):
    for y in range(h-1):
        sub =[[im.getpixel((x, y)), im.getpixel((x, y+1))],[im.getpixel((x+1, y)), im.getpixel((x+1, y+1))]]#x,y代表像素的位置，而不是像素值，要从图片上得到像素值
        sub = np.array(sub)#在python标准中list是不能做乘法，所以np.array()把list转就可以相乘
        roberts_x = np.array(roberts_x)
        roberts_y = np.array(roberts_y)
        var_x =sum(sum(sub * roberts_x))
        var_y = sum(sum(sub * roberts_y))

        var = abs(var_x) + abs(var_y)



pyplot.imshow(res, cmap=pyplot.cm.gray)#输出图片可能颜色有问题，用cmap=pyplot.cm.gray进行改颜色还有方向问题，也可以通过调整
pylab.show()
