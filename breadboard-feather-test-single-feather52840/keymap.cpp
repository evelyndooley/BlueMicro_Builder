/*
Copyright 2018 <Pierre Constantineau>

3-Clause BSD License

Redistribution and use in source and binary forms, with or without modification, are permitted provided that the following conditions are met:

1. Redistributions of source code must retain the above copyright notice, this list of conditions and the following disclaimer.

2. Redistributions in binary form must reproduce the above copyright notice, this list of conditions and the following disclaimer in the documentation and/or other materials provided with the distribution.

3. Neither the name of the copyright holder nor the names of its contributors may be used to endorse or promote products derived from this software without specific prior written permission.
THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT
LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
(INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.

*/
#include "keymap.h"



// Initialize matrix with nothing...
YMAP2ARRAY(KEYMAP(
     std::array<std::array<Key, MATRIX_COLS>, MATRIX_ROWS> matrix =
    KE   KC_NO,    KC_NO,    KC_NO,    KC_NO,        
        KC_NO,    KC_NO,    KC_NO,    KC_NO,   
        KC_NO,    KC_NO,    KC_NO,    KC_NO,     
        KC_NO,    KC_NO,    KC_NO,    KC_NO,   
        KC_NO,    KC_NO,    KC_NO,    KC_NO 
    ));

void updateDisplay(PersistentState* cfg, DynamicState* stat)
{
    #ifdef BLUEMICRO_CONFIGURED_DISPLAY
    u8g2.setFontMode(1);    // Transparent
    u8g2.setFontDirection(0);
    battery(22,19,stat->vbat_per);
    printline(0,28,stat->peer_name_prph);

    char buffer [50];
    u8g2.setFont(u8g2_font_helvB12_tf); // choose a suitable font
    switch(stat->layer)
    {
        case _L0:     u8g2.drawStr(0,128,""); break;
        case _L1:      u8g2.drawStr(0,128,"L1");break;
        case _L2:     u8g2.drawStr(0,128,"L2");break;
        // case _ADJUST:     u8g2.drawStr(0,128,"A");break;
        // case _EXTRAL:     u8g2.drawStr(0,128,"EL");break;
        // case _EXTRAR:     u8g2.drawStr(0,128,"ER");break; 
        // case _MACROL:     u8g2.drawStr(0,128,"ML");break;
        // case _MACROR:     u8g2.drawStr(0,128,"MR");break; 
        // case _MACRO:     u8g2.drawStr(0,128,"M");break;    
    }
    #endif
}

void setupKeymap() {
    #ifdef BLUEMICRO_CONFIGURED_DISPLAY
    OLED.setStatusDisplayCallback(updateDisplay);
    #endif

    /* Numpad
    * ,------------------------------------------------.
    * | Esc  |   Q  |   W  |   E  |   R  |   T  |   Y* | 
    * |------+------+------+------+------+-------------|
    * | Tab  |   A  |   S  |   D  |   F  |   G  |   H* |
    * |------+------+------+------+------+------|------|
    * | Shift|   Z  |   X  |   C  |   V  |   B  |Space |
    * |------+------+------+------+------+------+------'
    * | Ctrl | GUI  | Alt  | L(3) | L(1) |Space |
    * `-----------------------------------------'
    */

    uint32_t layer0_single[MATRIX_ROWS][MATRIX_COLS] =
        KEYMAP(
            LAYER_1,  KC_KP_SLASH,    KC_KP_ASTERISK,    KC_KP_MINUS,     
            KC_KP_7,  KC_KP_8,    KC_KP_9,    KC_KP_PLUS,   
            KC_KP_4, KC_KP_5,    KC_KP_6,    KC_NO,    
            KC_KP_1, KC_KP_2,    KC_KP_3,    KC_NO,    
            LAYER_2, KC_KP_0, KC_KP_DOT, KC_KP_ENTER
        );

    /* Layer 1 (Raise) Numpad
    * ,------------------------------------------------.
    * |  `   |   1  |   2  |   3  |   4  |   5  |   -  | 
    * |------+------+------+------+------+-------------|
    * | Del  |  F1  | F2   |  F3  | F4   |  F5  |  [   |
    * |------+------+------+------+------+------|------|
    * | Shift|  F7  | F8   |  F9  |  F10 | F11  |Space |
    * |------+------+------+------+------+------+------'
    * | Ctrl | GUI  | Alt  | L(3) | L(1) |Space |
    * `-----------------------------------------'
    */
    uint32_t layer1_single[MATRIX_ROWS][MATRIX_COLS] =
        KEYMAP( 
            LAYER_1,  KC_KP_SLASH,    KC_KP_ASTERISK,    KC_KP_MINUS,     
            KC_KP_7,  KC_KP_8,    KC_KP_9,    KC_KP_PLUS,   
            KC_KP_4, KC_KP_5,    KC_KP_6,    KC_NO,    
            KC_KP_1, KC_KP_2,    KC_KP_3,    KC_NO,    
            LAYER_2, KC_KP_0, KC_KP_DOT, KC_KP_ENTER
        );

    /* Layer 2 (Raise) Numpad
    * ,------------------------------------------------.
    * |  `   |   1  |   2  |   3  |   4  |   5  |   -  | 
    * |------+------+------+------+------+-------------|
    * | Del  |  F1  | F2   |  F3  | F4   |  F5  |  [   |
    * |------+------+------+------+------+------|------|
    * | Shift|  F7  | F8   |  F9  |  F10 | F11  |Space |
    * |------+------+------+------+------+------+------'
    * | Ctrl | GUI  | Alt  | L(3) | L(1) |Space |
    * `-----------------------------------------'
    */
    uint32_t layer2_single[MATRIX_ROWS][MATRIX_COLS] =
        KEYMAP( 
            KC_NLCK,  KC_KP_SLASH,    KC_KP_ASTERISK,    KC_KP_MINUS,     
            KC_KP_7,  KC_KP_8,    KC_KP_9,    KC_KP_PLUS,   
            KC_KP_4, KC_KP_5,    KC_KP_6,    KC_NO,    
            KC_KP_1, KC_KP_2,    KC_KP_3,    KC_NO,    
            LAYER_2, KC_KP_0, KC_KP_DOT, KC_KP_ENTER
        );


    for (int row = 0; row < MATRIX_ROWS; ++row)
    {
        for (int col = 0; col < MATRIX_COLS; ++col)
        {
            #if KEYBOARD_SIDE == SINGLE
                matrix[row][col].addActivation(_L0, Method::PRESS, layer0_single[row][col]);
                matrix[row][col].addActivation(_L1, Method::PRESS, layer1_single[row][col]);
                matrix[row][col].addActivation(_L2, Method::MT_HOLD, layer2_single[row][col]);
                
            #endif
            // if you want to add Tap/Hold or Tap/Doubletap activations, then you add them below.

        }
    }
}


