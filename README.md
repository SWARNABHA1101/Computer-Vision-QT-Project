# Computer Vision+qt based project on Image Analysis

Qt is a widget toolkit for creating graphical user interfaces as well as cross-platform applications that run on various software and hardware platforms such as Linux, Windows, macOS, Android or embedded systems with little or no change in the underlying codebase while still being a native application with native capabilities and speed.It is the faster, smarter way to create innovative devices, modern UIs & applications for multiple screens. </br>

1)**T1**- T1 has images where a part is being imaged. We are supposed to find the width and height of the part.This is done using OpenCV and qtCreator.  </br>
</br>

2)**T2** has folder containing images "T2-IMAGES" which cotains two folder(One for OK and One for Not OK), where a round part surface is imaged from a camera.The algorithm is designed such that it can differentiate between **OK** and **NOK**. This program can spot-find the differences between two images. The user loads to the program 2 images that are mostly the same but also have some small differences. By running the program user gets both images side by side with their differences highlighted.</br>
</br>
## Using cv2.absdiff. Script</br>
<li>First we are loading the two images.</li>
<li>Then we are converting both images to grayscale format.</li>
<li>Now it's time to find the absolute difference between the two images (arrays).</li>
<li>Apply threshold. Apply both THRESH_BINARY and THRESH_OTSU.</li>
<li>We are going to use 2 iterations of dilation in order to increase the white region in threshold.</li>
<li>Finally we are calculating the contours and draw rectangles in both images which are corresponding to the differences between the 2  images.</li>

</br>

3)**T3**-There are 5 images of a 2D shape in different orientations.The algorithm finds the  angle between 2 extended arms of this shape and two tangential arms of this shape. This is a generic algorithm which can find relative angle between a template 2d shape and test 2d shape.








