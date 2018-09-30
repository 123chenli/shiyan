# __author__ = 'Microcosm'
import cv2
import numpy as np
from matplotlib import pyplot as plt
img_L = cv2.imread("image_collection/yuchuli/left.jpg",0)
img_R = cv2.imread("image_collection/yuchuli/right.jpg",0)
# stereo = cv2.StereoBM(cv2.STEREO_BM_BASIC_PRESET,16,15)
stereo = cv
stereo = cv2.StereoBM_create(numDisparities=16, blockSize=15) # OpenCV 3.0的函数
disparity = stereo.compute(img_L, img_R)
plt.subplot(121),plt.imshow(img_L,'gray'),plt.title('img_left'),plt.xticks([]),plt.yticks([])
plt.subplot(122),plt.imshow(disparity,'gray'),plt.title('disparity'),plt.xticks([]),plt.yticks([])
plt.show()
