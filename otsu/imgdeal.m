img = imread('otsus_test.jpg');  
[counts x] = imhist(img);  
[m n] = size(img);  
level = otsu(counts, m*n);  
output = img;  
output(output<level) = 0;  
output(output>=level) = 255;  
imshow(output)  