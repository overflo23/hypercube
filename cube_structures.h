byte bottom_up[12][13]={

 { 12, 11, 10,  9,  8,  7,  6,  5,  4,  3,  2,  1,  0}, // 0 bottom frontside left to right (inverted)
 { 13, 14, 15, 16, 17, 18, 19, 20, 21, 22, 23, 24, 25}, // 1 bottom leftside front to back 
 { 26, 27, 28, 29, 30, 31, 32, 33, 34, 35, 36, 37, 38}, // 2 bottom backside left  to right
 { 51, 50, 49, 48, 47, 46, 45, 44, 43, 42, 41, 40, 39}, // 3 bottom rightside front to back (inverted)

 { 52, 53, 54, 55, 56, 57, 58, 59, 60, 61, 62, 63, 64}, // 4 saeule rightside front bottom to top
 {117,118,119,120,121,122,123,124,125,126,127,128,129}, // 5 saeule rightside back bottom to top
 {142,141,140,139,138,137,136,135,134,133,132,131,130}, // 6 saeule leftside back bottom to top (inverted)
 {143,144,145,146,147,148,149,150,151,152,153,154,155}, // 7 saeule leftside front bottom to top 


 { 65, 66, 67, 68, 69, 70 ,71, 72, 73, 74, 75, 76, 77}, // 8 top  rightside front to back 
 { 90, 89, 88, 87, 86, 85, 84, 83, 82, 81, 80, 79, 78}, // 9 top  backside  left to right (inverted)
 {103,102,101,100, 99, 98, 97, 96, 95, 94, 93, 92, 91}, // 10 top  leftside  front to back (inverted) 
 {104,105,106,107,108,109,110,111,112,113,114,115,116}  // 11 top  frontside left to right

};


/*
 byte up_down[12][13]={

 { 12, 11, 10,  9,  8,  7,  6,  5,  4,  3,  2,  1,  0}, // bottom frontside left to right (inverted)
 { 13, 14, 15, 16, 17, 18, 19, 20, 21, 22, 23, 24, 25}, // bottom leftside front to back 
 { 26, 27, 28, 29, 30, 31, 32, 33, 34, 35, 36, 37, 38}, // bottom backside left  to right
 { 51, 50, 49, 48, 47, 46, 45, 44, 43, 42, 41, 40, 39}, // bottom rightside front to back (inverted)

 { 52, 53, 54, 55, 56, 57, 58, 59, 60, 61, 62, 63, 64}, // saeule rightside front bottom to top

 { 65, 66, 67, 68, 69, 70 ,71, 72, 73, 74, 75, 76, 77}, // top  rightside front to back 
 { 90, 89, 88, 87, 86, 85, 84, 83, 82, 81, 80, 79, 78}, // top  backside  left to right (inverted)
 {103,102,101,100, 99, 98, 97, 96, 95, 94, 93, 92, 91},  // top  leftside  front to back (inverted) 
 {104,105,106,107,108,109,110,111,112,113,114,115,116},  // top  frontside left to right

 {117,118,119,120,121,122,123,124,125,126,127,128,129}, // saeule rightside back bottom to top
 {142,141,140,139,138,137,136,135,134,133,132,131,130}, // saeule leftside back bottom to top (inverted)
 {143,144,145,146,147,148,149,150,151,152,153,154,155} // saeule leftside front bottom to top 
};
*/

