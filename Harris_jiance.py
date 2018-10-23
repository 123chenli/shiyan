#eccoding: utf-8
import cv2
import numpy as np

filename = 'image_collection/yuchuli/left.jpg'

img = cv2.imread(filename)

gray_img = cv2.cvtColor(img, cv2.COLOR_BGR2GRAY)

gray_img = np.float32(gray_img)

# 对图像执行harris
Harris_detector = cv2.cornerHarris(gray_img, 2, 3, 0.04)

# 腐蚀harris结果
dst = cv2.dilate(Harris_detector, None)

# 设置阈值
thres = 0.01 * dst.max()

img[dst > thres] = [255, 0, 0]

cv2.imshow('show', img)

cv2.waitKey()
