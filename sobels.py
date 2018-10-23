#!/usr/bin/env python
# encoding: utf-8
import cv2
import numpy as np

img = cv2.imread("image_collection/yuchuli/left.jpg", 0)
x = cv2.Sobel(img, cv2.CV_16S, 1, 0)  #
y = cv2.Sobel(img, cv2.CV_16S, 0, 1)

absX = cv2.convertScaleAbs(x)  # 转回uint8
absY = cv2.convertScaleAbs(y)

dst = cv2.addWeighted(absX, 0.5, absY, 0.5, 0)

cv2.imshow("X", absX)
cv2.imshow("Y", absY)

cv2.imshow("Result", dst)

cv2.waitKey(0)
cv2.destroyAllWindows()