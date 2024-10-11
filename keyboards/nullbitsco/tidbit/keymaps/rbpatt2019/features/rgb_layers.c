const rgblight_segment_t PROGMEM volume[] = RGBLIGHT_LAYER_SEGMENTS( { 0, 8, HSV_BLUE } );
const rgblight_segment_t PROGMEM app_layer[] = RGBLIGHT_LAYER_SEGMENTS( { 4, 4, HSV_GREEN } );
const rgblight_segment_t PROGMEM brightness[] = RGBLIGHT_LAYER_SEGMENTS( { 0, 4, HSV_CYAN } );
const rgblight_segment_t PROGMEM chrome_layer[] = RGBLIGHT_LAYER_SEGMENTS( { 4, 4, HSV_MAGENTA } );
const rgblight_segment_t* const PROGMEM my_rgb_layers[] = RGBLIGHT_LAYERS_LIST(
    volume,
    app_layer,
    brightness,
    chrome_layer
);

void keyboard_post_init_user(void) {
    rgblight_layers = my_rgb_layers;
}

layer_state_t default_layer_state_set_user(layer_state_t state) {
    rgblight_set_layer_state(0, layer_state_cmp(state, 0));  //vol
    return state;
}

layer_state_t layer_state_set_user(layer_state_t state) {
    rgblight_set_layer_state(1, layer_state_cmp(state, 1));  //apps
    rgblight_set_layer_state(2, layer_state_cmp(state, 2));  //bright
    rgblight_set_layer_state(3, layer_state_cmp(state, 3));  //chrome
    return state;
}
