
import cv2
from matplotlib import pyplot as plt
im = cv2.imread('image_collection/yuchuli/right.jpg')
im_gray = cv2.cvtColor(im, cv2.COLOR_BGR2GRAY)
im_at_mean = cv2.adaptiveThreshold(im_gray, 255, cv2.ADAPTIVE_THRESH_MEAN_C, cv2.THRESH_BINARY, 5, 7)
im_at_mean2 = cv2.adaptiveThreshold(im_gray, 255, cv2.ADAPTIVE_THRESH_MEAN_C, cv2.THRESH_BINARY, 5, 10)
retval,im_at_fixed = cv2.threshold(im_gray, 50, 255, cv2.THRESH_BINARY)
plt.subplot(2, 2, 1),plt.imshow(im_gray,'gray')
plt.subplot(2, 2, 2),plt.imshow(im_at_mean,'gray')
plt.subplot(2, 2, 3),plt.imshow(im_at_mean2,'gray')
plt.subplot(2, 2, 4),plt.imshow(im_at_fixed,'gray')
plt.show()