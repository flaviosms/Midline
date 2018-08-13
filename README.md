# Introduction
  An Introduction to Computer Graphics assignment , where we learnt how to implement the Midline point algorithm also known as Bresenham's Algorithm.
  The ultimate goal is to create a graphical pipeline from scratch.
  
### Drawing Lines 
  ![Lines on all axis](https://github.com/flaviosms/Pipeline/blob/master/Axis.JPG)
 
   On this part , i draw a line for each direction to test if the function was working properly for all octants.
  
### Random Lines
  ![Lines with randomized color and endpoints starting from the center](https://github.com/flaviosms/Pipeline/blob/master/RandomLine.JPG)
  
   Here I randomized the endpoint of the lines to create an intersting pattern.
  
### Drawing Triangles
  ![Triangles drawn with the DrawTriangle function one filled up and the other only the borders](https://github.com/flaviosms/Pipeline/blob/master/Triangles.JPG)
  
   Here i used the DrawTriangle() function , which has 2 ways of being called ,
   one that recieves 3 colors and the other that receives one ,the one that gets one color is
   filled up with that color ,the one that receives 3 colors will draw 3 lines and interpolate
   the colors between them.
  
# Metodology
  
  ### How to run This code
   To run this code you'll need Glut/freeglut setup in your computer,
   the program used by me was Codeblocks on windows platform ,but 
   it can also be compiled manually.
   To use the functions you'll need to uncomment/write functions in main.cpp inside MyGlDraw function.
    
  ### Creating PutPixel()
   To create this function we needed to use the functions to know the pixels data address 
   based on x,y position on the pixel grid.
   
      Offset = x*4 + y*w*4
      
   W being the width of the screen in pixels , that can be found in definitions.h named as "IMAGE_WIDTH"
   
  ### Creating Drawline()
   The Drawline function was created as said before with the midline point algorithm as base , the implementation was adapted from:
   
     http://electrofriends.com/source-codes/software-programs/c/graphics/c-program-to-for-midpoint-line-algorithm/
     
   Some issues were found on this code mostly on drawing on all octants,one big change was the necessary division between the 4 quartets  into two groups , the main diagonal group and the inverted diagonal this was implemented through an if in the start of the function , checking if dx and dy had the same signal.
   Other than that , was necessary to implement the color interpolation algorithm asked in the assignment.
