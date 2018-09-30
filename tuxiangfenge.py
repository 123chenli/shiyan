# 视差图像预处理-canny算子对图像分割，将分割后的图像与原图做叠加，做差，分割出的部分显高亮
#  coding=utf-8
import cv2
import numpy as np
left_img = cv2.imread('image_collection/yuchuli/left.jpg')
right_img = cv2.imread('image_collection/yuchuli/left.jpg')
grayimg1 = cv2.cvtColor(left_img, cv2.COLOR_BGR2GRAY)
grayimg2 = cv2.cvtColor(right_img, cv2.COLOR_BGR2GRAY)
img1 = cv2.GaussianBlur(grayimg1, (3, 3), 0)
img2 = cv2.GaussianBlur(grayimg2, (3, 3), 0)
left_canny = cv2.Canny(img1, 50, 120)
right_canny = cv2.Canny(img2, 50, 150)
cv2.imshow('left_canny', left_canny)
cv2.imshow('right_canny', right_canny)
# cv2.imshow('Canny2-img2', right_canny-img2)
# cv2.imshow('Canny2+img2', canny2+img2)

key=cv2.waitKey(0)

if key == ord("s"):
    cv2.imwrite("image_collection/yuchuli/canny_left.jpg", left_canny)
    cv2.imwrite("image_collection/yuchuli/canny_right.jpg", right_canny)
    cv2.destroyAllWindows()
