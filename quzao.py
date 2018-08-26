# # # -*- coding: utf-8 -*-
# # """
# # Created on Sat Oct 14 22:16:47 2017
# #
# # @author: Don
# # """
# #
# # from tkinter import *
# # from skimage import io
# # import numpy as np
# #
# #
# # im=io.imread('lena_sp.jpg', as_grey=True)
# # im_copy_med = io.imread('lena_sp.jpg', as_grey=True)
# # im_copy_mea = io.imread('lena_sp.jpg', as_grey=True)
# # #io.imshow(im)
# # for i in range(0,im.shape[0]):
# #     for j in range(0,im.shape[1]):
# #         im_copy_med[i][j]=im[i][j]
# #         im_copy_mea[i][j]=im[i][j]
# # #ui
# # root = Tk()
# # root.title("lena")
# # root.geometry('300x200')
# #
# # medL = Label(root, text="中值滤波：")
# # medL.pack()
# # med_text = StringVar()
# # med = Entry(root, textvariable = med_text)
# # med_text.set("")
# # med.pack()
# #
# # meaL = Label(root, text="均值滤波：")
# # meaL.pack()
# # mea_text = StringVar()
# # mea = Entry(root, textvariable = mea_text)
# # mea_text.set("")
# # mea.pack()
# #
# # def m_filter(x, y, step):
# #     sum_s=[]
# #     for k in range(-int(step/2),int(step/2)+1):
# #         for m in range(-int(step/2),int(step/2)+1):
# #             sum_s.append(im[x+k][y+m])
# #     sum_s.sort()
# #     return sum_s[(int(step*step/2)+1)]
# #
# # def mean_filter(x, y, step):
# #     sum_s = 0
# #     for k in range(-int(step/2),int(step/2)+1):
# #         for m in range(-int(step/2),int(step/2)+1):
# #             sum_s += im[x+k][y+m] / (step*step)
# #     return sum_s
# #
# # def on_click():
# #     if(med_text):
# #         medStep = int(med_text.get())
# #         for i in range(int(medStep/2),im.shape[0]-int(medStep/2)):
# #             for j in range(int(medStep/2),im.shape[1]-int(medStep/2)):
# #                 im_copy_med[i][j] = m_filter(i, j, medStep)
# #     if(mea_text):
# #         meaStep = int(mea_text.get())
# #         for i in range(int(meaStep/2),im.shape[0]-int(meaStep/2)):
# #             for j in range(int(meaStep/2),im.shape[1]-int(meaStep/2)):
# #                 im_copy_mea[i][j] = mean_filter(i, j, meaStep)
# #     io.imshow(im_copy_med)
# #     io.imsave(str(medStep) + 'med.jpg', im_copy_med)
# #     io.imshow(im_copy_mea)
# #     io.imsave(str(meaStep) + 'mea.jpg', im_copy_mea)
# #
# # Button(root, text="filterGo", command = on_click).pack()
# #
# # root.mainloop()
#
#
# import cv2
# from numpy import *
#
#
# def SaltAndPepper(src, percetage):
#     NoiseImg = src
#     NoiseNum = int(percetage * src.shape[0] * src.shape[1])
#     for i in range(NoiseNum):
#         randX = random.random_integers(0, src.shape[0] - 1)
#         randY = random.random_integers(0, src.shape[1] - 1)
#         if random.random_integers(0, 1) == 0:
#             NoiseImg[randX, randY] = 0
#         else:
#             NoiseImg[randX, randY] = 255
#     return NoiseImg
#
#
# if __name__ == '__main__':
#     img = cv2.imread('image_collection/yuchuli/left.jpg', flags=0)
#     gimg = cv2.GaussianBlur(img, (7, 7), sigmaX=0)
#     NoiseImg = SaltAndPepper(gimg, 0.4)
#     # cv2.imshow('img',gimg)
#     # figure()
#     Pers = [0.4, 0.5, 0.6]
#     for i in Pers:
#         NoiseImg = SaltAndPepper(gimg, i)
#         fileName = 'GaussianSaltPepper' + str(i) + '.jpg'
#         cv2.imwrite(fileName, NoiseImg, [cv2.IMWRITE_JPEG_QUALITY, 100])
#     cv2.imshow('img2', NoiseImg)
#     cv2.waitKey()


import numpy as np
import cv2
import matplotlib.pyplot as plt
########     四个不同的滤波器    #########
img = cv2.imread('image_collection/yuchuli/left_gaosi.png')

# 均值滤波
img_mean = cv2.blur(img, (5,5))

# 高斯滤波
img_Guassian = cv2.GaussianBlur(img,(5,5),0)

# 中值滤波
img_median = cv2.medianBlur(img, 5)

# 双边滤波
img_bilater = cv2.bilateralFilter(img,9,75,75)

# 展示不同的图片
titles = ['srcImg','mean', 'Gaussian', 'median', ]
imgs = [img, img_mean, img_Guassian, img_median, img_bilater]

for i in range(4):
    plt.subplot(2,3,i+1)#注意，这和matlab中类似，没有0，数组下标从1开始
    plt.imshow(imgs[i])
    plt.title(titles[i])
plt.show()