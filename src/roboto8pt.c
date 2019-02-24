#include "nrf_font.h"
#include <stdint.h>// 
//  Font data for Roboto 8pt
// 

// Character bitmaps for Roboto 8pt
const uint8_t roboto_8ptBitmaps[] = 
{
	// @0 '!' (1 pixels wide)
	0x00, //  
	0x80, // #
	0x80, // #
	0x80, // #
	0x80, // #
	0x80, // #
	0x80, // #
	0x00, //  
	0x80, // #
	0x00, //  
	0x00, //  
	0x00, //  

	// @12 '"' (2 pixels wide)
	0x00, //   
	0xC0, // ##
	0xC0, // ##
	0xC0, // ##
	0x00, //   
	0x00, //   
	0x00, //   
	0x00, //   
	0x00, //   
	0x00, //   
	0x00, //   
	0x00, //   

	// @24 '#' (6 pixels wide)
	0x00, //       
	0x28, //   # # 
	0x48, //  #  # 
	0xFC, // ######
	0x50, //  # #  
	0x50, //  # #  
	0xF8, // ##### 
	0x50, //  # #  
	0x90, // #  #  
	0x00, //       
	0x00, //       
	0x00, //       

	// @36 '$' (5 pixels wide)
	0x20, //   #  
	0x70, //  ### 
	0x90, // #  # 
	0x88, // #   #
	0xE0, // ###  
	0x30, //   ## 
	0x08, //     #
	0x98, // #  ##
	0xF0, // #### 
	0x20, //   #  
	0x00, //      
	0x00, //      

	// @48 '%' (7 pixels wide)
	0x00, //        
	0xC0, // ##     
	0xA8, // # # #  
	0xB0, // # ##   
	0xD0, // ## #   
	0x2C, //   # ## 
	0x52, //  # #  #
	0x52, //  # #  #
	0x0C, //     ## 
	0x00, //        
	0x00, //        
	0x00, //        

	// @60 '&' (6 pixels wide)
	0x00, //       
	0x70, //  ###  
	0x90, // #  #  
	0x90, // #  #  
	0x60, //  ##   
	0xA8, // # # # 
	0x98, // #  ## 
	0x98, // #  ## 
	0xFC, // ######
	0x00, //       
	0x00, //       
	0x00, //       

	// @72 ''' (1 pixels wide)
	0x00, //  
	0x80, // #
	0x80, // #
	0x00, //  
	0x00, //  
	0x00, //  
	0x00, //  
	0x00, //  
	0x00, //  
	0x00, //  
	0x00, //  
	0x00, //  

	// @84 '(' (3 pixels wide)
	0x40, //  # 
	0x60, //  ##
	0x80, // #  
	0x80, // #  
	0x80, // #  
	0x80, // #  
	0x80, // #  
	0x80, // #  
	0x80, // #  
	0x80, // #  
	0x40, //  # 
	0x20, //   #

	// @96 ')' (3 pixels wide)
	0x80, // #  
	0x40, //  # 
	0x40, //  # 
	0x20, //   #
	0x20, //   #
	0x20, //   #
	0x20, //   #
	0x20, //   #
	0x20, //   #
	0x40, //  # 
	0x40, //  # 
	0x80, // #  

	// @108 '*' (5 pixels wide)
	0x00, //      
	0x20, //   #  
	0xB0, // # ## 
	0x68, //  ## #
	0x50, //  # # 
	0x00, //      
	0x00, //      
	0x00, //      
	0x00, //      
	0x00, //      
	0x00, //      
	0x00, //      

	// @120 '+' (6 pixels wide)
	0x00, //       
	0x00, //       
	0x00, //       
	0x10, //    #  
	0x10, //    #  
	0xFC, // ######
	0x10, //    #  
	0x10, //    #  
	0x00, //       
	0x00, //       
	0x00, //       
	0x00, //       

	// @132 ',' (2 pixels wide)
	0x00, //   
	0x00, //   
	0x00, //   
	0x00, //   
	0x00, //   
	0x00, //   
	0x00, //   
	0x00, //   
	0x40, //  #
	0x40, //  #
	0x80, // # 
	0x00, //   

	// @144 '-' (3 pixels wide)
	0x00, //    
	0x00, //    
	0x00, //    
	0x00, //    
	0x00, //    
	0xE0, // ###
	0x00, //    
	0x00, //    
	0x00, //    
	0x00, //    
	0x00, //    
	0x00, //    

	// @156 '.' (1 pixels wide)
	0x00, //  
	0x00, //  
	0x00, //  
	0x00, //  
	0x00, //  
	0x00, //  
	0x00, //  
	0x00, //  
	0x80, // #
	0x00, //  
	0x00, //  
	0x00, //  

	// @168 '/' (4 pixels wide)
	0x00, //     
	0x10, //    #
	0x10, //    #
	0x20, //   # 
	0x20, //   # 
	0x20, //   # 
	0x40, //  #  
	0x40, //  #  
	0x80, // #   
	0x80, // #   
	0x00, //     
	0x00, //     

	// @180 '0' (5 pixels wide)
	0x00, //      
	0x70, //  ### 
	0x90, // #  # 
	0x88, // #   #
	0x88, // #   #
	0x88, // #   #
	0x90, // #  # 
	0x90, // #  # 
	0x70, //  ### 
	0x00, //      
	0x00, //      
	0x00, //      

	// @192 '1' (3 pixels wide)
	0x00, //    
	0x60, //  ##
	0xA0, // # #
	0x20, //   #
	0x20, //   #
	0x20, //   #
	0x20, //   #
	0x20, //   #
	0x20, //   #
	0x00, //    
	0x00, //    
	0x00, //    

	// @204 '2' (6 pixels wide)
	0x00, //       
	0x78, //  #### 
	0x48, //  #  # 
	0x88, // #   # 
	0x08, //     # 
	0x10, //    #  
	0x20, //   #   
	0x40, //  #    
	0x7C, //  #####
	0x00, //       
	0x00, //       
	0x00, //       

	// @216 '3' (5 pixels wide)
	0x00, //      
	0x78, //  ####
	0x48, //  #  #
	0x08, //     #
	0x30, //   ## 
	0x08, //     #
	0x08, //     #
	0xC8, // ##  #
	0x78, //  ####
	0x00, //      
	0x00, //      
	0x00, //      

	// @228 '4' (6 pixels wide)
	0x00, //       
	0x18, //    ## 
	0x18, //    ## 
	0x28, //   # # 
	0x48, //  #  # 
	0x48, //  #  # 
	0xFC, // ######
	0x08, //     # 
	0x08, //     # 
	0x00, //       
	0x00, //       
	0x00, //       

	// @240 '5' (5 pixels wide)
	0x00, //      
	0xF8, // #####
	0x80, // #    
	0x80, // #    
	0xF0, // #### 
	0x18, //    ##
	0x08, //     #
	0x98, // #  ##
	0x70, //  ### 
	0x00, //      
	0x00, //      
	0x00, //      

	// @252 '6' (5 pixels wide)
	0x00, //      
	0x70, //  ### 
	0xC0, // ##   
	0x80, // #    
	0xF0, // #### 
	0x98, // #  ##
	0x88, // #   #
	0x90, // #  # 
	0x70, //  ### 
	0x00, //      
	0x00, //      
	0x00, //      

	// @264 '7' (6 pixels wide)
	0x00, //       
	0xFC, // ######
	0x08, //     # 
	0x08, //     # 
	0x10, //    #  
	0x10, //    #  
	0x10, //    #  
	0x20, //   #   
	0x60, //  ##   
	0x00, //       
	0x00, //       
	0x00, //       

	// @276 '8' (5 pixels wide)
	0x00, //      
	0xF0, // #### 
	0x90, // #  # 
	0x90, // #  # 
	0x60, //  ##  
	0x90, // #  # 
	0x88, // #   #
	0x90, // #  # 
	0xF0, // #### 
	0x00, //      
	0x00, //      
	0x00, //      

	// @288 '9' (4 pixels wide)
	0x00, //     
	0xE0, // ### 
	0x90, // #  #
	0x90, // #  #
	0x90, // #  #
	0xF0, // ####
	0x10, //    #
	0x10, //    #
	0x60, //  ## 
	0x00, //     
	0x00, //     
	0x00, //     

	// @300 ':' (1 pixels wide)
	0x00, //  
	0x00, //  
	0x00, //  
	0x80, // #
	0x00, //  
	0x00, //  
	0x00, //  
	0x00, //  
	0x80, // #
	0x00, //  
	0x00, //  
	0x00, //  

	// @312 ';' (2 pixels wide)
	0x00, //   
	0x00, //   
	0x00, //   
	0x40, //  #
	0x00, //   
	0x00, //   
	0x00, //   
	0x00, //   
	0x40, //  #
	0x40, //  #
	0x80, // # 
	0x00, //   

	// @324 '<' (5 pixels wide)
	0x00, //      
	0x00, //      
	0x00, //      
	0x08, //     #
	0x30, //   ## 
	0xC0, // ##   
	0x30, //   ## 
	0x08, //     #
	0x00, //      
	0x00, //      
	0x00, //      
	0x00, //      

	// @336 '=' (4 pixels wide)
	0x00, //     
	0x00, //     
	0x00, //     
	0x00, //     
	0xF0, // ####
	0x00, //     
	0xF0, // ####
	0x00, //     
	0x00, //     
	0x00, //     
	0x00, //     
	0x00, //     

	// @348 '>' (4 pixels wide)
	0x00, //     
	0x00, //     
	0x00, //     
	0x80, // #   
	0x60, //  ## 
	0x10, //    #
	0x60, //  ## 
	0x80, // #   
	0x00, //     
	0x00, //     
	0x00, //     
	0x00, //     

	// @360 '?' (5 pixels wide)
	0x00, //      
	0x70, //  ### 
	0xC8, // ##  #
	0x08, //     #
	0x10, //    # 
	0x20, //   #  
	0x20, //   #  
	0x00, //      
	0x20, //   #  
	0x00, //      
	0x00, //      
	0x00, //      

	// @372 '@' (8 pixels wide)
	0x00, //         
	0x3C, //   ####  
	0x42, //  #    # 
	0x9D, // #  ### #
	0xA5, // # #  # #
	0xA5, // # #  # #
	0xA5, // # #  # #
	0xAD, // # # ## #
	0xB6, // # ## ## 
	0x40, //  #      
	0x3C, //   ####  
	0x00, //         

	// @384 'A' (7 pixels wide)
	0x00, //        
	0x10, //    #   
	0x28, //   # #  
	0x28, //   # #  
	0x28, //   # #  
	0x44, //  #   # 
	0x7C, //  ##### 
	0x44, //  #   # 
	0x82, // #     #
	0x00, //        
	0x00, //        
	0x00, //        

	// @396 'B' (5 pixels wide)
	0x00, //      
	0xF0, // #### 
	0x88, // #   #
	0x88, // #   #
	0xF0, // #### 
	0x88, // #   #
	0x88, // #   #
	0x88, // #   #
	0xF0, // #### 
	0x00, //      
	0x00, //      
	0x00, //      

	// @408 'C' (6 pixels wide)
	0x00, //       
	0x78, //  #### 
	0x88, // #   # 
	0x84, // #    #
	0x80, // #     
	0x80, // #     
	0x84, // #    #
	0x88, // #   # 
	0x78, //  #### 
	0x00, //       
	0x00, //       
	0x00, //       

	// @420 'D' (6 pixels wide)
	0x00, //       
	0xF0, // ####  
	0x88, // #   # 
	0x88, // #   # 
	0x84, // #    #
	0x84, // #    #
	0x88, // #   # 
	0x88, // #   # 
	0xF0, // ####  
	0x00, //       
	0x00, //       
	0x00, //       

	// @432 'E' (5 pixels wide)
	0x00, //      
	0xF8, // #####
	0x80, // #    
	0x80, // #    
	0xF0, // #### 
	0x80, // #    
	0x80, // #    
	0x80, // #    
	0xF8, // #####
	0x00, //      
	0x00, //      
	0x00, //      

	// @444 'F' (5 pixels wide)
	0x00, //      
	0xF8, // #####
	0x80, // #    
	0x80, // #    
	0x80, // #    
	0xF0, // #### 
	0x80, // #    
	0x80, // #    
	0x80, // #    
	0x00, //      
	0x00, //      
	0x00, //      

	// @456 'G' (6 pixels wide)
	0x00, //       
	0x78, //  #### 
	0x88, // #   # 
	0x84, // #    #
	0x80, // #     
	0x9C, // #  ###
	0x84, // #    #
	0xC4, // ##   #
	0x78, //  #### 
	0x00, //       
	0x00, //       
	0x00, //       

	// @468 'H' (6 pixels wide)
	0x00, //       
	0x84, // #    #
	0x84, // #    #
	0x84, // #    #
	0xFC, // ######
	0x84, // #    #
	0x84, // #    #
	0x84, // #    #
	0x84, // #    #
	0x00, //       
	0x00, //       
	0x00, //       

	// @480 'I' (1 pixels wide)
	0x00, //  
	0x80, // #
	0x80, // #
	0x80, // #
	0x80, // #
	0x80, // #
	0x80, // #
	0x80, // #
	0x80, // #
	0x00, //  
	0x00, //  
	0x00, //  

	// @492 'J' (5 pixels wide)
	0x00, //      
	0x08, //     #
	0x08, //     #
	0x08, //     #
	0x08, //     #
	0x08, //     #
	0x08, //     #
	0xC8, // ##  #
	0x70, //  ### 
	0x00, //      
	0x00, //      
	0x00, //      

	// @504 'K' (6 pixels wide)
	0x00, //       
	0x8C, // #   ##
	0x90, // #  #  
	0xA0, // # #   
	0xE0, // ###   
	0xE0, // ###   
	0x90, // #  #  
	0x88, // #   # 
	0x8C, // #   ##
	0x00, //       
	0x00, //       
	0x00, //       

	// @516 'L' (5 pixels wide)
	0x00, //      
	0x80, // #    
	0x80, // #    
	0x80, // #    
	0x80, // #    
	0x80, // #    
	0x80, // #    
	0x80, // #    
	0xF8, // #####
	0x00, //      
	0x00, //      
	0x00, //      

	// @528 'M' (8 pixels wide)
	0x00, //         
	0x83, // #     ##
	0xC3, // ##    ##
	0xC5, // ##   # #
	0xA5, // # #  # #
	0xA5, // # #  # #
	0xA9, // # # #  #
	0x99, // #  ##  #
	0x91, // #  #   #
	0x00, //         
	0x00, //         
	0x00, //         

	// @540 'N' (6 pixels wide)
	0x00, //       
	0x84, // #    #
	0xC4, // ##   #
	0xE4, // ###  #
	0xA4, // # #  #
	0x94, // #  # #
	0x9C, // #  ###
	0x8C, // #   ##
	0x84, // #    #
	0x00, //       
	0x00, //       
	0x00, //       

	// @552 'O' (6 pixels wide)
	0x00, //       
	0x78, //  #### 
	0x88, // #   # 
	0x84, // #    #
	0x84, // #    #
	0x84, // #    #
	0x84, // #    #
	0x88, // #   # 
	0x78, //  #### 
	0x00, //       
	0x00, //       
	0x00, //       

	// @564 'P' (6 pixels wide)
	0x00, //       
	0xF8, // ##### 
	0x88, // #   # 
	0x84, // #    #
	0x88, // #   # 
	0xF8, // ##### 
	0x80, // #     
	0x80, // #     
	0x80, // #     
	0x00, //       
	0x00, //       
	0x00, //       

	// @576 'Q' (6 pixels wide)
	0x00, //       
	0x78, //  #### 
	0xCC, // ##  ##
	0x84, // #    #
	0x84, // #    #
	0x84, // #    #
	0x84, // #    #
	0xCC, // ##  ##
	0x78, //  #### 
	0x04, //      #
	0x00, //       
	0x00, //       

	// @588 'R' (6 pixels wide)
	0x00, //       
	0xF0, // ####  
	0x88, // #   # 
	0x88, // #   # 
	0x88, // #   # 
	0xF0, // ####  
	0x90, // #  #  
	0x88, // #   # 
	0x8C, // #   ##
	0x00, //       
	0x00, //       
	0x00, //       

	// @600 'S' (5 pixels wide)
	0x00, //      
	0x70, //  ### 
	0x88, // #   #
	0x80, // #    
	0x60, //  ##  
	0x18, //    ##
	0x08, //     #
	0x88, // #   #
	0x70, //  ### 
	0x00, //      
	0x00, //      
	0x00, //      

	// @612 'T' (6 pixels wide)
	0x00, //       
	0xFC, // ######
	0x10, //    #  
	0x10, //    #  
	0x10, //    #  
	0x10, //    #  
	0x10, //    #  
	0x10, //    #  
	0x10, //    #  
	0x00, //       
	0x00, //       
	0x00, //       

	// @624 'U' (5 pixels wide)
	0x00, //      
	0x88, // #   #
	0x88, // #   #
	0x88, // #   #
	0x88, // #   #
	0x88, // #   #
	0x88, // #   #
	0x88, // #   #
	0x70, //  ### 
	0x00, //      
	0x00, //      
	0x00, //      

	// @636 'V' (7 pixels wide)
	0x00, //        
	0x82, // #     #
	0x44, //  #   # 
	0x44, //  #   # 
	0x44, //  #   # 
	0x28, //   # #  
	0x28, //   # #  
	0x30, //   ##   
	0x10, //    #   
	0x00, //        
	0x00, //        
	0x00, //        

	// @648 'W' (10 pixels wide)
	0x00, 0x00, //           
	0x8C, 0xC0, // #   ##  ##
	0x4C, 0x80, //  #  ##  # 
	0x4C, 0x80, //  #  ##  # 
	0x54, 0x80, //  # # #  # 
	0x53, 0x00, //  # #  ##  
	0x33, 0x00, //   ##  ##  
	0x33, 0x00, //   ##  ##  
	0x21, 0x00, //   #    #  
	0x00, 0x00, //           
	0x00, 0x00, //           
	0x00, 0x00, //           

	// @672 'X' (7 pixels wide)
	0x00, //        
	0xC6, // ##   ##
	0x4C, //  #  ## 
	0x28, //   # #  
	0x10, //    #   
	0x10, //    #   
	0x28, //   # #  
	0x4C, //  #  ## 
	0xC6, // ##   ##
	0x00, //        
	0x00, //        
	0x00, //        

	// @684 'Y' (7 pixels wide)
	0x00, //        
	0xC6, // ##   ##
	0x44, //  #   # 
	0x68, //  ## #  
	0x28, //   # #  
	0x10, //    #   
	0x10, //    #   
	0x10, //    #   
	0x10, //    #   
	0x00, //        
	0x00, //        
	0x00, //        

	// @696 'Z' (6 pixels wide)
	0x00, //       
	0x7C, //  #####
	0x0C, //     ##
	0x08, //     # 
	0x10, //    #  
	0x20, //   #   
	0x20, //   #   
	0x40, //  #    
	0xFC, // ######
	0x00, //       
	0x00, //       
	0x00, //       

	// @708 '[' (2 pixels wide)
	0xC0, // ##
	0x80, // # 
	0x80, // # 
	0x80, // # 
	0x80, // # 
	0x80, // # 
	0x80, // # 
	0x80, // # 
	0x80, // # 
	0x80, // # 
	0xC0, // ##
	0x00, //   

	// @720 '\' (4 pixels wide)
	0x00, //     
	0x80, // #   
	0x40, //  #  
	0x40, //  #  
	0x40, //  #  
	0x20, //   # 
	0x20, //   # 
	0x10, //    #
	0x10, //    #
	0x10, //    #
	0x00, //     
	0x00, //     

	// @732 ']' (2 pixels wide)
	0xC0, // ##
	0x40, //  #
	0x40, //  #
	0x40, //  #
	0x40, //  #
	0x40, //  #
	0x40, //  #
	0x40, //  #
	0x40, //  #
	0x40, //  #
	0xC0, // ##
	0x00, //   

	// @744 '^' (3 pixels wide)
	0x00, //    
	0x40, //  # 
	0xC0, // ## 
	0xA0, // # #
	0xA0, // # #
	0x00, //    
	0x00, //    
	0x00, //    
	0x00, //    
	0x00, //    
	0x00, //    
	0x00, //    

	// @756 '_' (5 pixels wide)
	0x00, //      
	0x00, //      
	0x00, //      
	0x00, //      
	0x00, //      
	0x00, //      
	0x00, //      
	0x00, //      
	0x00, //      
	0xF8, // #####
	0x00, //      
	0x00, //      

	// @768 '`' (3 pixels wide)
	0xC0, // ## 
	0x60, //  ##
	0x00, //    
	0x00, //    
	0x00, //    
	0x00, //    
	0x00, //    
	0x00, //    
	0x00, //    
	0x00, //    
	0x00, //    
	0x00, //    

	// @780 'a' (4 pixels wide)
	0x00, //     
	0x00, //     
	0x00, //     
	0xF0, // ####
	0x10, //    #
	0xF0, // ####
	0x90, // #  #
	0x90, // #  #
	0xF0, // ####
	0x00, //     
	0x00, //     
	0x00, //     

	// @792 'b' (5 pixels wide)
	0x00, //      
	0x80, // #    
	0x80, // #    
	0xF0, // #### 
	0x90, // #  # 
	0x88, // #   #
	0x88, // #   #
	0x90, // #  # 
	0xF0, // #### 
	0x00, //      
	0x00, //      
	0x00, //      

	// @804 'c' (5 pixels wide)
	0x00, //      
	0x00, //      
	0x00, //      
	0x70, //  ### 
	0x90, // #  # 
	0x88, // #   #
	0x80, // #    
	0x98, // #  ##
	0x70, //  ### 
	0x00, //      
	0x00, //      
	0x00, //      

	// @816 'd' (5 pixels wide)
	0x00, //      
	0x08, //     #
	0x08, //     #
	0x78, //  ####
	0x48, //  #  #
	0x88, // #   #
	0x88, // #   #
	0x48, //  #  #
	0x78, //  ####
	0x00, //      
	0x00, //      
	0x00, //      

	// @828 'e' (5 pixels wide)
	0x00, //      
	0x00, //      
	0x00, //      
	0x70, //  ### 
	0x90, // #  # 
	0xF8, // #####
	0x80, // #    
	0x90, // #  # 
	0x70, //  ### 
	0x00, //      
	0x00, //      
	0x00, //      

	// @840 'f' (4 pixels wide)
	0x30, //   ##
	0x40, //  #  
	0x40, //  #  
	0xF0, // ####
	0x40, //  #  
	0x40, //  #  
	0x40, //  #  
	0x40, //  #  
	0x40, //  #  
	0x00, //     
	0x00, //     
	0x00, //     

	// @852 'g' (5 pixels wide)
	0x00, //      
	0x00, //      
	0x00, //      
	0x78, //  ####
	0x48, //  #  #
	0x88, // #   #
	0x88, // #   #
	0x48, //  #  #
	0x78, //  ####
	0x08, //     #
	0x78, //  ####
	0x00, //      

	// @864 'h' (4 pixels wide)
	0x00, //     
	0x80, // #   
	0x80, // #   
	0xF0, // ####
	0x90, // #  #
	0x90, // #  #
	0x90, // #  #
	0x90, // #  #
	0x90, // #  #
	0x00, //     
	0x00, //     
	0x00, //     

	// @876 'i' (1 pixels wide)
	0x00, //  
	0x80, // #
	0x00, //  
	0x80, // #
	0x80, // #
	0x80, // #
	0x80, // #
	0x80, // #
	0x80, // #
	0x00, //  
	0x00, //  
	0x00, //  

	// @888 'j' (2 pixels wide)
	0x00, //   
	0x40, //  #
	0x00, //   
	0x40, //  #
	0x40, //  #
	0x40, //  #
	0x40, //  #
	0x40, //  #
	0x40, //  #
	0x40, //  #
	0xC0, // ##
	0x00, //   

	// @900 'k' (5 pixels wide)
	0x80, // #    
	0x80, // #    
	0x80, // #    
	0x90, // #  # 
	0xA0, // # #  
	0xC0, // ##   
	0xA0, // # #  
	0xA0, // # #  
	0x98, // #  ##
	0x00, //      
	0x00, //      
	0x00, //      

	// @912 'l' (1 pixels wide)
	0x80, // #
	0x80, // #
	0x80, // #
	0x80, // #
	0x80, // #
	0x80, // #
	0x80, // #
	0x80, // #
	0x80, // #
	0x00, //  
	0x00, //  
	0x00, //  

	// @924 'm' (8 pixels wide)
	0x00, //         
	0x00, //         
	0x00, //         
	0xF7, // #### ###
	0x99, // #  ##  #
	0x91, // #  #   #
	0x91, // #  #   #
	0x91, // #  #   #
	0x91, // #  #   #
	0x00, //         
	0x00, //         
	0x00, //         

	// @936 'n' (4 pixels wide)
	0x00, //     
	0x00, //     
	0x00, //     
	0xF0, // ####
	0x90, // #  #
	0x90, // #  #
	0x90, // #  #
	0x90, // #  #
	0x90, // #  #
	0x00, //     
	0x00, //     
	0x00, //     

	// @948 'o' (6 pixels wide)
	0x00, //       
	0x00, //       
	0x00, //       
	0x78, //  #### 
	0x48, //  #  # 
	0x84, // #    #
	0x84, // #    #
	0x48, //  #  # 
	0x78, //  #### 
	0x00, //       
	0x00, //       
	0x00, //       

	// @960 'p' (5 pixels wide)
	0x00, //      
	0x00, //      
	0x00, //      
	0xF0, // #### 
	0x90, // #  # 
	0x88, // #   #
	0x88, // #   #
	0x90, // #  # 
	0xF0, // #### 
	0x80, // #    
	0x80, // #    
	0x00, //      

	// @972 'q' (5 pixels wide)
	0x00, //      
	0x00, //      
	0x00, //      
	0x78, //  ####
	0x48, //  #  #
	0x88, // #   #
	0x88, // #   #
	0x48, //  #  #
	0x78, //  ####
	0x08, //     #
	0x08, //     #
	0x00, //      

	// @984 'r' (3 pixels wide)
	0x00, //    
	0x00, //    
	0x00, //    
	0xE0, // ###
	0x80, // #  
	0x80, // #  
	0x80, // #  
	0x80, // #  
	0x80, // #  
	0x00, //    
	0x00, //    
	0x00, //    

	// @996 's' (4 pixels wide)
	0x00, //     
	0x00, //     
	0x00, //     
	0xF0, // ####
	0x90, // #  #
	0xE0, // ### 
	0x10, //    #
	0x90, // #  #
	0xF0, // ####
	0x00, //     
	0x00, //     
	0x00, //     

	// @1008 't' (3 pixels wide)
	0x00, //    
	0x00, //    
	0x40, //  # 
	0xE0, // ###
	0x40, //  # 
	0x40, //  # 
	0x40, //  # 
	0x40, //  # 
	0x20, //   #
	0x00, //    
	0x00, //    
	0x00, //    

	// @1020 'u' (4 pixels wide)
	0x00, //     
	0x00, //     
	0x00, //     
	0x90, // #  #
	0x90, // #  #
	0x90, // #  #
	0x90, // #  #
	0x90, // #  #
	0xF0, // ####
	0x00, //     
	0x00, //     
	0x00, //     

	// @1032 'v' (5 pixels wide)
	0x00, //      
	0x00, //      
	0x00, //      
	0x88, // #   #
	0x90, // #  # 
	0x50, //  # # 
	0x50, //  # # 
	0x60, //  ##  
	0x20, //   #  
	0x00, //      
	0x00, //      
	0x00, //      

	// @1044 'w' (8 pixels wide)
	0x00, //         
	0x00, //         
	0x00, //         
	0x99, // #  ##  #
	0x9A, // #  ## # 
	0x5A, //  # ## # 
	0x6A, //  ## # # 
	0x66, //  ##  ## 
	0x24, //   #  #  
	0x00, //         
	0x00, //         
	0x00, //         

	// @1056 'x' (5 pixels wide)
	0x00, //      
	0x00, //      
	0x00, //      
	0xC8, // ##  #
	0x50, //  # # 
	0x30, //   ## 
	0x30, //   ## 
	0x50, //  # # 
	0xC8, // ##  #
	0x00, //      
	0x00, //      
	0x00, //      

	// @1068 'y' (5 pixels wide)
	0x00, //      
	0x00, //      
	0x00, //      
	0x88, // #   #
	0x50, //  # # 
	0x50, //  # # 
	0x50, //  # # 
	0x20, //   #  
	0x20, //   #  
	0x20, //   #  
	0xC0, // ##   
	0x00, //      

	// @1080 'z' (5 pixels wide)
	0x00, //      
	0x00, //      
	0x00, //      
	0x78, //  ####
	0x10, //    # 
	0x30, //   ## 
	0x20, //   #  
	0x40, //  #   
	0xF8, // #####
	0x00, //      
	0x00, //      
	0x00, //      

	// @1092 '{' (4 pixels wide)
	0x30, //   ##
	0x20, //   # 
	0x20, //   # 
	0x20, //   # 
	0x40, //  #  
	0xC0, // ##  
	0x40, //  #  
	0x20, //   # 
	0x20, //   # 
	0x20, //   # 
	0x30, //   ##
	0x00, //     

	// @1104 '|' (1 pixels wide)
	0x00, //  
	0x80, // #
	0x80, // #
	0x80, // #
	0x80, // #
	0x80, // #
	0x80, // #
	0x80, // #
	0x80, // #
	0x80, // #
	0x00, //  
	0x00, //  

	// @1116 '}' (4 pixels wide)
	0xC0, // ##  
	0x40, //  #  
	0x40, //  #  
	0x40, //  #  
	0x60, //  ## 
	0x30, //   ##
	0x60, //  ## 
	0x40, //  #  
	0x40, //  #  
	0x40, //  #  
	0x80, // #   
	0x00, //     

	// @1128 '~' (7 pixels wide)
	0x00, //        
	0x00, //        
	0x00, //        
	0x00, //        
	0x00, //        
	0x72, //  ###  #
	0x9C, // #  ### 
	0x00, //        
	0x00, //        
	0x00, //        
	0x00, //        
	0x00, //        
};

// Character descriptors for Roboto 8pt
// { [Char width in bits], [Offset into roboto_8ptCharBitmaps in bytes] }
const FONT_CHAR_INFO roboto_8ptDescriptors[] = 
{
	{1, 0}, 		// ! 
	{2, 12}, 		// " 
	{6, 24}, 		// # 
	{5, 36}, 		// $ 
	{7, 48}, 		// % 
	{6, 60}, 		// & 
	{1, 72}, 		// ' 
	{3, 84}, 		// ( 
	{3, 96}, 		// ) 
	{5, 108}, 		// * 
	{6, 120}, 		// + 
	{2, 132}, 		// , 
	{3, 144}, 		// - 
	{1, 156}, 		// . 
	{4, 168}, 		// / 
	{5, 180}, 		// 0 
	{3, 192}, 		// 1 
	{6, 204}, 		// 2 
	{5, 216}, 		// 3 
	{6, 228}, 		// 4 
	{5, 240}, 		// 5 
	{5, 252}, 		// 6 
	{6, 264}, 		// 7 
	{5, 276}, 		// 8 
	{4, 288}, 		// 9 
	{1, 300}, 		// : 
	{2, 312}, 		// ; 
	{5, 324}, 		// < 
	{4, 336}, 		// = 
	{4, 348}, 		// > 
	{5, 360}, 		// ? 
	{8, 372}, 		// @ 
	{7, 384}, 		// A 
	{5, 396}, 		// B 
	{6, 408}, 		// C 
	{6, 420}, 		// D 
	{5, 432}, 		// E 
	{5, 444}, 		// F 
	{6, 456}, 		// G 
	{6, 468}, 		// H 
	{1, 480}, 		// I 
	{5, 492}, 		// J 
	{6, 504}, 		// K 
	{5, 516}, 		// L 
	{8, 528}, 		// M 
	{6, 540}, 		// N 
	{6, 552}, 		// O 
	{6, 564}, 		// P 
	{6, 576}, 		// Q 
	{6, 588}, 		// R 
	{5, 600}, 		// S 
	{6, 612}, 		// T 
	{5, 624}, 		// U 
	{7, 636}, 		// V 
	{10, 648}, 		// W 
	{7, 672}, 		// X 
	{7, 684}, 		// Y 
	{6, 696}, 		// Z 
	{2, 708}, 		// [ 
	{4, 720}, 		// \ 
	{2, 732}, 		// ] 
	{3, 744}, 		// ^ 
	{5, 756}, 		// _ 
	{3, 768}, 		// ` 
	{4, 780}, 		// a 
	{5, 792}, 		// b 
	{5, 804}, 		// c 
	{5, 816}, 		// d 
	{5, 828}, 		// e 
	{4, 840}, 		// f 
	{5, 852}, 		// g 
	{4, 864}, 		// h 
	{1, 876}, 		// i 
	{2, 888}, 		// j 
	{5, 900}, 		// k 
	{1, 912}, 		// l 
	{8, 924}, 		// m 
	{4, 936}, 		// n 
	{6, 948}, 		// o 
	{5, 960}, 		// p 
	{5, 972}, 		// q 
	{3, 984}, 		// r 
	{4, 996}, 		// s 
	{3, 1008}, 		// t 
	{4, 1020}, 		// u 
	{5, 1032}, 		// v 
	{8, 1044}, 		// w 
	{5, 1056}, 		// x 
	{5, 1068}, 		// y 
	{5, 1080}, 		// z 
	{4, 1092}, 		// { 
	{1, 1104}, 		// | 
	{4, 1116}, 		// } 
	{7, 1128}, 		// ~ 
};

// Font information for Roboto 8pt
const FONT_INFO roboto_8ptFontInfo =
{
	12, //  Character height
	'!', //  Start character
	'~', //  End character
	1, //  Width, in pixels, of space character
	roboto_8ptDescriptors, //  Character descriptor array
	roboto_8ptBitmaps, //  Character bitmap array
};

