# P2-2023-Project: Image Effect Application


## GitHub Link
https://github.com/Hemant-Gupta1/Image-Effect-Application


## Features
The project allows users to adjust image features such as brightness, contrast, invert, rotation, sepia, hue saturation, Gaussian blur, sharpen, flip, and grayscale in real time.The photos are tracked in the Logs Section.


## Table of Contents
The project is divided into two sections broadly: ImageEffectFrontend and ImageEffectBackend. The major front-end code is written in /src/app, whereas the main back-end code is written in /Libraries.


## Technologies used
Languages used in this project include TyeScript, C++, Java, HTML, SCSS, and JavaScript.


## Basic Implementation
Filters such as Brightness, Contrast, Flip, Invert (Colour Inversion), Sepia, Hue Saturation, and Grayscale impose specific conditions on the image's pixels.Users can modify the image's focus and sharpness with the Gaussian Blur and Sharpen filters.Using the Rotation Filter, we can reorient the photos.
Each filter has its own interface file, which is invoked in PhotoService.java.In LoggingService.java, the Logs section is implemented using File IO.

## Instructions to run
1. npx ng serve in /ImageEffectFrontend in Terminal
2. make clean in /ImageEffectBackend/Libraries in Terminal
3. make in /ImageEffectBackend/Libraries in Terminal
4. Run ImageEffectApplication in Intellij


## Team Members 
Ritish Shrirao (IMT2022003)
Siddeshwar Kagatikar (IMT2022026)
Hemant Gupta (IMT2022030)
Bhavya Kapadia (IMT2022095)
Shreyas Biradar (IMT2022529)
Sanjeev Harge (IMT2022530)

#Contributions
Ritish Shrirao - Filters (Gaussian Blur,Sharpen) 
Siddeshwar Kagatikar - Filter (Rotation, Sepia) 
Hemant Gupta - Filter (Flip, Hue Saturation) 
Bhavya Kapadia - Filters (Brightness, Contrast, Invert) 
Shreyas Biradar - Logging Service 
Sanjeev Harge (Comments, Grayscale)
